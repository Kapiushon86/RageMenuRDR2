#pragma once

#include "../SubmenuInclude.h"

class CTeleportSubmenu
{
public:
    enum eTeleportSubmenuID
    {
        Submenu_Teleport,
    };

public:
    void Init();
};

extern CTeleportSubmenu::eTeleportSubmenuID Submenu_Teleport;
extern CTeleportSubmenu* g_TeleportSubmenu;
