#pragma once

#include "../SubmenuInclude.h"

class CPedsSubmenu
{
public:
    enum ePedsSubmenuID
    {
        Submenu_Peds,
    };

public:
    void Init();
};

extern CPedsSubmenu::ePedsSubmenuID Submenu_Peds;
extern CPedsSubmenu* g_PedsSubmenu;
