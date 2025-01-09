#pragma once

#include "../SubmenuInclude.h"

class CAnimalsSubmenu
{
public:
    enum eAnimalsSubmenuID
    {
        Submenu_Animals,
    };

public:
    void Init();
};

extern CAnimalsSubmenu::eAnimalsSubmenuID Submenu_Animals;
extern CAnimalsSubmenu* g_AnimalsSubmenu;
