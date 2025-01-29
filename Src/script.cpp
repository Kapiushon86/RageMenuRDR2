#include "script.h"
#include "common.hpp"
#include "UI/Menu.hpp"
#include "UI/UIUtil.h"
#include "Utils/Config/config.h"
#include "Utils/Config/config_manager.h"
#include "Utils/Config/settings_manger.h"

#include "Menu/Base/Submenus/Main/Player/player.h"
#include "Menu/Base/Submenus/Main/Network/network.h"
#include "Menu/Base/Submenus/Main/Recovery/recovery.h"
#include "Menu/Base/Submenus/Main/Weapons/weapons.h"
#include "Menu/Base/Submenus/Main/Teleport/teleport.h"
#include "Menu/Base/Submenus/Main/Spawner/spawner.h"
#include "Menu/Base/Submenus/Main/World/world.h"
#include "Menu/Base/Submenus/Main/Misc/misc.h"
#include "Menu/Base/Submenus/Main/Settings/settings.h"
#include "Menu/Base/Submenus/Main/Credits/credits.h"

// Special 

#include "Utils/Saving/States/Misc/misc_default_states.h"
#include "Utils/Functions/Settings/settings_functions.h"
#include "Utils/Functions/Settings/logging_functions.h"

// Spawn list

#include "Utils/Functions/Spawner/humans_males_functions.h"
#include "Utils/Functions/Spawner/humans_females_functions.h"
#include "Utils/Functions/Spawner/animals_functions.h"


// Player

#include "Utils/Functions/Player/UpdateFeatureLoop/no_clip_update_features_loop.h"
#include "Utils/Functions/Player/UpdateFeatureLoop/player_update_features_loop.h"
#include "Utils/Functions/Player/UpdateFeatureLoop/mount_update_features_loop.h"
#include "Utils/Functions/Player/UpdateFeatureLoop/vehicle_update_features_loop.h"
#include "Utils/Functions/Player/UpdateFeatureLoop/modifiers_update_features_loop.h"
#include "Utils/Functions/Player/UpdateFeatureLoop/proofs_update_features_loop.h"

// Recovery

#include "Utils/Functions/Recovery/UpdateFeatureLoop/recovery_update_features_loop.h"
#include "Utils/Functions/Recovery/UpdateFeatureLoop/add_update_features_loop.h"
#include "Utils/Functions/Recovery/UpdateFeatureLoop/remove_update_features_loop.h"

// Weapons

#include "Utils/Functions/Weapons/UpdateFeatureLoop/weapon_update_features_loop.h"

// Teleport

#include "Utils/Functions/Teleport/UpdateFeaturesLoop/teleport_update_features_loop.h"
#include "Utils/Functions/Teleport/UpdateFeaturesLoop/locations_update_features_loop.h"

// Spawner

#include "Utils/Functions/Spawner/UpdateFeatureLoop/humans_update_features_loop.h"
#include "Utils/Functions/Spawner/UpdateFeatureLoop/humans_males_update_features_loop.h"
#include "Utils/Functions/Spawner/UpdateFeatureLoop/humans_females_update_features_loop.h"
#include "Utils/Functions/Spawner/UpdateFeatureLoop/horses_update_features_loop.h"
#include "Utils/Functions/Spawner/UpdateFeatureLoop/dogs_update_features_loop.h"

// World

#include "Utils/Functions/World/UpdateFeatureLoop/world_update_features_loop.h"
#include "Utils/Functions/World/UpdateFeatureLoop/time_update_features_loop.h"
#include "Utils/Functions/World/UpdateFeatureLoop/weather_update_features_loop.h"

// Misc

#include "Utils/Functions/Misc/UpdateFeatureLoop/misc_update_features_loop.h"
#include "Utils/Functions/Misc/UpdateFeatureLoop/free_camera_update_features_loop.h"
#include "Utils/Functions/Misc/UpdateFeatureLoop/wav_player_update_features_loop.h"
#include "Utils/Functions/Misc/UpdateFeatureLoop/disables_update_features_loop.h"
#include "Utils/Functions/Misc/UpdateFeatureLoop/bypasses_update_features_loop.h"
#include "Utils/Functions/Misc/UpdateFeatureLoop/links_update_features_loop.h"

// Settings

#include "Utils/Functions/Settings/UpdateFeaturesLoop/settings_update_features_loop.h"
#include "Utils/Functions/Settings/UpdateFeaturesLoop/themes_update_features_loop.h"
#include "Utils/Functions/Settings/UpdateFeaturesLoop/saving_update_features_loop.h"
#include "Utils/Functions/Settings/UpdateFeaturesLoop/logging_update_features_loop.h"

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <filesystem>
#include <shlobj.h>
#include <Lmcons.h>
#include <fstream>
#include <unordered_set>
#include <map>

std::string GetEnvVariable(const std::string& varName) {
    char* buffer = nullptr;
    size_t size = 0;
    if (_dupenv_s(&buffer, &size, varName.c_str()) == 0 && buffer != nullptr) {
        std::string value(buffer);
        free(buffer);
        return value;
    }
    return "";
}

