#include "network.h"
#include "players.h"
#include "../../../../../Utils/Saving/States/Network/network_default_states.h"
#include "../../../../../Utils/Functions/network/network_functions.h"

CNetworkSubmenu::NetworkSubmenuID Submenu_Example = CNetworkSubmenu::Submenu_Network;
CNetworkSubmenu* g_NetworkSubmenu = nullptr;

void CNetworkSubmenu::Init()
{
    const int submenuPriority = 8;
    
    g_PlayersSubmenu = new CPlayersSubmenu();
    g_PlayersSubmenu->Init();

    g_Menu->AddSubmenu("RageMenu", "Network", Submenu_network, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Players", "", Submenu_players);

       
        });
}
