#pragma once

#include "../SubmenuInclude.h"

class CSpawnerSubmenu
{
public:
    enum eSpawnerSubmenuID
    {
        Submenu_Spawner,
    };

public:
    void Init();
};

extern CSpawnerSubmenu::eSpawnerSubmenuID Submenu_Spawner;
extern CSpawnerSubmenu* g_SpawnerSubmenu;
