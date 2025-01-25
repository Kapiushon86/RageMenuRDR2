#include "ragemenu.h"
#include "credits.h"
#include "core.h"
#include "developers.h"
#include "userinterface.h"
#include "ragemenu.h"


#include "../../../../../Utils/Saving/States/Credits/ragemenu_default_states.h"
#include "../../../../../Utils/Functions/Credits/ragemenu_functions.h"

CRagemenuSubmenu::eRagemenuSubmenuID Submenu_Ragemenu = CRagemenuSubmenu::Submenu_Ragemenu;
CRagemenuSubmenu* g_RagemenuSubmenu = nullptr;

void CRagemenuSubmenu::Init() {
    const int submenuPriority = 8;

    g_CoreSubmenu = new CCoreSubmenu();
    g_CoreSubmenu->Init();

    g_DevelopersSubmenu = new CDevelopersSubmenu();
    g_DevelopersSubmenu->Init();

    g_UserinterfaceSubmenu = new CUserinterfaceSubmenu();
    g_UserinterfaceSubmenu->Init();




    g_Menu->AddSubmenu("RageMenu", "RageMenu", Submenu_ragemenu, submenuPriority, [](Submenu* sub) {
       
        sub->AddSubmenuOption("Core", "", Submenu_core);
        sub->AddSubmenuOption("Developers", "", Submenu_developers);
        sub->AddSubmenuOption("Userinterface", "", Submenu_userinterface);
   

        });
}
