#pragma once

#include "../SubmenuInclude.h"

class CHorsesSubmenu {
public:
    enum eHorsesSubmenuID {
        Submenu_Horses,
    };

public:
    void Init();
};

extern CHorsesSubmenu::eHorsesSubmenuID Submenu_Horses;
extern CHorsesSubmenu* g_HorsesSubmenu;
