#include "animals.h"
#include "legendary_animals.h"
#include "../../../../../Utils/Saving/States/Spawner/animals_default_states.h"
#include "../../../../../Utils/Functions/Spawner/animals_functions.h"

CAnimalsSubmenu::eAnimalsSubmenuID Submenu_Animals = CAnimalsSubmenu::Submenu_Animals;
CAnimalsSubmenu* g_AnimalsSubmenu = nullptr;

const int submenuPriority = 8;

void CAnimalsSubmenu::Init()
{
    g_Legendary_AnimalsSubmenu = new CLegendary_AnimalsSubmenu();
    g_Legendary_AnimalsSubmenu->Init();

    g_Menu->AddSubmenu("RageMenu", "Animals", Submenu_animals, submenuPriority, [](Submenu* sub) {
        sub->AddSubmenuOption("Legendary Animals", "", Submenu_legendary_animals);

        

        });
}