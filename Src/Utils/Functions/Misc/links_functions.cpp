#include "links_functions.h"
#include "../../../Menu/Base/Submenus/Main/Misc/links.h" 
#include "../../Saving/States/Misc/links_default_states.h" 

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
                    UIUtil::PrintSubtitle("Discord Link Copied To Your Clipboard.");
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

void Misc_GithubLinkFunction() {
    static bool linkCopied = false;
    if (!linkCopied) {
        const std::string discordLink = "https://github.com/Kapiushon86/RageMenuRDR2";
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
                    UIUtil::PrintSubtitle("Github Link Copied To Your Clipboard.");
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

void Misc_NexusLinkFunction() {
    static bool linkCopied = false;
    if (!linkCopied) {
        const std::string discordLink = "https://www.nexusmods.com/reddeadredemption2/mods/5244/?tab=description";
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
                    UIUtil::PrintSubtitle("Nexus Link Copied To Your Clipboard.");
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