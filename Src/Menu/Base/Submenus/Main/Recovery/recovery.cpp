#include "recovery.h"
#include "money.h"
#include "../../../../../Utils/Saving/States/Recovery/Recovery_default_states.h"
#include "../../../../../Utils/Functions/Recovery/recovery_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CRecoverySubmenu::eRecoverySubmenuID Submenu_Recovery = CRecoverySubmenu::Submenu_Recovery;
CRecoverySubmenu* g_RecoverySubmenu = nullptr;

void CRecoverySubmenu::Init()
{
    const int submenuPriority = 8;


    g_MoneySubmenu = new CMoneySubmenu();
    g_MoneySubmenu->Init();

    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Recovery" : "Recovery";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_recovery, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Money", "", Submenu_money);
       
        });
}
