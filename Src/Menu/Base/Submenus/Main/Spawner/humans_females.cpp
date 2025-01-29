#include "humans_females.h"
#include <cmath>
#include "../../../../../Utils/Saving/States/Spawner/humans_females_default_states.h"
#include "../../../../../Utils/Functions/Spawner/humans_females_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CHumansFemalesSubmenu::eHumansFemalesSubmenuID Submenu_HumansFemales = CHumansFemalesSubmenu::Submenu_HumansFemales;
CHumansFemalesSubmenu* g_HumansFemalesSubmenu = nullptr;

void CHumansFemalesSubmenu::Init() {
    const int submenuPriority = 8;

    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Spawner > Peds > Humans > Females" : "Females";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_humans_females, submenuPriority, [](Submenu* sub) {

        sub->AddBoolOption("Invincibility", "Spawn The Peds Invincible", &human_females_invincibility_bool, [] {
            HumanFemales_InvincibilityFunction();
            });

        sub->AddBoolOption("Alive", "Spawn The Peds Alive Or Dead", &human_females_alive_bool, [] {
            HumanFemales_AliveFunction();
            });

        /*sub->AddBoolOption("Variation", "Peds Will Sometimes Spawn With Variation", &human_females_variation_bool, [] {
            HumanFemales_variationFunction();
            });
            */

        sub->AddRegularOption("Delete All", "Delete All Spawned Peds", [] {
            HumanFemales_DeleteAllFunction();
            });

        sub->AddRegularOption("Delete Last", "Delete Last Spawned Ped", [] {
            HumanFemales_DeleteLastFunction();
            });

        sub->AddEmptyOption("Models");

        AddFemaleHumanSpawnOptions(sub);

        });
}