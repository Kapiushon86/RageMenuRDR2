#include "locations.h"
#include "../../../../../Utils/Saving/States/Teleport/locations_default_states.h"
#include "../../../../../Utils/Functions/Teleport/locations_functions.h"

CLocationsSubmenu::eLocationsSubmenuID Submenu_Locations = CLocationsSubmenu::Submenu_Locations;
CLocationsSubmenu* g_LocationsSubmenu = nullptr;

void CLocationsSubmenu::Init() {
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Main > Teleport > Locations", Submenu_locations, submenuPriority, [](Submenu* sub) {

        });
}