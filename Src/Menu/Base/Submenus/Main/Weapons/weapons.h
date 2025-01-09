#pragma once

#include "../SubmenuInclude.h"

class CWeaponsSubmenu
{
public:
    enum eWeaponsSubmenuID
    {
        Submenu_Weapons,
    };

public:
    void Init();
};

extern CWeaponsSubmenu::eWeaponsSubmenuID Submenu_Weapons;
extern CWeaponsSubmenu* g_WeaponsSubmenu; 
