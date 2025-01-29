#include "humans_males.h"
#include <cmath>
#include "../../../../../Utils/Saving/States/Spawner/humans_males_default_states.h"
#include "../../../../../Utils/Functions/Spawner/humans_males_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CHumansMalesSubmenu::eHumansMalesSubmenuID Submenu_HumansMales = CHumansMalesSubmenu::Submenu_HumansMales;
CHumansMalesSubmenu* g_HumansMalesSubmenu = nullptr;

void CHumansMalesSubmenu::Init() {
    const int submenuPriority = 8;

    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Spawner > Peds > Humans > Males" : "Males";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_humans_males, submenuPriority, [](Submenu* sub) {

        sub->AddBoolOption("Invincibility", "Spawn The Peds Invincible", &human_males_invincibility_bool, [] {
            HumanMales_InvincibilityFunction();
            });

        sub->AddBoolOption("Alive", "Spawn The Peds Alive Or Dead", &human_males_alive_bool, [] {
            HumanMales_AliveFunction();
            });

        /*sub->AddBoolOption("Variation", "Peds Will Sometimes Spawn With Variation", &human_males_variation_bool, [] {
           HumanMales_variationFunction();
           });
           */

        sub->AddRegularOption("Delete All", "Delete All Spawned Peds", [] {
            HumanMales_DeleteAllFunction();
            });

        sub->AddRegularOption("Delete Last", "Delete Last Spawned Ped", [] {
            HumanMales_DeleteLastFunction();
            });

        sub->AddEmptyOption("Models");

        AddMaleHumanSpawnOptions(sub); 

        });
}