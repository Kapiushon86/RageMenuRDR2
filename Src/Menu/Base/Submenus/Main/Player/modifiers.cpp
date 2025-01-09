#include "modifiers.h"
#include "../../../../../Utils/Saving/States/Player/modifiers_default_states.h"
#include "../../../../../Utils/Functions/Player/modifiers_functions.h"

CModifiersSubmenu::eModifiersSubmenuID Submenu_Modifiers = CModifiersSubmenu::Submenu_Modifiers;
CModifiersSubmenu* g_ModifiersSubmenu = nullptr;
const int submenuPriority = 8;

void CModifiersSubmenu::Init() {

    g_Menu->AddSubmenu("RageMenu", "Modifiers", Submenu_modifiers, submenuPriority, [](Submenu* sub) {

        sub->AddBoolOption("Infinite Stamina", "", &modifiers_infinite_stamina_bool, [=] {
            Modifiers_InfiniteStaminaFunction();
            });

        sub->AddBoolOption("Infinite Dead Eye", "", &modifiers_infinite_dead_eye_bool, [=] {
            Modifiers_InfiniteDeadEyeFunction();
            });

        sub->AddBoolOption("Infinite Eagle Eye", "", &modifiers_infinite_eagle_eye_bool, [=] {
            Modifiers_InfiniteEagleEyeFunction();
            });

        /*sub->AddBoolOption("Super Charged Cores", "", &modifiers_super_charged_cores_bool, [=] {
            Modifiers_SuperChargedCoresFunction();
            });
            */

        sub->AddRegularOption("Refill All Cores", "", [] {
            Modifiers_RefillAllCoresFunction();
            });

        sub->AddRegularOption("Refill Health Core", "", [] {
            Modifiers_RefillHealthCoreFunction();
            });

        sub->AddRegularOption("Refill Stamina Core", "", [] {
            Modifiers_RefillStaminaCoreFunction();
            });

        sub->AddRegularOption("Refill Dead Eye Core", "", [] {
            Modifiers_RefillDeadEyeCoreFunction();
            });
            
        });
}
