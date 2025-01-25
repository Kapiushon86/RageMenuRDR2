#pragma once

#include "../SubmenuInclude.h"

class CHumansFemalesSubmenu
{
public:
    enum eHumansFemalesSubmenuID
    {
        Submenu_HumansFemales,
    };

public:
    void Init();
};

extern CHumansFemalesSubmenu::eHumansFemalesSubmenuID Submenu_HumansFemales;
extern CHumansFemalesSubmenu* g_HumansFemalesSubmenu;

void AddFemaleHumanSpawnOptions(Submenu* sub);
