#include "settings_manger.h"
#include "config.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <locale>
#include <iostream>


#include "../Saving/States/Settings/saving_default_states.h"

void SettingsUpdateLastEditedTimestamp(std::stringstream& content) {
    std::time_t now = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &now);
    std::stringstream timestamp;

    timestamp.imbue(std::locale("en_US.UTF-8"));
    timestamp << std::put_time(&localTime, "%m-%d-%Y, %X");

    content << "\nLast Edited: " << timestamp.str() << "\n";
}

// Default Open Keys
std::string SettingsManager::keyboardOpenKey = "F5";
std::string SettingsManager::numpadOpenKey = "*";
std::string SettingsManager::controllerOpenKey = "R2+Square";

std::string GetSettingsIniFilePath() {
    Config config;
    return config.GetConfigsFolderPath() + "\\" + "RageMenuSettings.ini";
}

void SettingsManager::SaveOpenKeys(std::stringstream& content) {
    content << "[OPEN SETTINGS]\n\n";

    content << "Keyboard Open Key=" << (keyboardOpenKey.empty() ? "F5" : keyboardOpenKey) << "\n";
    content << "Numpad Open Key=" << (numpadOpenKey.empty() ? "*" : numpadOpenKey) << "\n";
    content << "Controller Open Key=" << (controllerOpenKey.empty() ? "R2+Square" : controllerOpenKey) << "\n";
    content << "----------------------------\n";
}

void SettingsManager::SaveAllSettings(bool forceSave) {
    if (!saving_auto_save_bool && !forceSave) return;

    std::stringstream content;

    SaveOpenKeys(content);

    SettingsUpdateLastEditedTimestamp(content);

    std::ofstream outFile(GetSettingsIniFilePath(), std::ios_base::trunc);
    outFile << content.str();
}

void SettingsManager::LoadOpenKeys() {
    std::ifstream iniFile(GetSettingsIniFilePath());
    if (!iniFile.is_open()) {
        std::cerr << "Failed to open settings file: " << GetSettingsIniFilePath() << std::endl;
        return;
    }

    std::string line;
    bool openSettingsSectionFound = false;

    while (std::getline(iniFile, line)) {
        if (line == "[OPEN SETTINGS]") {
            openSettingsSectionFound = true;
            continue;
        }

        if (openSettingsSectionFound) {
            if (line.find("Keyboard Open Key=") != std::string::npos) {
                keyboardOpenKey = line.substr(line.find("=") + 1);
                if (keyboardOpenKey.empty() || GetVirtualKeyFromString(keyboardOpenKey) == 0) {
                    keyboardOpenKey = "F5";
                }
            }
            else if (line.find("Numpad Open Key=") != std::string::npos) {
                numpadOpenKey = line.substr(line.find("=") + 1);
                if (numpadOpenKey.empty() || GetVirtualKeyFromString(numpadOpenKey) == 0) {
                    numpadOpenKey = "*";
                }
            }
            else if (line.find("Controller Open Key=") != std::string::npos) {
                controllerOpenKey = line.substr(line.find("=") + 1);
                if (controllerOpenKey.empty()) {
                    controllerOpenKey = "R2+Square";
                }
            }
        }
    }

    iniFile.close();
}
