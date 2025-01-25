#include "vehicles.h"
#include "../../../../../Utils/Saving/States/Spawner/vehicles_default_states.h"
#include "../../../../../Utils/Functions/Spawner/vehicles_functions.h"

CVehiclesSubmenu::eVehiclesSubmenuID Submenu_Vehicles = CVehiclesSubmenu::Submenu_Vehicles;
CVehiclesSubmenu* g_VehiclesSubmenu = nullptr;

void CVehiclesSubmenu::Init() {
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Main > Spawner > Vehicles", Submenu_vehicles, submenuPriority, [](Submenu* sub) {
   
        });
}
