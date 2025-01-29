#include "saving_functions.h"
#include "../../../Utils/Config/config_manager.h"
#include "../../../Utils/Config/config.h"
#include "../../../../Menu/Base/Submenus/Main/Settings/saving.h" 
#include "../../../../Utils/Saving/States/Settings/saving_default_states.h" 

#include <filesystem>
#include <iostream>


void Saving_AutoSaveFunction() {
}

void Saving_ControllerSupportFunction() {


}

void Saving_NumpadSupportFunction() {

}

void Saving_ManualSaveFunction() {
    ConfigManager::SaveAllSettingsManual();
}

namespace fs = std::filesystem;

// Toggles Are also based on init not just the ini file so this cant really 
// be done in real time since the toggles will stay in there current state 
// anyway no matter if file is deleted unless reloaded init.
// User Can Just manually delete the files "RageMenuOptions.ini" and "RageMenuSettings.ini" and it will auto regenerate.

void Saving_ResetOptionsToDefaultFunction() {
    Config config;  

    std::string rootPath = config.GetRDR2Path(); 
    std::string configFolderPath = rootPath + "\\" + config.GetConfigsFolderPath();  
    std::string optionsFilePath = configFolderPath + "\\" + config.GetIniOptionsFile(); 

    if (fs::exists(optionsFilePath)) {
        try {
            fs::remove(optionsFilePath);
        }
        catch (const fs::filesystem_error& e) {
            std::cerr << "Error resetting options file: " << e.what() << std::endl;
        }
    }
    else {
        std::cerr << "Options file does not exist." << std::endl;
    }
}

void CheckAndAutoSave() {
    if (saving_auto_save_bool) {
        ConfigManager::SaveAllSettings();
    }

}