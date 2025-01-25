#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

class SettingsManager {
public:
    static void SaveAllSettings(bool forceSave = false);
    static void SaveOpenKeys(std::stringstream& content);
    static void LoadOpenKeys();

    static int GetVirtualKeyFromString(const std::string& key);

    static std::string keyboardOpenKey;
    static std::string numpadOpenKey;
    static std::string controllerOpenKey;

private:
    static const std::vector<std::string> categoryOrder;
    static const std::unordered_map<std::string, const std::vector<std::pair<std::string, bool*>>*> optionsCategories;
};
