#pragma once

#include "../SubmenuInclude.h"

class CLegendary_AnimalsSubmenu
{
public:
    enum eLegendary_AnimalsSubmenuID
    {
        Submenu_Legendary_Animals,
    };

public:
    void Init();
};

extern CLegendary_AnimalsSubmenu::eLegendary_AnimalsSubmenuID Submenu_Legendary_Animals;
extern CLegendary_AnimalsSubmenu* g_Legendary_AnimalsSubmenu;
