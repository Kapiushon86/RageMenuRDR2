#pragma once

#include "../SubmenuInclude.h"

class CUserinterfaceSubmenu
{
public:
    enum eUserinterfaceSubmenuID
    {
        Submenu_Userinterface,
    };

public:
    void Init();
};

extern CUserinterfaceSubmenu::eUserinterfaceSubmenuID Submenu_Userinterface;
extern CUserinterfaceSubmenu* g_UserinterfaceSubmenu;
