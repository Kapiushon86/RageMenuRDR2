#include "money.h"
#include "add.h"
#include "remove.h"
#include "../../../../../Utils/Saving/States/Recovery/money_default_states.h"
#include "../../../../../Utils/Functions/Recovery/money_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"


CMoneySubmenu::eMoneySubmenuID Submenu_Money = CMoneySubmenu::Submenu_Money;
CMoneySubmenu* g_MoneySubmenu = nullptr;

void CMoneySubmenu::Init() {
    const int submenuPriority = 8;

    g_AddSubmenu = new CAddSubmenu();
    g_AddSubmenu->Init();

    g_RemoveSubmenu = new CRemoveSubmenu();
    g_RemoveSubmenu->Init();

    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Recovery > Money" : "Money";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_money, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Add", "", Submenu_add);

       // sub->AddSubmenuOption("Remove", "", Submenu_remove);

        });
}
