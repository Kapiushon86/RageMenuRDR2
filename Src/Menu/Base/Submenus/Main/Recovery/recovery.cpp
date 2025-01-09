#include "recovery.h"
#include "money.h"
#include "../../../../../Utils/Saving/States/Recovery/Recovery_default_states.h"
#include "../../../../../Utils/Functions/Recovery/recovery_functions.h"

CRecoverySubmenu::eRecoverySubmenuID Submenu_Recovery = CRecoverySubmenu::Submenu_Recovery;
CRecoverySubmenu* g_RecoverySubmenu = nullptr;

void CRecoverySubmenu::Init()
{
    const int submenuPriority = 8;


    g_MoneySubmenu = new CMoneySubmenu();
    g_MoneySubmenu->Init();

    g_Menu->AddSubmenu("RageMenu", "Recovery", Submenu_recovery, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Money", "", Submenu_money);
       
        });
}
