#include "settings_manager.h"
#include "../Saving/States/Player/player_default_states.h"
#include "../Saving/States/Player/no_clip_default_states.h"
#include "../Saving/States/Player/mount_default_states.h"
#include "../Saving/States/Player/vehicle_default_states.h"
#include "../Saving/States/Player/model_default_states.h"
#include "../Saving/States/Player/model_changer_default_states.h"
#include "../Saving/States/Player/modifiers_default_states.h"
#include "../Saving/States/Player/effects_default_states.h"
#include "../Saving/States/Player/effects_screen_default_states.h"
#include "../Saving/States/Player/effects_particles_default_states.h"
#include "../Saving/States/Network/network_default_states.h"
#include "../Saving/States/Network/players_default_states.h"
#include "../Saving/States/Recovery/recovery_default_states.h"
#include "../Saving/States/Recovery/money_default_states.h"
#include "../Saving/States/Recovery/add_default_states.h"
#include "../Saving/States/Recovery/remove_default_states.h"
#include "../Saving/States/Weapons/weapons_default_states.h"
#include "../Saving/States/Teleport/teleport_default_states.h"
#include "../Saving/States/Spawner/spawner_default_states.h"
#include "../Saving/States/Spawner/peds_default_states.h"
#include "../Saving/States/Spawner/vehicles_default_states.h"
#include "../Saving/States/Spawner/humans_default_states.h"
#include "../Saving/States/Spawner/horses_default_states.h"
#include "../Saving/States/Spawner/animals_default_states.h"
#include "../Saving/States/Spawner/legendary_animals_default_states.h"
#include "../Saving/States/World/world_default_states.h"
#include "../Saving/States/World/time_default_states.h"
#include "../Saving/States/World/weather_default_states.h"
#include "../Saving/States/Misc/misc_default_states.h"
#include "../Saving/States/Misc/free_camera_default_states.h"
#include "../Saving/States/Misc/wav_player_default_states.h"
#include "../Saving/States/Misc/disables_default_states.h"
#include "../Saving/States/Misc/bypasses_default_states.h"
#include "../Saving/States/Settings/settings_default_states.h"
#include "../Saving/States/Settings/saving_default_states.h"
#include "../Saving/States/Settings/logging_default_states.h"
#include "../Saving/States/Credits/credits_default_states.h"
#include "../Saving/States/Credits/core_default_states.h"
#include "../Saving/States/Credits/developers_default_states.h"
#include "../Saving/States/Credits/ragemenu_default_states.h"
#include "../Saving/States/Credits/userinterface_default_states.h"

#include "config.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <locale>

const std::vector<std::string> SettingsManager::categoryOrder = {
    "PLAYER", "NO CLIP", "MOUNT", "VEHICLE", "MODIFIERS", "WEAPONS", "TIME", "WEATHER", "MISC", "FREE CAMERA", "DISABLES","SAVING"
};

const std::unordered_map<std::string, const std::vector<std::pair<std::string, bool*>>*> SettingsManager::settingsCategories = {
    {categoryOrder[0], &playerSettings},
    {categoryOrder[1], &noclipSettings},
    {categoryOrder[2], &mountSettings},
    {categoryOrder[3], &vehicleSettings},
    {categoryOrder[4], &modifiersSettings},
    {categoryOrder[5], &weaponsSettings},
    {categoryOrder[6], &timeSettings},
    {categoryOrder[7], &weatherSettings},
    {categoryOrder[8], &miscSettings},
    {categoryOrder[9], &freecameraSettings},
    {categoryOrder[10], &disablesSettings},
    {categoryOrder[11], &savingSettings},
};

const std::vector<std::pair<std::string, bool*>> SettingsManager::playerSettings = {
    {"Invincibility", &player_invincibility_bool},
    {"Invisibility", &player_invisibility_bool},
    {"Lawless", &player_lawless_bool},
    {"Super Jump", &player_super_jump_bool},
    {"Super Punch", &player_super_punch_bool},
    {"One Hit Ko", &player_one_hit_ko_bool},
    {"Anti Melee", &player_anti_melee_bool},
    {"Everyone Ignore", &player_everyone_ignore_bool},
    {"No Ragdoll", &player_no_ragdoll_bool},
    // {"Climb Steep Slopes", &player_climb_steep_slopes_bool},
    {"Quick Skin", &player_quick_skin_bool},
    {"Always Show Cores", &player_always_show_cores_bool},
    {"Always Clean", &player_always_clean_bool},
};

