#pragma once
#include "../SubmenuInclude.h"

class CCoreSubmenu
{
public:
    enum eCoreSubmenuID
    {
        Submenu_Core,
    };

public:
    void Init();
};

extern CCoreSubmenu::eCoreSubmenuID Submenu_Core;
extern CCoreSubmenu* g_CoreSubmenu;
