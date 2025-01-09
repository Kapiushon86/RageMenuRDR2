#pragma once

#include "../SubmenuInclude.h"

class CModifiersSubmenu
{
public:
    enum eModifiersSubmenuID
    {
        Submenu_Modifiers,
    };

public:
    void Init();
};

extern CModifiersSubmenu::eModifiersSubmenuID Submenu_Modifiers;
extern CModifiersSubmenu* g_ModifiersSubmenu;
