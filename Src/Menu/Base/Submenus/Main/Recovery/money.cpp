#include "money.h"
#include "add.h"
#include "remove.h"
#include "../../../../../Utils/Saving/States/Recovery/money_default_states.h"
#include "../../../../../Utils/Functions/Recovery/money_functions.h"


CMoneySubmenu::eMoneySubmenuID Submenu_Money = CMoneySubmenu::Submenu_Money;
CMoneySubmenu* g_MoneySubmenu = nullptr;

void CMoneySubmenu::Init() {
    const int submenuPriority = 8;

    g_AddSubmenu = new CAddSubmenu();
    g_AddSubmenu->Init();

    g_RemoveSubmenu = new CRemoveSubmenu();
    g_RemoveSubmenu->Init();

    g_Menu->AddSubmenu("RageMenu", "Main > Recovery > Money", Submenu_money, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Add", "", Submenu_add);

       // sub->AddSubmenuOption("Remove", "", Submenu_remove);

        });
}
