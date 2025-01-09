#include "remove.h"
#include "../../../../../Utils/Saving/States/Recovery/remove_default_states.h"
#include "../../../../../Utils/Functions/Recovery/remove_functions.h"

CRemoveSubmenu::eRemoveSubmenuID Submenu_Remove = CRemoveSubmenu::Submenu_Remove;
CRemoveSubmenu* g_RemoveSubmenu = nullptr;

void CRemoveSubmenu::Init()
{
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Remove", Submenu_remove, submenuPriority, [](Submenu* sub) {

        sub->AddBoolOption("10k Loop", "", &recovery_remove_10k_loop_bool, [] {
            Remove_Remove10kLoopFunction();
            });

        sub->AddRegularOption("Remove 10k", "", [] {
            Remove_Remove10kFunction();
            });


        });
}
