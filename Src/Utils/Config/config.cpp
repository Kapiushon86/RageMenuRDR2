#include "config.h"
#include <Windows.h>
#include <shlobj.h>
#include <filesystem>
#include <vector>
#include <fstream>
#include <psapi.h>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <iostream>

namespace fs = std::filesystem;

std::string Config::GetLogFilePath() {
    return GetLogsFolderPath() + "\\" + LOG_FILE_NAME;
}

std::string Config::GetDateSpecificFolderPath() {
    std::time_t now = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &now);
    std::ostringstream dateStream;
    dateStream << std::setw(2) << std::setfill('0') << (localTime.tm_mon + 1) << "-"
        << std::setw(2) << std::setfill('0') << localTime.tm_mday << "-"
        << (localTime.tm_year + 1900);
    return GetLogsFolderPath() + "\\" + dateStream.str();
}

std::string Config::GetRDR2Path() {
    return fs::current_path().string();
}

std::string Config::GetRootFolderPath() {
    return GetRDR2Path() + "\\" + ROOT_FOLDER;
}

std::string Config::GetLogsFolderPath() {
    return GetRootFolderPath() + "\\" + LOGS_FOLDER;
}

std::string Config::GetConfigsFolderPath() {
    return GetRootFolderPath() + "\\" + CONFIGS_FOLDER;
}

std::string Config::GetUtilsFolderPath() {
    return GetRootFolderPath() + "\\" + UTILS_FOLDER;
}

std::string Config::GetSkipIntroFolderPath() {
    return GetRootFolderPath() + "\\" + UTILS_FOLDER + "\\" + SKIPINTRO_FOLDER;
}

std::string Config::GetWavPlayerFolderPath() {
    return GetRootFolderPath() + "\\" + WAV_PLAYER_FOLDER;
}

bool Config::CreateDirectoryStructure() {
    std::vector<std::string> paths = {
        GetRootFolderPath(),
        GetConfigsFolderPath(),
        GetLogsFolderPath(),
        GetDateSpecificFolderPath(),
        GetWavPlayerFolderPath(),
    };

    for (const auto& path : paths) {
        CreateFolderWithPermissions(path);
    }
    return true;
}

bool Config::VerifyFolderStructure() {
    std::vector<std::string> requiredPaths = {
        GetRootFolderPath(),
        GetConfigsFolderPath(),
        GetLogsFolderPath(),
        GetDateSpecificFolderPath(),
        GetWavPlayerFolderPath(),
    };

    for (const auto& path : requiredPaths) {
        if (!fs::exists(path)) {
            CreateFolderWithPermissions(path);
        }
    }
    return true;
}

bool Config::CleanupUnwantedFolders() {
    std::vector<std::string> foldersToKeep = {
        CONFIGS_FOLDER,
        LOGS_FOLDER,
        UTILS_FOLDER,
        SKIPINTRO_FOLDER,
        WAV_PLAYER_FOLDER,
        GetDateSpecificFolderPath()
    };

    for (const auto& entry : fs::directory_iterator(GetRootFolderPath())) {
        if (entry.is_directory() &&
            std::find(foldersToKeep.begin(), foldersToKeep.end(), entry.path().filename().string()) == foldersToKeep.end()) {
            fs::remove_all(entry.path());
        }
    }
    return true;
}

bool Config::CreateIniFile() {
    std::string iniFilePath = GetConfigsFolderPath() + "\\" + INI_OPTIONS_FILE;
    if (fs::exists(iniFilePath)) {
        return true;
    }

    std::ofstream iniFile(iniFilePath, std::ios::out | std::ios::trunc);
    if (!iniFile.is_open()) {
        return false;
    }
    iniFile.close();
    return true;
}

bool CreateFolderWithPermissions(const std::string& path) {
    try {
        if (!fs::exists(path)) {
            fs::create_directory(path);
            DWORD attributes = GetFileAttributesA(path.c_str());
            SetFileAttributesA(path.c_str(), attributes & ~FILE_ATTRIBUTE_READONLY);
        }
        return true;
    }
    catch (const fs::filesystem_error&) {
        return false;
    }
}
