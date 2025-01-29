#include "spawner.h"
#include "peds.h"
#include "vehicles.h"
#include "../../../../../Utils/Saving/States/Spawner/peds_default_states.h"
#include "../../../../../Utils/Functions/Spawner/peds_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CSpawnerSubmenu::eSpawnerSubmenuID Submenu_Spawner = CSpawnerSubmenu::Submenu_Spawner;
CSpawnerSubmenu* g_SpawnerSubmenu = nullptr;

void CSpawnerSubmenu::Init()
{
    const int submenuPriority = 8;

    g_PedsSubmenu = new CPedsSubmenu();
    g_PedsSubmenu->Init();

    g_VehiclesSubmenu = new CVehiclesSubmenu();
    g_VehiclesSubmenu->Init();

    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Spawner" : "Spawner";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_spawner, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Peds", "", Submenu_peds);
      //  sub->AddSubmenuOption("Vehicles", "", Submenu_vehicles);


        });
}
