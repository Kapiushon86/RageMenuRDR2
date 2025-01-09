#pragma once

#include "../SubmenuInclude.h"

class CHumansSubmenu
{
public:
    enum eHumansSubmenuID
    {
        Submenu_Humans,
    };

public:
    void Init();
};

extern CHumansSubmenu::eHumansSubmenuID Submenu_Humans;
extern CHumansSubmenu* g_HumansSubmenu;
