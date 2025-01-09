#include "core.h"

#include "../../../../../Utils/Saving/States/Credits/core_default_states.h"
#include "../../../../../Utils/Functions/Credits/core_functions.h"

CCoreSubmenu::eCoreSubmenuID Submenu_Core = CCoreSubmenu::Submenu_Core;
CCoreSubmenu* g_CoreSubmenu = nullptr;

void CCoreSubmenu::Init() {
    const int submenuPriority = 8;

  


    g_Menu->AddSubmenu("RageMenu", "Core", Submenu_core, submenuPriority, [](Submenu* sub) {

        sub->AddRegularOption("RageMenu", "", [] {
            Core_RagemenuFunction();
            });

        });
}
