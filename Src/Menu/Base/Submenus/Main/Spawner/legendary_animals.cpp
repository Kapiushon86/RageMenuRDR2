#include "legendary_animals.h"
#include "../../../../../Utils/Saving/States/Spawner/legendary_animals_default_states.h"
#include "../../../../../Utils/Functions/Spawner/legendary_animals_functions.h"

CLegendary_AnimalsSubmenu::eLegendary_AnimalsSubmenuID Submenu_Legendary_Animals = CLegendary_AnimalsSubmenu::Submenu_Legendary_Animals;
CLegendary_AnimalsSubmenu* g_Legendary_AnimalsSubmenu = nullptr;

const int submenuPriority = 8;

void CLegendary_AnimalsSubmenu::Init()
{
    g_Menu->AddSubmenu("RageMenu", " Main > Spawner > Peds > Animals > Legendary Animals", Submenu_legendary_animals, submenuPriority, [](Submenu* sub)
        {
           
        });
}
