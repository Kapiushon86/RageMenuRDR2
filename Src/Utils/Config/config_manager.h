#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>


class  ConfigManager {
public:
    static void SaveAllSettings(bool forceSave = false);
    static void LoadAllSettings();
    static void SaveAllSettingsManual();
    static std::string keyboardOpenKey;
    static std::string numpadOpenKey;
    static std::string controllerOpenKey;

private:

    // Player

    static const std::vector<std::pair<std::string, bool*>> playerOptions;
    static const std::vector<std::pair<std::string, bool*>> noclipOptions;
    static const std::vector<std::pair<std::string, bool*>> mountOptions;
    static const std::vector<std::pair<std::string, bool*>> vehicleOptions;
    static const std::vector<std::pair<std::string, bool*>> modelOptions;
    static const std::vector<std::pair<std::string, bool*>> modifiersOptions;
    static const std::vector<std::pair<std::string, bool*>> proofsOptions;
    static const std::vector<std::pair<std::string, bool*>> effectsOptions;
    static const std::vector<std::pair<std::string, bool*>> effectsScreenOptions;
    static const std::vector<std::pair<std::string, bool*>> effectsParticlesOptions;

    // Network

    static const std::vector<std::pair<std::string, bool*>> networkOptions;
    static const std::vector<std::pair<std::string, bool*>> playersOptions;

    // Recovery

    static const std::vector<std::pair<std::string, bool*>> recoveryOptions;
    static const std::vector<std::pair<std::string, bool*>> addOptions;
    static const std::vector<std::pair<std::string, bool*>> removeOptions;
    static const std::vector<std::pair<std::string, bool*>> moneyOptions;

    // Weapons

    static const std::vector<std::pair<std::string, bool*>> weaponsOptions;

    // Teleport

    static const std::vector<std::pair<std::string, bool*>> teleportOptions;
    static const std::vector<std::pair<std::string, bool*>> locationsOptions;

    // Spawner

    static const std::vector<std::pair<std::string, bool*>> spawnerOptions;
    static const std::vector<std::pair<std::string, bool*>> pedsOptions;
    static const std::vector<std::pair<std::string, bool*>> vehiclesOptions;
    static const std::vector<std::pair<std::string, bool*>> humansOptions;
    static const std::vector<std::pair<std::string, bool*>> humansMalesOptions;
    static const std::vector<std::pair<std::string, bool*>> humansFemalesOptions;
    static const std::vector<std::pair<std::string, bool*>> horsesOptions;
    static const std::vector<std::pair<std::string, bool*>> animalsOptions;
    static const std::vector<std::pair<std::string, bool*>> legendaryAnimalsOptions;
    static const std::vector<std::pair<std::string, bool*>> dogsOptions;

    // World

    static const std::vector<std::pair<std::string, bool*>> worldOptions;
    static const std::vector<std::pair<std::string, bool*>> timeOptions;
    static const std::vector<std::pair<std::string, bool*>> weatherOptions;

    // Misc

    static const std::vector<std::pair<std::string, bool*>> miscOptions;
    static const std::vector<std::pair<std::string, bool*>> freeCameraOptions;
    static const std::vector<std::pair<std::string, bool*>> wavPlayerOptions;
    static const std::vector<std::pair<std::string, bool*>> disablesOptions;
    static const std::vector<std::pair<std::string, bool*>> bypassesOptions;
    static const std::vector<std::pair<std::string, bool*>> linksOptions;

    // Settings

    static const std::vector<std::pair<std::string, bool*>> settingsOptions;
    static const std::vector<std::pair<std::string, bool*>> savingOptions;
    static const std::vector<std::pair<std::string, bool*>> loggingOptions;

    // Credits

    static const std::vector<std::pair<std::string, bool*>> creditsOptions;
    static const std::vector<std::pair<std::string, bool*>> coreOptions;
    static const std::vector<std::pair<std::string, bool*>> developersOptions;
    static const std::vector<std::pair<std::string, bool*>> rageMenuOptions;
    static const std::vector<std::pair<std::string, bool*>> userInterfaceOptions;

    static const std::vector<std::string> categoryOrder;
    static const std::unordered_map<std::string, const std::vector<std::pair<std::string, bool*>>*> optionsCategories;

    static bool LoadSettingState(const std::string& table, const std::string& key, bool defaultValue);
    static void SaveSettingsForCategory(const std::string& category, std::stringstream& content);
    static void LoadSettingsForCategory(const std::string& category);

};

