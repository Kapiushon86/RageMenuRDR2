#include "horses.h"
#include "../../../../../Utils/Saving/States/Spawner/horses_default_states.h"
#include "../../../../../Utils/Functions/Spawner/horses_functions.h"

CHorsesSubmenu::eHorsesSubmenuID Submenu_Horses = CHorsesSubmenu::Submenu_Horses;
CHorsesSubmenu* g_HorsesSubmenu = nullptr;

const int submenuPriority = 8;

void CHorsesSubmenu::Init()
{
    g_Menu->AddSubmenu("RageMenu", "Horses", Submenu_horses, submenuPriority, [](Submenu* sub)
        {
          
        });
}
