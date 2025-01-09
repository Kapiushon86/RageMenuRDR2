#pragma once

#include "../SubmenuInclude.h"

class CMoneySubmenu
{
public:
    enum eMoneySubmenuID
    {
        Submenu_Money,
    };

public:
    void Init();
};

extern CMoneySubmenu::eMoneySubmenuID Submenu_Money;
extern CMoneySubmenu* g_MoneySubmenu;
