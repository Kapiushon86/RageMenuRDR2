#include "script.h"
#include "common.hpp"
#include "UI/Menu.hpp"
#include "UI/UIUtil.h"
#include "Utils/Config/config.h"
#include "Utils/Config/settings_manager.h"

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

#include "Utils/Functions/Settings/settings_functions.h"
#include "Utils/Functions/Settings/logging_functions.h"

#include "Utils/Functions/Player/UpdateFeatureLoop/no_clip_update_features_loop.h"
#include "Utils/Functions/Player/UpdateFeatureLoop/player_update_features_loop.h"
#include "Utils/Functions/Player/UpdateFeatureLoop/mount_update_features_loop.h"
#include "Utils/Functions/Player/UpdateFeatureLoop/vehicle_update_features_loop.h"
#include "Utils/Functions/Player/UpdateFeatureLoop/modifiers_update_features_loop.h"
#include "Utils/Functions/Recovery/UpdateFeatureLoop/recovery_update_features_loop.h"
#include "Utils/Functions/Recovery/UpdateFeatureLoop/add_update_features_loop.h"
#include "Utils/Functions/Recovery/UpdateFeatureLoop/remove_update_features_loop.h"
#include "Utils/Functions/Weapons/UpdateFeatureLoop/weapon_update_features_loop.h"
#include "Utils/Functions/Teleport/UpdateFeaturesLoop/teleport_update_features_loop.h"
#include "Utils/Functions/World/UpdateFeatureLoop/world_update_features_loop.h"
#include "Utils/Functions/World/UpdateFeatureLoop/time_update_features_loop.h"
#include "Utils/Functions/World/UpdateFeatureLoop/weather_update_features_loop.h"
#include "Utils/Functions/Misc/UpdateFeatureLoop/misc_update_features_loop.h"
#include "Utils/Functions/Misc/UpdateFeatureLoop/free_camera_update_features_loop.h"
#include "Utils/Functions/Misc/UpdateFeatureLoop/wav_player_update_features_loop.h"
#include "Utils/Functions/Misc/UpdateFeatureLoop/disables_update_features_loop.h"
#include "Utils/Functions/Misc/UpdateFeatureLoop/bypasses_update_features_loop.h"
#include "Utils/Functions/Settings/UpdateFeaturesLoop/settings_update_features_loop.h"
#include "Utils/Functions/Settings/UpdateFeaturesLoop/saving_update_features_loop.h"
#include "Utils/Functions/Settings/UpdateFeaturesLoop/logging_update_features_loop.h"

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <filesystem>
#include <shlobj.h>
#include <Lmcons.h>

std::string DetectGraphicsAPI(int& logCounter, std::ofstream& logFile) {
    char path[MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_MYDOCUMENTS, NULL, 0, path);

    std::string settingsPath = std::string(path) + "\\Rockstar Games\\Red Dead Redemption 2\\Settings\\system.xml";

    std::ifstream settingsFile(settingsPath);
    std::string line;
    std::string apiUsed = "Unknown API";

    if (settingsFile.is_open()) {
        while (std::getline(settingsFile, line)) {
            if (line.find("<API>") != std::string::npos) {
                if (line.find("kSettingAPI_Vulkan") != std::string::npos) {
                    apiUsed = "Vulkan";
                    WriteLogEntry(logFile, "Wrn", "Not Using D3D12", logCounter);
                    WriteLogEntry(logFile, "Suc", "Using Vulkan", logCounter);
                }
                else if (line.find("kSettingAPI_DirectX12") != std::string::npos) {
                    apiUsed = "DirectX 12";
                    WriteLogEntry(logFile, "Wrn", "Not Using Vulkan", logCounter);
                    WriteLogEntry(logFile, "Suc", "Using D3D12", logCounter);
                }
                break;
            }
        }
        settingsFile.close();
    }
    else {
        WriteLogEntry(logFile, "Err", "Settings File Could Not Be Opened", logCounter);
        std::cerr << "Error: Settings file could not be opened!" << std::endl;
    }

    return apiUsed;
}

void InitializeMenu() {
    const int submenuPriority = 8;

    Logging_LoggingFunction();

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

    g_Menu->AddSubmenu("RageMenu", "Main", Submenu_main, submenuPriority, [](Submenu* mainMenu) {
        g_PlayerSubmenu = new CPlayerSubmenu();
        g_PlayerSubmenu->Init();

        g_RecoverySubmenu = new CRecoverySubmenu();
        g_RecoverySubmenu->Init();

        g_WeaponsSubmenu = new CWeaponsSubmenu();
        g_WeaponsSubmenu->Init();

        g_WorldSubmenu = new CWorldSubmenu();
        g_WorldSubmenu->Init();

        g_MiscSubmenu = new CMiscSubmenu();
        g_MiscSubmenu->Init();

        g_SettingsSubmenu = new CSettingsSubmenu();
        g_SettingsSubmenu->Init();

        // g_NetworkSubmenu = new CNetworkSubmenu();
        // g_NetworkSubmenu->Init();

        // g_TeleportSubmenu = new CTeleportSubmenu();
        // g_TeleportSubmenu->Init();

        // g_SpawnerSubmenu = new CSpawnerSubmenu();
        // g_SpawnerSubmenu->Init();

        // g_CreditsSubmenu = new CCreditsSubmenu();
        // g_CreditsSubmenu->Init();

        mainMenu->AddSubmenuOption("Player", "", Submenu_player);
        mainMenu->AddSubmenuOption("Recovery", "", Submenu_recovery);
        mainMenu->AddSubmenuOption("Weapons", "", Submenu_weapons);
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

    // Recovery

    RecoveryUpdateFeaturesLoop();
    AddUpdateFeaturesLoop();
    RemoveUpdateFeaturesLoop();

    // Weapons

    WeaponsUpdateFeaturesLoop();

    // Teleport

    TeleportUpdateFeaturesLoop();

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

    // Settings

    SettingsUpdateFeaturesLoop();
    SavingUpdateFeaturesLoop();
    LoggingUpdateFeaturesLoop();

}

void ScriptMain() {
    Config config;

    config.VerifyFolderStructure();
    config.CreateIniFile();

    SettingsManager::LoadAllSettings();

    g_Menu = std::make_unique<CNativeMenu>();
    InitializeMenu();
    g_Menu->GoToSubmenu(Submenu_main);

    Logging_LoggingFunction();

    while (true) {
        config.CleanupUnwantedFolders();
        g_Menu->Update();
        SettingsManager::SaveAllSettings();

        UpdateFeaturesLoop();

        WAIT(0);
    }
}