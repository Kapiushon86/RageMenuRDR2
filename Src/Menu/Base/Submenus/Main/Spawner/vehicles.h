#pragma once

#include "../SubmenuInclude.h"

class CVehiclesSubmenu
{
public:
    enum eVehiclesSubmenuID
    {
        Submenu_Vehicles,
    };

public:
    void Init();
};

extern CVehiclesSubmenu::eVehiclesSubmenuID Submenu_Vehicles;
extern CVehiclesSubmenu* g_VehiclesSubmenu;
