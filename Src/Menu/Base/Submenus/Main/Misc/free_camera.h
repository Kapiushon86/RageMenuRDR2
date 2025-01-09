#pragma once
#include "../SubmenuInclude.h"

class CFreecameraSubmenu
{
public:
    enum eFreecameraSubmenuID
    {
        Submenu_Freecamera,
    };

public:
    void Init();
};

extern CFreecameraSubmenu::eFreecameraSubmenuID Submenu_Freecamera;
extern CFreecameraSubmenu* g_FreecameraSubmenu;
