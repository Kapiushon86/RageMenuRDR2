#include "dogs.h"
#include "../../../../../Utils/Saving/States/Spawner/humans_default_states.h"
#include "../../../../../Utils/Functions/Spawner/humans_functions.h"

CDogsSubmenu::eDogsSubmenuID Submenu_Dogs = CDogsSubmenu::Submenu_Dogs;
CDogsSubmenu* g_DogsSubmenu = nullptr;

void CDogsSubmenu::Init() {
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Main > Spawner > Animals > Dogs", Submenu_dogs, submenuPriority, [](Submenu* sub) {

        });
}