// The simplest and easiest way to determine the user's graphics API is by reading it directly from the game's configuration file, avoiding the need to hook into the game's process.

std::string ParseGraphicsAPI(std::ifstream& settingsFile, std::ofstream& logFile, int& logCounter) {
    std::string apiUsed = "Unknown API";
    std::string line;

    if (settingsFile.is_open()) {
        while (std::getline(settingsFile, line)) {
            if (line.find("<API>") != std::string::npos) {
                if (line.find("kSettingAPI_Vulkan") != std::string::npos) {
                    apiUsed = "Vulkan";
                    WriteLogEntry(logFile, "Wrn", "Not Using D3D12", logCounter);
                    WriteLogEntry(logFile, "Suc", "Using Vulkan", logCounter);
                }
                else if (line.find("kSettingAPI_DX12") != std::string::npos) {
                    apiUsed = "DirectX 12";
                    WriteLogEntry(logFile, "Wrn", "Not Using Vulkan", logCounter);
                    WriteLogEntry(logFile, "Suc", "Using D3D12", logCounter);
                }
                break;
            }
        }
    }
    else {
        WriteLogEntry(logFile, "Err", "Settings File Could Not Be Opened", logCounter);
    }

    // If the API was not found, log the error
    if (apiUsed == "Unknown API") {
        WriteLogEntry(logFile, "Err", "Unable to Find Graphics API (Vulkan or DX12)", logCounter);
    }

    return apiUsed;
}

std::string DetectGraphicsAPI(int& logCounter, std::ofstream& logFile) {
    namespace fs = std::filesystem;
    char path[MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_MYDOCUMENTS, NULL, 0, path);

    std::string rockstarPath = std::string(path) + "\\Rockstar Games\\Red Dead Redemption 2\\Settings\\system.xml";
    std::string epicGamesPath = GetEnvVariable("LOCALAPPDATA") + "\\Rockstar Games\\Red Dead Redemption 2\\Settings\\system.xml";
    std::string steamBasePath = GetEnvVariable("PROGRAMFILES(X86)") + "\\Steam\\userdata";

    std::string apiUsed = "Unknown API";
    std::unordered_set<std::string> processedPaths;

    // Rockstar
    if (fs::exists(rockstarPath) && processedPaths.find(rockstarPath) == processedPaths.end()) {
        processedPaths.insert(rockstarPath);
        std::ifstream settingsFile(rockstarPath);
        apiUsed = ParseGraphicsAPI(settingsFile, logFile, logCounter);
    }
    // Epic
    else if (fs::exists(epicGamesPath) && processedPaths.find(epicGamesPath) == processedPaths.end()) {
        processedPaths.insert(epicGamesPath);
        std::ifstream settingsFile(epicGamesPath);
        apiUsed = ParseGraphicsAPI(settingsFile, logFile, logCounter);
    }
    // Steam
    else if (fs::exists(steamBasePath)) {
        for (const auto& entry : fs::directory_iterator(steamBasePath)) {
            if (entry.is_directory()) {
                std::string steamPath = entry.path().string() + "\\1174180\\remote\\system.xml";
                if (fs::exists(steamPath) && processedPaths.find(steamPath) == processedPaths.end()) {
                    processedPaths.insert(steamPath);
                    std::ifstream settingsFile(steamPath);
                    apiUsed = ParseGraphicsAPI(settingsFile, logFile, logCounter);
                    break;
                }
            }
        }
    }

    if (processedPaths.empty()) {
        WriteLogEntry(logFile, "Err", "Settings File Could Not Be Found", logCounter);
        std::cerr << "Error: Settings file could not be found!" << std::endl;
    }

    // If API is still unknown after checking all paths, log and show an error
    if (apiUsed == "Unknown API") {
        WriteLogEntry(logFile, "Err", "Unable to detect Vulkan or DirectX 12. Defaulting to Unknown API.", logCounter);
        std::cerr << "Error: Unable to detect Vulkan or DirectX 12. Defaulting to Unknown API." << std::endl;
    }


    return apiUsed;
}

