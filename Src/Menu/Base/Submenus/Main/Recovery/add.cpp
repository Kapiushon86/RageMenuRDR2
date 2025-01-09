#include "add.h"
#include "../../../../../Utils/Saving/States/Recovery/add_default_states.h"
#include "../../../../../Utils/Functions/Recovery/add_functions.h"

CAddSubmenu::eAddSubmenuID Submenu_Add = CAddSubmenu::Submenu_Add;
CAddSubmenu* g_AddSubmenu = nullptr;

void CAddSubmenu::Init()
{
    const int submenuPriority = 8;


    g_Menu->AddSubmenu("RageMenu", "Add", Submenu_add, submenuPriority, [](Submenu* sub) {

        sub->AddBoolOption("10k Loop", "", &recovery_add_10k_loop_bool, [] {
            Add_Add10kLoopFunction();
            });

        sub->AddRegularOption("Add 10k", "", [] {
            Add_Add10kFunction();
            });


        });
}
