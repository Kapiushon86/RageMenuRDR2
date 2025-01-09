#include "spawner.h"
#include "peds.h"
#include "vehicles.h"
#include "../../../../../Utils/Saving/States/Spawner/peds_default_states.h"
#include "../../../../../Utils/Functions/Spawner/peds_functions.h"

CSpawnerSubmenu::eSpawnerSubmenuID Submenu_Spawner = CSpawnerSubmenu::Submenu_Spawner;
CSpawnerSubmenu* g_SpawnerSubmenu = nullptr;

void CSpawnerSubmenu::Init()
{
    const int submenuPriority = 8;

    g_PedsSubmenu = new CPedsSubmenu();
    g_PedsSubmenu->Init();

    g_VehiclesSubmenu = new CVehiclesSubmenu();
    g_VehiclesSubmenu->Init();

    g_Menu->AddSubmenu("RageMenu", "Spawner", Submenu_spawner, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Peds", "", Submenu_peds);
        sub->AddSubmenuOption("Vehicles", "", Submenu_vehicles);


        });
}
