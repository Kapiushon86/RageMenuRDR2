#pragma once
#include "../SubmenuInclude.h"

class CWorldSubmenu
{
public:
    enum eWorldSubmenuID
    {
        Submenu_World,
    };

public:
    void Init();
};

extern CWorldSubmenu::eWorldSubmenuID Submenu_World;
extern CWorldSubmenu* g_WorldSubmenu;
