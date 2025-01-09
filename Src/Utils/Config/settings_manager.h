#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>


class SettingsManager {
public:
    static void SaveAllSettings(bool forceSave = false);
    static void LoadAllSettings();
    static void SaveAllSettingsManual();
    static void SaveOpenKeys(std::stringstream& content);
    static void LoadOpenKeys();
    static std::string keyboardOpenKey;
    static std::string numpadOpenKey;
    static std::string controllerOpenKey;

private:
    static const std::vector<std::pair<std::string, bool*>> playerSettings;
    static const std::vector<std::pair<std::string, bool*>> noclipSettings;
    static const std::vector<std::pair<std::string, bool*>> mountSettings;
    static const std::vector<std::pair<std::string, bool*>> vehicleSettings;
    static const std::vector<std::pair<std::string, bool*>> modelSettings;
    static const std::vector<std::pair<std::string, bool*>> modifiersSettings;
    static const std::vector<std::pair<std::string, bool*>> effectsSettings;
    static const std::vector<std::pair<std::string, bool*>> effectsscreenSettings;
    static const std::vector<std::pair<std::string, bool*>> effectsparticlesSettings;
    static const std::vector<std::pair<std::string, bool*>> networkSettings;
    static const std::vector<std::pair<std::string, bool*>> playersSettings;
    static const std::vector<std::pair<std::string, bool*>> recoverySettings;
    static const std::vector<std::pair<std::string, bool*>> addSettings;
    static const std::vector<std::pair<std::string, bool*>> removeSettings;
    static const std::vector<std::pair<std::string, bool*>> moneySettings;
    static const std::vector<std::pair<std::string, bool*>> weaponsSettings;
    static const std::vector<std::pair<std::string, bool*>> teleportSettings;
    static const std::vector<std::pair<std::string, bool*>> spawnerSettings;
    static const std::vector<std::pair<std::string, bool*>> pedsSettings;
    static const std::vector<std::pair<std::string, bool*>> vehiclesSettings;
    static const std::vector<std::pair<std::string, bool*>> humansSettings;
    static const std::vector<std::pair<std::string, bool*>> horsesSettings;
    static const std::vector<std::pair<std::string, bool*>> animalsSettings;
    static const std::vector<std::pair<std::string, bool*>> legendary_animalsSettings;
    static const std::vector<std::pair<std::string, bool*>> worldSettings;
    static const std::vector<std::pair<std::string, bool*>> timeSettings;
    static const std::vector<std::pair<std::string, bool*>> weatherSettings;
    static const std::vector<std::pair<std::string, bool*>> miscSettings;
    static const std::vector<std::pair<std::string, bool*>> freecameraSettings;
    static const std::vector<std::pair<std::string, bool*>> wavplayerSettings;
    static const std::vector<std::pair<std::string, bool*>> disablesSettings;
    static const std::vector<std::pair<std::string, bool*>> bypassesSettings;
    static const std::vector<std::pair<std::string, bool*>> settingsSettings;
    static const std::vector<std::pair<std::string, bool*>> savingSettings;
    static const std::vector<std::pair<std::string, bool*>> loggingSettings;
    static const std::vector<std::pair<std::string, bool*>> creditsSettings;
    static const std::vector<std::pair<std::string, bool*>> coreSettings;
    static const std::vector<std::pair<std::string, bool*>> developersSettings;
    static const std::vector<std::pair<std::string, bool*>> ragemenuSettings;
    static const std::vector<std::pair<std::string, bool*>> userinterfaceSettings;

    static const std::vector<std::string> categoryOrder;
    static const std::unordered_map<std::string, const std::vector<std::pair<std::string, bool*>>*> settingsCategories;

    static bool LoadSettingState(const std::string& table, const std::string& key, bool defaultValue);
    static void SaveSettingsForCategory(const std::string& category, std::stringstream& content);
    static void LoadSettingsForCategory(const std::string& category);

};

