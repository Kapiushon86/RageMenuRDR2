#pragma once
#include "../SubmenuInclude.h"

class CDevelopersSubmenu
{
public:
    enum eDevelopersSubmenuID
    {
        Submenu_Developers,
    };

public:
    void Init();
};

extern CDevelopersSubmenu::eDevelopersSubmenuID Submenu_Developers;
extern CDevelopersSubmenu* g_DevelopersSubmenu;
