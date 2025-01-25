#pragma once

#include "../SubmenuInclude.h"

class CLocationsSubmenu
{
public:
    enum eLocationsSubmenuID
    {
        Submenu_Locations,
    };

public:
    void Init();
};

extern CLocationsSubmenu::eLocationsSubmenuID Submenu_Locations;
extern CLocationsSubmenu* g_LocationsSubmenu;