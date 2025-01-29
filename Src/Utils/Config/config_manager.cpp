#include "config_manager.h"
#include <algorithm>
#include <cctype>    
#include <fstream>
#include <sstream>
#include <string>

// Player

#include "../Saving/States/Player/player_default_states.h"
#include "../Saving/States/Player/no_clip_default_states.h"
#include "../Saving/States/Player/mount_default_states.h"
#include "../Saving/States/Player/vehicle_default_states.h"
#include "../Saving/States/Player/model_default_states.h"
#include "../Saving/States/Player/model_changer_default_states.h"
#include "../Saving/States/Player/modifiers_default_states.h"
#include "../Saving/States/Player/proofs_default_states.h"
#include "../Saving/States/Player/effects_default_states.h"
#include "../Saving/States/Player/effects_screen_default_states.h"
#include "../Saving/States/Player/effects_particles_default_states.h"

// Network

#include "../Saving/States/Network/network_default_states.h"
#include "../Saving/States/Network/players_default_states.h"

// Recovery 

#include "../Saving/States/Recovery/recovery_default_states.h"
#include "../Saving/States/Recovery/money_default_states.h"
#include "../Saving/States/Recovery/add_default_states.h"
#include "../Saving/States/Recovery/remove_default_states.h"

// Weapons

#include "../Saving/States/Weapons/weapons_default_states.h"

// Teleport

#include "../Saving/States/Teleport/teleport_default_states.h"
#include "../Saving/States/Teleport/locations_default_states.h"

// Spawner

#include "../Saving/States/Spawner/spawner_default_states.h"
#include "../Saving/States/Spawner/peds_default_states.h"
#include "../Saving/States/Spawner/vehicles_default_states.h"
#include "../Saving/States/Spawner/humans_default_states.h"
#include "../Saving/States/Spawner/humans_males_default_states.h"
#include "../Saving/States/Spawner/humans_females_default_states.h"
#include "../Saving/States/Spawner/horses_default_states.h"
#include "../Saving/States/Spawner/animals_default_states.h"
#include "../Saving/States/Spawner/legendary_animals_default_states.h"
#include "../Saving/States/Spawner/dogs_default_states.h"

// World

#include "../Saving/States/World/world_default_states.h"
#include "../Saving/States/World/time_default_states.h"
#include "../Saving/States/World/weather_default_states.h"

// Misc

#include "../Saving/States/Misc/misc_default_states.h"
#include "../Saving/States/Misc/free_camera_default_states.h"
#include "../Saving/States/Misc/wav_player_default_states.h"
#include "../Saving/States/Misc/disables_default_states.h"
#include "../Saving/States/Misc/bypasses_default_states.h"
#include "../Saving/States/Misc/links_default_states.h"

// Settings

#include "../Saving/States/Settings/settings_default_states.h"
#include "../Saving/States/Settings/themes_default_states.h"
#include "../Saving/States/Settings/saving_default_states.h"
#include "../Saving/States/Settings/logging_default_states.h"

// Credits

#include "../Saving/States/Credits/credits_default_states.h"
#include "../Saving/States/Credits/core_default_states.h"
#include "../Saving/States/Credits/developers_default_states.h"
#include "../Saving/States/Credits/ragemenu_default_states.h"
#include "../Saving/States/Credits/userinterface_default_states.h"

#include "config.h"
#include <unordered_map>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <locale>

const std::vector<std::string>  ConfigManager::categoryOrder = {
    "PLAYER", "NO CLIP", "MOUNT", "VEHICLE", "MODIFIERS", "WEAPONS", "TELEPORT", "SPAWNER HUMAN MALES", "SPAWNER HUMAN FEMALES", "TIME", "WEATHER", "MISC", "FREE CAMERA", "DISABLES", "SETTINGS", "SAVING", "LOGGING"
};

