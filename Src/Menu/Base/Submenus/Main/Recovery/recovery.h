#pragma once
#include "../SubmenuInclude.h"

class CRecoverySubmenu
{
public:
    enum eRecoverySubmenuID
    {
        Submenu_Recovery,
    };

public:
    void Init();
};

extern CRecoverySubmenu::eRecoverySubmenuID Submenu_Recovery;
extern CRecoverySubmenu* g_RecoverySubmenu;
