#include "credits.h"
#include "ragemenu.h"

#include "../../../../../Utils/Saving/States/Credits/credits_default_states.h"
#include "../../../../../Utils/Functions/Credits/credits_functions.h"

CCreditsSubmenu::eCreditsSubmenuID Submenu_Credits = CCreditsSubmenu::Submenu_Credits;
CCreditsSubmenu* g_CreditsSubmenu = nullptr;

void CCreditsSubmenu::Init() {
    const int submenuPriority = 8;

    g_RagemenuSubmenu = new CRagemenuSubmenu();
    g_RagemenuSubmenu->Init();
   

    g_Menu->AddSubmenu("RageMenu", "Credits", Submenu_credits, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("RageMenu", "", Submenu_ragemenu);
        });
}
