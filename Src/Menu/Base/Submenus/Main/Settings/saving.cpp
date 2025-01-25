#include "saving.h"
#include "../../../../../Utils/Saving/States/Settings/saving_default_states.h"
#include "../../../../../Utils/Functions/Settings/saving_functions.h"

CSavingSubmenu::eSavingSubmenuID Submenu_Saving = CSavingSubmenu::Submenu_Saving;
CSavingSubmenu* g_SavingSubmenu = nullptr;


void CSavingSubmenu::Init()
{
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Main > Settings > Saving", Submenu_saving, submenuPriority, [](Submenu* sub) {

        sub->AddBoolOption("Auto Save", "Automatically Save Toggle States To Config", &saving_auto_save_bool, [] {
            Saving_AutoSaveFunction();
            });

       /* sub->AddBoolOption("Controller Support", "", &saving_controller_support_bool, [] {
            Saving_ControllerSupportFunction();
            });

        sub->AddBoolOption("Numpad Support", "", &saving_numpad_support_bool, [] {
            Saving_NumpadSupportFunction();
            });

            */

        sub->AddRegularOption("Manual Save", "Manully Save The Current Toggle States To Config", [] {
            Saving_ManualSaveFunction();
            });
        });
}