void InitializeMenu() {
    const int submenuPriority = 8;

    Logging_LoggingFunction();

    // Mostly Simple logging for now besides the api, will expand on this much further in a future update to dynamically fetch all info based on values and such.

    if (logFile.is_open()) {
        WriteLogEntry(logFile, "Inf", "Starting Initialization...", logCounter);

        WriteLogEntry(logFile, "Inf", "Detecting APIs...", logCounter);
        std::string apiUsed = DetectGraphicsAPI(logCounter, logFile);

        WriteLogEntry(logFile, "Inf", "Loading Configurations...", logCounter);

        WriteLogEntry(logFile, "Suc", "RageMenu Has Been Initialized Successfully", logCounter);

        char username[UNLEN + 1];
        DWORD usernameLength = UNLEN + 1;
        if (GetUserNameA(username, &usernameLength)) {
            std::string user(username);
            WriteLogEntry(logFile, "Inf", "Welcome To RageMenu " + user + " - Red Dead Redemption 2", logCounter);
        }
        else {
            WriteLogEntry(logFile, "Inf", "Welcome To RageMenu Unknown User - Red Dead Redemption 2", logCounter);
        }
    }
    else {
        WriteLogEntry(logFile, "Err", "Failed To Initialize RageMenu: Log File Could Not Be Opened.", logCounter);
        std::cerr << "Error: Log file is not open!" << std::endl;
    }

    // Welcome Message

    if (misc_welcome_message_bool) {
        static const std::vector<std::string> welcomeMessages = {
            "Welcome To RageMenu!",
            "To Open Menu (After Welcome Messages) Press: Keyboard: [F5] , Numpad: [*], Controller: [R2+Square]",
            "All Open Keys Can Be Changed Through The Config Inside Your RDR2 Root, Enjoy!"
        };

        for (const auto& message : welcomeMessages) {
            UIUtil::PrintSubtitle(message);
            WAIT(4000);
        }
    }

    g_Menu->AddSubmenu("RageMenu", "Main", Submenu_main, submenuPriority, [](Submenu* mainMenu) {

        g_PlayerSubmenu = new CPlayerSubmenu();
        g_PlayerSubmenu->Init();

        // g_NetworkSubmenu = new CNetworkSubmenu();
       // g_NetworkSubmenu->Init();

        g_RecoverySubmenu = new CRecoverySubmenu();
        g_RecoverySubmenu->Init();

        g_WeaponsSubmenu = new CWeaponsSubmenu();
        g_WeaponsSubmenu->Init();

        g_TeleportSubmenu = new CTeleportSubmenu();
        g_TeleportSubmenu->Init();

        g_SpawnerSubmenu = new CSpawnerSubmenu();
        g_SpawnerSubmenu->Init();

        g_WorldSubmenu = new CWorldSubmenu();
        g_WorldSubmenu->Init();

        g_MiscSubmenu = new CMiscSubmenu();
        g_MiscSubmenu->Init();

        g_SettingsSubmenu = new CSettingsSubmenu();
        g_SettingsSubmenu->Init();

        // g_CreditsSubmenu = new CCreditsSubmenu();
        // g_CreditsSubmenu->Init();

        mainMenu->AddSubmenuOption("Player", "", Submenu_player);
        mainMenu->AddSubmenuOption("Recovery", "", Submenu_recovery);
        mainMenu->AddSubmenuOption("Weapons", "", Submenu_weapons);
        mainMenu->AddSubmenuOption("Teleport", "", Submenu_teleport);
        mainMenu->AddSubmenuOption("Spawner", "", Submenu_spawner);
        mainMenu->AddSubmenuOption("World", "", Submenu_world);
        mainMenu->AddSubmenuOption("Misc", "", Submenu_misc);
        mainMenu->AddSubmenuOption("Settings", "", Submenu_settings);

        });
        
}

void UpdateFeaturesLoop() {

    // Player

    PlayerUpdateFeaturesLoop();
    NoClipUpdateFeaturesLoop();
    MountUpdateFeaturesLoop();
    VehicleUpdateFeaturesLoop();
    ModifiersUpdateFeaturesLoop();
    ProofsUpdateFeaturesLoop();

    // Recovery

    RecoveryUpdateFeaturesLoop();
    AddUpdateFeaturesLoop();
    RemoveUpdateFeaturesLoop();

    // Weapons

    WeaponsUpdateFeaturesLoop();

    // Teleport

    TeleportUpdateFeaturesLoop();
    LocationsUpdateFeaturesLoop();

    // Spawner

    HumansUpdateFeaturesLoop();
    HumansMalesUpdateFeaturesLoop();
    HumansFemalesUpdateFeaturesLoop();
    HorsesUpdateFeaturesLoop();
    DogsUpdateFeaturesLoop();

    // World

    WorldUpdateFeaturesLoop();
    TimeUpdateFeaturesLoop();
    WeatherUpdateFeaturesLoop();

    // Misc

    FreeCameraUpdateFeaturesLoop();
    MiscUpdateFeaturesLoop();
    WavPlayerUpdateFeaturesLoop();
    DisablesUpdateFeaturesLoop();
    BypassesUpdateFeaturesLoop();
    LinksUpdateFeaturesLoop();

    // Settings

    SettingsUpdateFeaturesLoop();
    ThemesUpdateFeaturesLoop();
    SavingUpdateFeaturesLoop();
    LoggingUpdateFeaturesLoop();

}

void ScriptMain() {
    Config config;

    config.VerifyFolderStructure();
    config.CreateOptionsIniFile();
    config.CreateSettingsIniFile();

    ConfigManager::LoadAllSettings();
    SettingsManager::LoadOpenKeys();

    g_Menu = std::make_unique<CNativeMenu>();
    InitializeMenu();
    g_Menu->GoToSubmenu(Submenu_main);

    Logging_LoggingFunction();

    InitializeMaleHumansList();
    InitializeFemaleHumansList();
    InitializeAnimalsList();

    while (true) {
        config.CleanupUnwantedFolders();
        g_Menu->Update();
        ConfigManager::SaveAllSettings();
        SettingsManager::SaveAllSettings();

        UpdateFeaturesLoop();

        WAIT(0);
    }
}