const std::unordered_map<std::string, const std::vector<std::pair<std::string, bool*>>*> ConfigManager::optionsCategories = {
    {categoryOrder[0], &playerOptions},
    {categoryOrder[1], &noclipOptions},
    {categoryOrder[2], &mountOptions},
    {categoryOrder[3], &vehicleOptions},
    {categoryOrder[4], &modifiersOptions},
    {categoryOrder[5], &weaponsOptions},
    {categoryOrder[6], &teleportOptions},
    {categoryOrder[7], &humansMalesOptions},
    {categoryOrder[8], &humansFemalesOptions},
    {categoryOrder[9], &timeOptions},
    {categoryOrder[10], &weatherOptions},
    {categoryOrder[11], &miscOptions},
    {categoryOrder[12], &freeCameraOptions},
    {categoryOrder[13], &disablesOptions},
    {categoryOrder[14], &settingsOptions},
    {categoryOrder[15], &savingOptions},
    {categoryOrder[16], &loggingOptions},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::playerOptions = {
    {"Invincibility", &player_invincibility_bool},
    {"Invisibility", &player_invisibility_bool},
    {"Lawless", &player_lawless_bool},
    {"Levitate", &player_levitate_bool},
    {"Super Jump", &player_super_jump_bool},
    {"Super Punch", &player_super_punch_bool},
    {"One Hit Ko", &player_one_hit_ko_bool},
    {"Anti Melee", &player_anti_melee_bool},
    {"Everyone Ignore", &player_everyone_ignore_bool},
    {"No Ragdoll", &player_no_ragdoll_bool},
    // {"Climb Steep Slopes", &player_climb_steep_slopes_bool},
    {"Quick Skin", &player_quick_skin_bool},
   // {"Never Loose Hat", &player_never_loose_hat_bool},
    {"Always Show Cores", &player_always_show_cores_bool},
    {"Always Clean", &player_always_clean_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::noclipOptions = {
    {"No Clip", &noclip_no_clip_bool},
    {"Use Yaw Rotation", &noclip_use_yaw_rotation_bool},
    {"Freeze Entity", &noclip_freeze_entity_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::mountOptions = {
    {"Invincibility", &mount_invincibility_bool},
    {"Invisibility", &mount_invisibility_bool},
    {"Levitate", &mount_levitate_bool},
    {"Infinite Stamina", &mount_infinite_stamina_bool},
    {"Infinite Swim", &mount_infinite_swim_bool},
    {"Fearless", &mount_fearless_bool},
    {"No Ragdoll", &mount_no_ragdoll_bool},
    {"Always Show Cores", &mount_always_show_cores_bool},
    {"Always Clean", &mount_always_clean_bool}
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::vehicleOptions = {
    {"Invincibility", &vehicle_invincibility_bool},
    {"Invisibility", &vehicle_invisibility_bool},
    {"Disable Knock Off", &vehicle_disable_knock_off_bool},
    {"Always Clean", &vehicle_always_clean_bool}
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::modifiersOptions = {
    {"Infinite Stamina", &modifiers_infinite_stamina_bool},
    {"Infinite Swim", &modifiers_infinite_swim_bool},
    {"Infinite Dead Eye", &modifiers_infinite_dead_eye_bool},
    {"Infinite Eagle Eye", &modifiers_infinite_eagle_eye_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::weaponsOptions = {
    {"Infinite Ammo", &weapon_infinite_ammo_bool},
    {"Infinite Clip",&weapon_infinite_clip_bool},
    {"Rapid Fire",&weapon_rapid_fire_bool},
    {"One Shot Kill",&weapon_one_shot_kill_bool},
    {"Auto Cock",&weapon_auto_cock_bool},
    {"No Spread",&weapon_no_spread_bool},
    {"No Weapon Wheel Slow Down",&weapon_no_weapon_wheel_slow_down_bool},
    {"Always Clean",&weapon_always_clean_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::teleportOptions = {
    {"Show Screen Fades", &teleport_show_screen_fades_bool},
    {"Auto Waypoint", &teleport_auto_waypoint_bool},
    {"Use Yaw Rotation", &teleport_use_yaw_rotation_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::humansMalesOptions = {
    {"Invincibility", &human_males_invincibility_bool},
    {"Alive", &human_males_alive_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::humansFemalesOptions = {
    {"Invincibility", &human_females_invincibility_bool},
    {"Alive", &human_females_alive_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::timeOptions = {
    {"Freeze Time", &time_freeze_time_bool},
    {"Loop Time", &time_loop_time_bool},
    {"Sync With System", &time_sync_with_system_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::weatherOptions = {
    {"Freeze Weather", &weather_freeze_weather_bool},
    {"Loop Weather", &weather_loop_weather_bool},
    {"Ground Snow", &weather_ground_snow_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::miscOptions = {
    {"Welcome Message", &misc_welcome_message_bool},
    {"Seasonal Greetings", &misc_seasonal_greetings_bool},
    {"Discord Presence", &misc_discord_presence_bool},
    {"Real Alt F4", &misc_real_alt_f4_bool},
    {"Fog Of War", &misc_fog_of_war_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::freeCameraOptions = {
    {"Free Camera", &freecamera_free_camera_bool},
    {"Use Yaw Rotation", &freecamera_use_yaw_rotation_bool},
    {"Freeze Entity", &freecamera_freeze_entity_bool},
    {"Entity Invisibility", &freecamera_entity_invisibility_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::disablesOptions = {
    {"Disable All Hud", &disables_disable_all_hud_bool},
    {"Disable Simple Hud", &disables_disable_simple_hud_bool},
    {"Disable Help Text", &disables_disable_help_text_bool},
    {"Disable Location Info", &disables_disable_location_info_bool},
    {"Disable New Austin Sniper", &disables_disable_new_austin_sniper_bool},
    {"Disable Radar When Menu Is Open", &disables_disable_radar_when_menu_is_open_bool},
    {"Disable Horse Whistle On Controller", &disables_disable_horse_whistle_on_controller_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::settingsOptions = {
   // {"Left", &settings_left_position_bool},
    {"Background Full Alpha", &settings_full_alpha_bool},
    {"Show Scroller", &settings_show_scroller_bool},
    {"Show Submenu Indicators", &settings_show_submenu_indicators_bool},
    {"Show Check Boxes", &settings_show_check_boxes_bool},
    {"Show X For False Values", &settings_show_x_for_false_values_bool},
    {"Show Option Counter", &settings_show_option_counter_bool},
    {"Show Tool Tips", &settings_show_tool_tips_bool},
    {"Show Empty Options", &settings_show_empty_options_bool},
    {"Show Title", &settings_show_title_bool},
    {"Show Header", &settings_show_header_bool},
    {"Show Sub Header", &settings_show_sub_header_bool},
    {"Show Bread Crumbs", &settings_show_bread_crumbs_bool},
    {"Show Version", &settings_show_version_bool},
    {"Show Outliners", &settings_show_outliners_bool},
    {"Show Footer", &settings_show_footer_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::savingOptions = {
    {"Auto Save", &saving_auto_save_bool},
};

const std::vector<std::pair<std::string, bool*>> ConfigManager::loggingOptions = {
    {"Logging", &logging_logging_bool},
    //{"Detailed Logging", &logging_detailed_logging_bool},
    //{"Console", &logging_console_bool},
};

std::string GetOptionsIniFilePath() {
    Config config;
    return config.GetConfigsFolderPath() + "\\" + "RageMenuOptions.ini";
}

std::string ToLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) {
        return std::tolower(c);
        });
    return lowerStr;
}

bool GetIniBoolValue(const std::string& key, bool defaultValue) {
    std::ifstream iniFile(GetOptionsIniFilePath());
    std::string line, itemKey;
    bool value = defaultValue;

    while (std::getline(iniFile, line)) {
        std::istringstream lineStream(line);
        if (std::getline(lineStream, itemKey, '=') && itemKey == key) {
            std::string strValue;
            if (std::getline(lineStream, strValue)) {
                value = (ToLower(strValue) == "true");
            }
            break;
        }
    }

    return value;
}

void SetIniBoolValue(const std::string& key, bool value, std::stringstream& content) {
    content << key << "=" << (value ? "true" : "false") << "\n";
}

void OptionsUpdateLastEditedTimestamp(std::stringstream& content) {
    std::time_t now = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &now);
    std::stringstream timestamp;

    timestamp.imbue(std::locale("en_US.UTF-8"));
    timestamp << std::put_time(&localTime, "%m-%d-%Y, %X");

    content << "\nLast Edited: " << timestamp.str() << "\n";
}

void ConfigManager::SaveAllSettings(bool forceSave) {
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

    OptionsUpdateLastEditedTimestamp(content);

    std::ofstream outFile(GetOptionsIniFilePath(), std::ios_base::trunc);
    outFile << content.str();
}

void ConfigManager::SaveAllSettingsManual() {
    std::stringstream content;

    bool firstCategory = true;
    for (const std::string& category : categoryOrder) {
        if (!firstCategory) {
            content << "\n";
        }
        firstCategory = false;

        SaveSettingsForCategory(category, content);
    }

    OptionsUpdateLastEditedTimestamp(content);

    std::ofstream outFile(GetOptionsIniFilePath(), std::ios_base::trunc);
    outFile << content.str();
}

void ConfigManager::SaveSettingsForCategory(const std::string& category, std::stringstream& content) {
    content << "[" << category << " OPTIONS]\n\n";

    auto settingsVector = optionsCategories.at(category);
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

void ConfigManager::LoadAllSettings() {
    for (const auto& category : optionsCategories) {
        LoadSettingsForCategory(category.first);
    }
}

void ConfigManager::LoadSettingsForCategory(const std::string& category) {
    auto settingsVector = optionsCategories.at(category);
    for (const auto& pair : *settingsVector) {
        if (pair.second != nullptr) {
            std::string prefixedKey = category + "_ " + pair.first;
            *pair.second = LoadSettingState(category, prefixedKey, *pair.second);
        }
    }
}

bool ConfigManager::LoadSettingState(const std::string& table, const std::string& key, bool defaultValue) {
    return GetIniBoolValue(key, defaultValue);
}