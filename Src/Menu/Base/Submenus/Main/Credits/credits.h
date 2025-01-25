#pragma once
#include "../SubmenuInclude.h"

class CCreditsSubmenu
{
public:
    enum eCreditsSubmenuID
    {
        Submenu_Credits,
    };

public:
    void Init();
};

extern CCreditsSubmenu::eCreditsSubmenuID Submenu_Credits;
extern CCreditsSubmenu* g_CreditsSubmenu;
