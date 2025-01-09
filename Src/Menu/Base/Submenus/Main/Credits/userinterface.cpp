#include "userinterface.h"
#include "../../../../../Utils/Saving/States/Credits/userinterface_default_states.h"
#include "../../../../../Utils/Functions/Credits/userinterface_functions.h"


CUserinterfaceSubmenu::eUserinterfaceSubmenuID Submenu_Userinterface = CUserinterfaceSubmenu::Submenu_Userinterface;
CUserinterfaceSubmenu* g_UserinterfaceSubmenu = nullptr;

void CUserinterfaceSubmenu::Init() {
    const int submenuPriority = 8;


    g_Menu->AddSubmenu("RageMenu", "Userinterface", Submenu_userinterface, submenuPriority, [](Submenu* sub) {

        sub->AddRegularOption("Rockstar Games", "", [] {
            UserInterface_RockstarGamesFunction();
            });

        sub->AddRegularOption("Halen84", "", [] {
            UserInterface_Halen84Function();
            });

        sub->AddRegularOption("JJ", "", [] {
            UserInterface_JJFunction();
            });

        sub->AddRegularOption("Ghostone", "", [] {
            UserInterface_GhostoneFunction();
            });
        });
}