#include "saving_functions.h"
#include "../../../Utils/Config/settings_manager.h"
#include "../../../../Menu/Base/Submenus/Main/Settings/saving.h" 
#include "../../../../Utils/Saving/States/Settings/saving_default_states.h" 


void Saving_AutoSaveFunction() {
}

void Saving_ControllerSupportFunction() {


}

void Saving_NumpadSupportFunction() {

}

void Saving_ManualSaveFunction() {
    SettingsManager::SaveAllSettingsManual();
}

void Saving_ResetSelectedOptionFunction() {

}

void CheckAndAutoSave() {
    if (saving_auto_save_bool) {
        SettingsManager::SaveAllSettings();
    }
}