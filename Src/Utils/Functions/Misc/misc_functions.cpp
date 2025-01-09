#include "misc_functions.h"
#include <Windows.h>
#include <string>
#include <thread>
#include <iostream>
#include <mutex>
#include <Shlwapi.h>
#include <filesystem>
#include <mmsystem.h>
#include <ctime>
#include <map>
#include "../../../Menu/Base/Submenus/Main/Misc/misc.h"
#include "../../Saving/States/Misc/misc_default_states.h"
#include "../../../ThirdParty/discord-rpc/win64-static/include/discord_rpc.h"

#pragma comment(lib, "Shlwapi.lib")

std::mutex printMutex;
std::atomic<bool> altF4Running(false);
static bool gameTerminated = false;
static bool greetingDisplayed = false;

void SafePrint(const std::string& message)
{
    std::lock_guard<std::mutex> lock(printMutex);
    UIUtil::PrintSubtitle(message);
}

void TerminateGame()
{
    if (gameTerminated) return;

    HWND hwnd = FindWindowA(nullptr, "Red Dead Redemption 2");
    if (hwnd)
    {
        DWORD processId;
        GetWindowThreadProcessId(hwnd, &processId);
        HANDLE processHandle = OpenProcess(PROCESS_TERMINATE, FALSE, processId);
        if (processHandle)
        {
            if (TerminateProcess(processHandle, 0))
            {
                SafePrint("Game terminated successfully.");
                gameTerminated = true;
            }
            else
            {
                SafePrint("Failed to terminate the game process.");
            }
            CloseHandle(processHandle);
        }
        else
        {
            SafePrint("Failed to open game process.");
        }
    }
    else
    {
        SafePrint("Game window not found.");
    }
}

void Misc_SeasonalGreetingsFunction() {
    if (greetingDisplayed || !misc_seasonal_greetings_bool) return;

    static const std::map<std::pair<int, int>, std::string> greetings = {
        {{10, 31}, "Happy Halloween!\nGet ready for a spook-tacular time filled with tricks and treats!\nStay safe and enjoy the festivities!"},
        {{12, 25}, "Merry Christmas!\nMay your holiday season be filled with love, joy, and the magic of Christmas.\nEnjoy the time with loved ones!"},
        {{4, 20}, "Happy Easter!\nA time for renewal and hope.\nMay your day be filled with springtime joy, Easter eggs, and new beginnings!"}
    };

    std::time_t now = std::time(0);
    std::tm localTime;
    localtime_s(&localTime, &now);

    int month = localTime.tm_mon + 1; // Months are 0-indexed
    int day = localTime.tm_mday;
    int weekday = localTime.tm_wday; // Sunday = 0, Monday = 1, ..., Saturday = 6

    // Check for Thanksgiving (4th Thursday of November)
    if (month == 11 && day >= 22 && day <= 28 && weekday == 4) {
        UIUtil::PrintSubtitle("Happy Thanksgiving!\nA time to reflect on what we're thankful for.\nWishing you a warm and joyful day with family and friends!");
        greetingDisplayed = true;
        return;
    }

    auto it = greetings.find({ month, day });
    if (it != greetings.end()) {
        UIUtil::PrintSubtitle(it->second.c_str());
        greetingDisplayed = true;
    }
}

void Misc_RealAltF4Function() {
    if (misc_real_alt_f4_bool && !altF4Running.load()) {
        altF4Running.store(true);
        std::thread([] {
            while (misc_real_alt_f4_bool) {
                if (GetAsyncKeyState(VK_LMENU) & 0x8000 && GetAsyncKeyState(VK_F4) & 0x8000) {
                    TerminateGame();
                    break;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            altF4Running.store(false);
            }).detach();
    }
}

void Misc_AltF4Function() {
    TerminateGame();
}

static bool discordInitialized = false;

void Misc_DiscordPresenceFunction() {
    if (misc_discord_presence_bool) {
        if (!discordInitialized) {
            Discord_Initialize("1310430706618597376", nullptr, true, nullptr);
            discordInitialized = true;
        }

        DiscordRichPresence discordPresence;
        memset(&discordPresence, 0, sizeof(discordPresence));

        time_t now = time(nullptr);
        discordPresence.startTimestamp = now;
        discordPresence.state = "Inside Rockstar's Advanced Game Engine Menu";

        Discord_UpdatePresence(&discordPresence);
    }
    else {
        if (discordInitialized) {
            Discord_ClearPresence();
            Discord_Shutdown();
            discordInitialized = false;
        }
    }
}




void Misc_RevealMapFunction() {
    MAP::SET_MINIMAP_HIDE_FOW(TRUE);
}

void Misc_UnrevealMapFunction() {
    MAP::SET_MINIMAP_HIDE_FOW(FALSE);
}

void Misc_DiscordLinkFunction() {
    static bool linkCopied = false;
    if (!linkCopied) {
        const std::string discordLink = "https://discord.gg/FMcy3Sxq6T";
        if (OpenClipboard(nullptr)) {
            EmptyClipboard();
            size_t linkSize = discordLink.size() + 1;
            std::vector<char> buffer(linkSize);
            std::memcpy(buffer.data(), discordLink.c_str(), linkSize);

            HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, linkSize);
            if (hGlobal) {
                LPVOID pGlobal = GlobalLock(hGlobal);
                if (pGlobal) {
                    std::memcpy(pGlobal, buffer.data(), linkSize);
                    GlobalUnlock(pGlobal);
                    SetClipboardData(CF_TEXT, hGlobal);
                    UIUtil::PrintSubtitle("Discord link copied to your clipboard.");
                    linkCopied = true;
                }
                else {
                    UIUtil::PrintSubtitle("Failed to lock global memory.");
                }
                GlobalFree(hGlobal);
            }
            else {
                UIUtil::PrintSubtitle("Failed to allocate global memory.");
            }
            CloseClipboard();
        }
        else {
            UIUtil::PrintSubtitle("Failed to open clipboard.");
        }
    }
}

void Misc_BypassStartupIntrosFunction() {

}

void Misc_SkipCutsceneFunction() {

}
