#include "humans.h"
#include "humans_males.h"
#include "humans_females.h"
#include <vector>
#include <string>
#include <cmath>
#include "../../../../../Utils/Saving/States/Spawner/humans_default_states.h"
#include "../../../../../Utils/Functions/Spawner/humans_functions.h"

CHumansSubmenu::eHumansSubmenuID Submenu_Humans = CHumansSubmenu::Submenu_Humans;
CHumansSubmenu* g_HumansSubmenu = nullptr;

void CHumansSubmenu::Init() {
    const int submenuPriority = 8;

    g_HumansMalesSubmenu = new CHumansMalesSubmenu();
    g_HumansMalesSubmenu->Init();

    g_HumansFemalesSubmenu = new CHumansFemalesSubmenu();
    g_HumansFemalesSubmenu->Init();

    g_Menu->AddSubmenu("RageMenu", "Main > Spawner > Peds > Humans", Submenu_humans, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Males", "", Submenu_humans_males);
        sub->AddSubmenuOption("Females", "", Submenu_humans_females);

        });
}
