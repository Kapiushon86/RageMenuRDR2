#include "animals.h"
#include "legendary_animals.h"
#include "dogs.h"
#include "../../../../../Utils/Saving/States/Spawner/animals_default_states.h"
#include "../../../../../Utils/Functions/Spawner/animals_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CAnimalsSubmenu::eAnimalsSubmenuID Submenu_Animals = CAnimalsSubmenu::Submenu_Animals;
CAnimalsSubmenu* g_AnimalsSubmenu = nullptr;

const int submenuPriority = 8;

void CAnimalsSubmenu::Init()
{
   /* g_Legendary_AnimalsSubmenu = new CLegendary_AnimalsSubmenu();
    g_Legendary_AnimalsSubmenu->Init();

    g_DogsSubmenu = new CDogsSubmenu();
    g_DogsSubmenu->Init();
    */

    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Spawner > Peds > Animals" : "Animals";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_animals, submenuPriority, [](Submenu* sub) {
      //  sub->AddSubmenuOption("Legendary Animals", "", Submenu_legendary_animals);
        //sub->AddSubmenuOption("Dogs", "", Submenu_dogs);

        sub->AddBoolOption("Invincibility", "Spawn The Peds Invincible", &animals_invincibility_bool, [] {
            Animals_InvincibilityFunction();
            });

        sub->AddBoolOption("Alive", "Spawn The Peds Alive Or Dead", &animals_alive_bool, [] {
            Animals_AliveFunction();
            });

        /*sub->AddBoolOption("Variation", "Peds Will Sometimes Spawn With Variation", &animals_variation_bool, [] {
           HumanMales_variationFunction();
           });
           */

        sub->AddRegularOption("Delete All", "Delete All Spawned Peds", [] {
            Animals_DeleteAllFunction();
            });

        sub->AddRegularOption("Delete Last", "Delete Last Spawned Ped", [] {
            Animals_DeleteLastFunction();
            });

        sub->AddEmptyOption("Models");

        AddAnimalsSpawnOptions(sub);
        });
}