const std::vector<std::pair<std::string, bool*>> SettingsManager::noclipSettings = {
    {"No Clip", &noclip_no_clip_bool},
    {"Use Yaw Rotation", &noclip_use_yaw_rotation_bool},
    {"Freeze Entity", &noclip_freeze_entity_bool},
};

const std::vector<std::pair<std::string, bool*>> SettingsManager::mountSettings = {
    {"Invincibility", &mount_invincibility_bool},
    {"Invisibility", &mount_invisibility_bool},
    {"Infinite Stamina", &mount_infinite_stamina_bool},
    {"Fearless", &mount_fearless_bool},
    {"No Ragdoll", &mount_no_ragdoll_bool},
    {"Always Show Cores", &mount_always_show_cores_bool},
    {"Always Clean", &mount_always_clean_bool}
};

const std::vector<std::pair<std::string, bool*>> SettingsManager::vehicleSettings = {
    {"Invincibility", &vehicle_invincibility_bool},
    {"Invisibility", &vehicle_invisibility_bool},
    {"Disable Knock Off", &vehicle_disable_knock_off_bool},
    {"Always Clean", &vehicle_always_clean_bool}
};

const std::vector<std::pair<std::string, bool*>> SettingsManager::modifiersSettings = {
    {"Infinite Stamina", &modifiers_infinite_stamina_bool},
    {"Infinite Dead Eye", &modifiers_infinite_dead_eye_bool},
    {"Infinite Eagle Eye", &modifiers_infinite_eagle_eye_bool},
};

const std::vector<std::pair<std::string, bool*>> SettingsManager::weaponsSettings = {
    {"Infinite Ammo", &weapon_infinite_ammo_bool},
    {"Infinite Clip",& weapon_infinite_clip_bool},
    {"One Shot Kill",&weapon_one_shot_kill_bool},
    {"Auto Cock",&weapon_auto_cock_bool},
    {"No Spread",&weapon_no_spread_bool},
    {"Always Clean",&weapon_always_clean_bool},
};

const std::vector<std::pair<std::string, bool*>> SettingsManager::timeSettings = {
    {"Freeze Time", &time_freeze_time_bool},
    {"Loop Time", &time_loop_time_bool},
    {"Sync With System", &time_sync_with_system_bool},
};

const std::vector<std::pair<std::string, bool*>> SettingsManager::weatherSettings = {
    {"Freeze Weather", &weather_freeze_weather_bool},
    {"Loop Weather", &weather_loop_weather_bool},
    {"Ground Snow", &weather_ground_snow_bool},
};

const std::vector<std::pair<std::string, bool*>> SettingsManager::miscSettings = {
    {"Seasonal Greetings", &misc_seasonal_greetings_bool},
    {"Real Alt F4", &misc_real_alt_f4_bool},
    {"Discord Presence", &misc_discord_presence_bool},
};

const std::vector<std::pair<std::string, bool*>> SettingsManager::freecameraSettings = {
    {"Free Camera", &freecamera_free_camera_bool},
    {"Use Yaw Rotation", &freecamera_use_yaw_rotation_bool},
    {"Freeze Entity", &freecamera_freeze_entity_bool},
    {"Entity Invisibility", &freecamera_entity_invisibility_bool},
};

const std::vector<std::pair<std::string, bool*>> SettingsManager::disablesSettings = {
    {"Disable Help Text", &disables_disable_help_text_bool},
    {"Disable Location Info", &disables_disable_location_info_bool},
    {"Disable Radar When Menu Is Open", &disables_disable_radar_when_menu_open_bool},
    {"Disable Horse Whistle On Gamepad", &disables_disable_horse_whistling_bool},
};

const std::vector<std::pair<std::string, bool*>> SettingsManager::savingSettings = {
    {"Auto Save", &saving_auto_save_bool},
    //{"Controller Support", &saving_controller_support_bool},
    //{"Numpad Support",& saving_numpad_support_bool }
};  

std::string SettingsManager::keyboardOpenKey = "F5";
std::string SettingsManager::numpadOpenKey = "*";
std::string SettingsManager::controllerOpenKey = "R2+X";

std::string GetIniFilePath() {
    Config config;
    return config.GetConfigsFolderPath() + "\\" + "RageMenuOptions.ini";
}

bool GetIniBoolValue(const std::string& key, bool defaultValue) {
    std::ifstream iniFile(GetIniFilePath());
    std::string line, itemKey;
    bool value = defaultValue;

    while (std::getline(iniFile, line)) {
        std::istringstream lineStream(line);
        if (std::getline(lineStream, itemKey, '=') && itemKey == key) {
            std::string strValue;
            if (std::getline(lineStream, strValue)) {
                value = (strValue == "true");
            }
            break;
        }
    }

    return value;
}

