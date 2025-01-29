#include "peds.h"
#include "humans.h"
#include "horses.h"
#include "animals.h"
#include "../../../../../Utils/Saving/States/Spawner/peds_default_states.h"
#include "../../../../../Utils/Functions/Spawner/peds_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"


CPedsSubmenu::ePedsSubmenuID Submenu_Peds = CPedsSubmenu::Submenu_Peds;
CPedsSubmenu* g_PedsSubmenu = nullptr;

void CPedsSubmenu::Init() {
    const int submenuPriority = 8;

    g_HumansSubmenu = new CHumansSubmenu();
    g_HumansSubmenu->Init();

    g_HorsesSubmenu = new CHorsesSubmenu();
    g_HorsesSubmenu->Init();
    
    g_AnimalsSubmenu = new CAnimalsSubmenu();
    g_AnimalsSubmenu->Init();


    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Spawner > Peds" : "Peds";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_peds, submenuPriority, [](Submenu* sub) {
        sub->AddSubmenuOption("Humans", "", Submenu_humans);
       // sub->AddSubmenuOption("Horses", "", Submenu_horses);
        sub->AddSubmenuOption("Animals", "", Submenu_animals);

        });
}
