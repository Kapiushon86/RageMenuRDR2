#pragma once
#include "../SubmenuInclude.h"

class CPlayerSubmenu
{
public:
    enum ePlayerSubmenuID
    {
        Submenu_Player,
    };

public:
    void Init();
};

extern CPlayerSubmenu::ePlayerSubmenuID Submenu_Player;
extern CPlayerSubmenu* g_PlayerSubmenu;
