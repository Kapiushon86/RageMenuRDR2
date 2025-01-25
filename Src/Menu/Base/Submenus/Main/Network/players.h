#pragma once

#include "../SubmenuInclude.h"

class CPlayersSubmenu
{
public:
    enum ePlayersSubmenuID
    {
        Submenu_Players,
    };

public:
    void Init();
};

extern CPlayersSubmenu::ePlayersSubmenuID Submenu_Players;
extern CPlayersSubmenu* g_PlayersSubmenu;
