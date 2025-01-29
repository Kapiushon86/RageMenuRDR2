#include "humans.h"
#include "humans_males.h"
#include "humans_females.h"
#include <vector>
#include <string>
#include <cmath>
#include "../../../../../Utils/Saving/States/Spawner/humans_default_states.h"
#include "../../../../../Utils/Functions/Spawner/humans_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CHumansSubmenu::eHumansSubmenuID Submenu_Humans = CHumansSubmenu::Submenu_Humans;
CHumansSubmenu* g_HumansSubmenu = nullptr;

void CHumansSubmenu::Init() {
    const int submenuPriority = 8;

    g_HumansMalesSubmenu = new CHumansMalesSubmenu();
    g_HumansMalesSubmenu->Init();

    g_HumansFemalesSubmenu = new CHumansFemalesSubmenu();
    g_HumansFemalesSubmenu->Init();

    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Spawner > Peds > Humans" : "Humans";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_humans, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Males", "", Submenu_humans_males);
        sub->AddSubmenuOption("Females", "", Submenu_humans_females);

        });
}
