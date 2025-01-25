#include "wav_player_functions.h"
#include "../../../Menu/Base/Submenus/Main/Misc/wav_player.h" 
#include "../../Saving/States/Misc/wav_player_default_states.h" 
#include <Windows.h>
#include <string>
#include <thread>
#include <iostream>
#include <mmsystem.h>
#include <mutex> 
#include <Shlwapi.h>
#include <filesystem>
#include <fstream>
#include <future>

// Plan to redo all this, use a third party library so i dont have to rely on default os. Cant change volume without changing windows volume etc.

namespace fs = std::filesystem;

const std::string WAV_PLAYER_FOLDER = "WavPlayer";

std::mutex playMutex;

std::string currentWavFile = "";
std::atomic<bool> wavplayer_paused = false;
DWORD previousPlayTime = 0;

std::vector<std::string> wavFiles;

std::string GetRootFolderPathFromMisc() {
    Config config;
    return config.GetRootFolderPath();
}

std::vector<std::string> GetWavFilesInWavPlayerFolder() {
    std::string wavPlayerFolder = GetRootFolderPathFromMisc() + "\\" + WAV_PLAYER_FOLDER;

    if (!fs::exists(wavPlayerFolder) || !fs::is_directory(wavPlayerFolder)) {
        return wavFiles;
    }

    wavFiles.clear();

    for (const auto& entry : fs::directory_iterator(wavPlayerFolder)) {
        if (entry.is_regular_file() && entry.path().extension() == ".wav") {
            std::ifstream file(entry.path().string());
            if (!file.good()) {
                continue;
            }

            std::string fileName = entry.path().filename().string();
            if (fileName.find_first_of("\\/:*?\"<>|") != std::string::npos) {
                continue;
            }

            wavFiles.push_back(entry.path().filename().string());
        }
    }

    return wavFiles;
}

void StopCurrentPlayback() {
    if (!currentWavFile.empty()) {
        mciSendString(L"stop MyWav", NULL, 0, NULL);
        mciSendString(L"close MyWav", NULL, 0, NULL);
        currentWavFile.clear();
        wavplayer_paused = false;
    }
}

void PlayWavFileMCI(const std::string& fileName) {
    try {
        std::string wavFilePath = GetRootFolderPathFromMisc() + "\\" + WAV_PLAYER_FOLDER + "\\" + fileName;

        if (!fs::exists(wavFilePath)) {
            std::cerr << "WAV file not found: " << wavFilePath << std::endl;
            return;
        }

        std::lock_guard<std::mutex> lock(playMutex);

        mciSendString(L"close all", NULL, 0, NULL);

        std::string command = "stop MyWav";
        std::wstring wideCommand = std::wstring(command.begin(), command.end());
        mciSendString(wideCommand.c_str(), NULL, 0, NULL);

        std::wstring playCommand = L"open \"" + std::wstring(wavFilePath.begin(), wavFilePath.end()) + L"\" type waveaudio alias MyWav";
        if (mciSendString(playCommand.c_str(), NULL, 0, NULL) != 0) {
            std::cerr << "Error opening WAV file: " << wavFilePath << std::endl;
            return;
        }

        if (mciSendString(L"play MyWav", NULL, 0, NULL) != 0) {
            std::cerr << "Error playing the WAV file: " << wavFilePath << std::endl;
            return;
        }

        currentWavFile = fileName;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void WavPlayer_loopFunction() {
    wavplayer_loop_bool = !wavplayer_loop_bool;
    if (!wavplayer_loop_bool) {
        PlaySound(NULL, NULL, 0);
    }
}

void WavPlayer_SetVolumeFunction() {
    int volumeLevel = stoi(volumeOptionVector[volumeOptionIndex].substr(0, volumeOptionVector[volumeOptionIndex].size() - 1));

    if (volumeLevel < 0) {
        volumeLevel = 0;
    }
    else if (volumeLevel > 100) {
        volumeLevel = 100;
    }

    DWORD volume = (volumeLevel * 65535 / 100);
    DWORD volumeWithBalance = (volume | (volume << 16));

    waveOutSetVolume(NULL, volumeWithBalance);
}

void WavPlayer_PauseFunction() {
    if (!currentWavFile.empty() && !wavplayer_paused) {
        wavplayer_paused = true;
        PlaySound(NULL, NULL, 0);

        previousPlayTime = static_cast<DWORD>(GetTickCount64());
    }
}

void WavPlayer_ResumeFunction() {
    if (!currentWavFile.empty() && wavplayer_paused) {
        wavplayer_paused = false;
        DWORDLONG resumeTime = GetTickCount64() - previousPlayTime;

        std::this_thread::sleep_for(std::chrono::milliseconds(resumeTime));

        std::wstring wideWavFile = std::wstring(currentWavFile.begin(), currentWavFile.end());
        PlaySound(wideWavFile.c_str(), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void WavPlayer_StopFunction() {
    std::lock_guard<std::mutex> lock(playMutex);

    if (!currentWavFile.empty()) {
        int result = mciSendString(L"stop MyWav", NULL, 0, NULL);
        if (result != 0) {
            std::cerr << "Error stopping the WAV file: " << currentWavFile << std::endl;
        }

        result = mciSendString(L"close MyWav", NULL, 0, NULL);
        if (result != 0) {
            std::cerr << "Error closing the WAV file: " << currentWavFile << std::endl;
        }

        currentWavFile.clear();
        wavplayer_paused = false;

        std::cerr << "Playback stopped and resources cleared." << std::endl;
    }
    else {
        std::cerr << "No WAV file is currently playing." << std::endl;
    }
}


void WavPlayer_RefreshFunction() {
    wavFiles = GetWavFilesInWavPlayerFolder();
    if (wavFiles.empty()) {
    }
    else {
        for (const auto& file : wavFiles) {
        }
    }
}
