#pragma once
#include "../SubmenuInclude.h"

class CBypassesSubmenu
{
public:
    enum eBypassesSubmenuID
    {
        Submenu_Bypasses,
    };

public:
    void Init();
};

extern CBypassesSubmenu::eBypassesSubmenuID Submenu_Bypasses;
extern CBypassesSubmenu* g_BypassesSubmenu;
