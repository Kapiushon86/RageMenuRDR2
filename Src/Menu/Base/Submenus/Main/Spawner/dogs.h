#pragma once

#include "../SubmenuInclude.h"

class CDogsSubmenu
{
public:
    enum eDogsSubmenuID
    {
        Submenu_Dogs,
    };

public:
    void Init();
};

extern CDogsSubmenu::eDogsSubmenuID Submenu_Dogs;
extern CDogsSubmenu* g_DogsSubmenu;