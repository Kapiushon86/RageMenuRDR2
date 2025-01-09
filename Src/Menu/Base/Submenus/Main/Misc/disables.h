#pragma once
#include "../SubmenuInclude.h"

class CDisablesSubmenu
{
public:
    enum eDisablesSubmenuID
    {
        Submenu_Disables,
    };

public:
    void Init();
};

extern CDisablesSubmenu::eDisablesSubmenuID Submenu_Disables;
extern CDisablesSubmenu* g_DisablesSubmenu;