void SetIniBoolValue(const std::string& key, bool value, std::stringstream& content) {
    content << key << "=" << (value ? "true" : "false") << "\n";
}

void UpdateLastEditedTimestamp(std::stringstream& content) {
    std::time_t now = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &now);
    std::stringstream timestamp;

    timestamp.imbue(std::locale("en_US.UTF-8"));
    timestamp << std::put_time(&localTime, "%m-%d-%Y, %X");

    content << "\nLast Edited: " << timestamp.str() << "\n";
}

void SettingsManager::SaveAllSettings(bool forceSave) {
    if (!saving_auto_save_bool && !forceSave) return;

    std::stringstream content;

    bool firstCategory = true;

    for (const auto& category : categoryOrder) {
        if (!firstCategory) {
            content << "\n";
        }
        firstCategory = false;

        SaveSettingsForCategory(category, content);
    }

    SaveOpenKeys(content);
    UpdateLastEditedTimestamp(content);

    std::ofstream outFile(GetIniFilePath(), std::ios_base::trunc);
    outFile << content.str();
}


void SettingsManager::SaveAllSettingsManual() {
    std::stringstream content;

    bool firstCategory = true;
    for (const std::string& category : categoryOrder) {
        if (!firstCategory) {
            content << "\n";
        }
        firstCategory = false;

        SaveSettingsForCategory(category, content);
    }

    SaveOpenKeys(content);

    UpdateLastEditedTimestamp(content);

    std::ofstream outFile(GetIniFilePath(), std::ios_base::trunc);
    outFile << content.str();
}

void SettingsManager::SaveSettingsForCategory(const std::string& category, std::stringstream& content) {
    content << "[" << category << " SETTINGS]\n\n";

    auto settingsVector = settingsCategories.at(category);
    size_t count = 0;
    size_t totalSettings = settingsVector->size();

    for (const auto& pair : *settingsVector) {
        if (pair.second != nullptr) {
            std::string prefixedKey = category + "_ " + pair.first;
            SetIniBoolValue(prefixedKey, *pair.second, content);
            content << "\n"; 
            count++;
        }
    }

    content << "----------------------------\n";
}

void SettingsManager::SaveOpenKeys(std::stringstream& content) {
    content << "\n";
    content << "[OPEN SETTINGS]\n\n";
    content << "Keyboard Open Key=" << (keyboardOpenKey.empty() ? "F5" : keyboardOpenKey) << "\n\n";
    content << "Numpad Open Key=" << (numpadOpenKey.empty() ? "*" : numpadOpenKey) << "\n\n";
    content << "Controller Open Key=" << (controllerOpenKey.empty() ? "R2+X" : controllerOpenKey) << "\n\n";
    content << "----------------------------\n";
}

void SettingsManager::LoadAllSettings() {
    for (const auto& category : settingsCategories) {
        LoadSettingsForCategory(category.first);
    }

    LoadOpenKeys();
}

void SettingsManager::LoadSettingsForCategory(const std::string& category) {
    auto settingsVector = settingsCategories.at(category);
    for (const auto& pair : *settingsVector) {
        if (pair.second != nullptr) {
            std::string prefixedKey = category + "_ " + pair.first;
            *pair.second = LoadSettingState(category, prefixedKey, *pair.second);
        }
    }
}

void SettingsManager::LoadOpenKeys() {
    std::ifstream iniFile(GetIniFilePath());
    std::string line;
    bool openOptionsSectionFound = false;

    while (std::getline(iniFile, line)) {
        if (line == "[OPEN SETTINGS]") {
            openOptionsSectionFound = true;
        }

        if (openOptionsSectionFound) {
            if (line.find("Keyboard Open Key=") != std::string::npos) {
                keyboardOpenKey = line.substr(line.find("=") + 1);
                if (keyboardOpenKey.empty()) {
                    keyboardOpenKey = "F5";
                }
            }
            if (line.find("Numpad Open Key=") != std::string::npos) {
                numpadOpenKey = line.substr(line.find("=") + 1);
                if (numpadOpenKey.empty()) {
                    numpadOpenKey = "*";
                }
            }
            if (line.find("Controller Open Key=") != std::string::npos) {
                controllerOpenKey = line.substr(line.find("=") + 1);
                if (controllerOpenKey.empty()) {
                    controllerOpenKey = "R2+X";
                }
            }
        }
    }
}

bool SettingsManager::LoadSettingState(const std::string& table, const std::string& key, bool defaultValue) {
    return GetIniBoolValue(key, defaultValue);
}
