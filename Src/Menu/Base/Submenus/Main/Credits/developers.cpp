#include "developers.h"
#include "../../../../../Utils/Saving/States/Credits/developers_default_states.h"
#include "../../../../../Utils/Functions/Credits/developers_functions.h"

CDevelopersSubmenu::eDevelopersSubmenuID Submenu_Developers = CDevelopersSubmenu::Submenu_Developers;
CDevelopersSubmenu* g_DevelopersSubmenu = nullptr;

void CDevelopersSubmenu::Init() {
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Developers", Submenu_developers, submenuPriority, [](Submenu* sub) {

        sub->AddRegularOption("Kapiushon93", "", [] {
            Developer_Kapiushon93Function();
            });

        sub->AddRegularOption("JJ", "", [] {
            Developer_JJFunction();
            });


        });
}
