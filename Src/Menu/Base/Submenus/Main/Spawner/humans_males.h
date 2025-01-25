#pragma once

#include "../SubmenuInclude.h"

class CHumansMalesSubmenu
{
public:
    enum eHumansMalesSubmenuID
    {
        Submenu_HumansMales,
    };

public:
    void Init();
};

extern CHumansMalesSubmenu::eHumansMalesSubmenuID Submenu_HumansMales;
extern CHumansMalesSubmenu* g_HumansMalesSubmenu;


void AddMaleHumanSpawnOptions(Submenu* sub);