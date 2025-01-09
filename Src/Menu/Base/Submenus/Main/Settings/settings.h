#pragma once
#include "../SubmenuInclude.h"

class CSettingsSubmenu
{
public:
    enum eSettingsSubmenuID
    {
        Submenu_Settings,
    };

public:
    void Init();
};

extern CSettingsSubmenu::eSettingsSubmenuID Submenu_Settings;
extern CSettingsSubmenu* g_SettingsSubmenu;
