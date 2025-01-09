#pragma once

#include "../SubmenuInclude.h"

class CVehicleSubmenu
{
public:
    enum eVehicleSubmenuID
    {
        Submenu_Vehicle,
    };

public:
    void Init();
};

extern CVehicleSubmenu::eVehicleSubmenuID Submenu_Vehicle;
extern CVehicleSubmenu* g_VehicleSubmenu;
