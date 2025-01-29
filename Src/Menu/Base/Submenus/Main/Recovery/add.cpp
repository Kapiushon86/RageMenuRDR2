#include "add.h"
#include "../../../../../Utils/Saving/States/Recovery/add_default_states.h"
#include "../../../../../Utils/Functions/Recovery/add_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CAddSubmenu::eAddSubmenuID Submenu_Add = CAddSubmenu::Submenu_Add;
CAddSubmenu* g_AddSubmenu = nullptr;

void CAddSubmenu::Init()
{
    const int submenuPriority = 8;


    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Recovery > Money > Add" : "Add";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_add, submenuPriority, [](Submenu* sub) {

        sub->AddBoolOption("10k Loop", "", &recovery_add_10k_loop_bool, [] {
            Add_Add10kLoopFunction();
            });

        sub->AddRegularOption("Add 10k", "", [] {
            Add_Add10kFunction();
            });


        });
}
