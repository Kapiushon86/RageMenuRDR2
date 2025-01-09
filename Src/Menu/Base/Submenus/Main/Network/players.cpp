#include "players.h"
#include "../../../../../Utils/Saving/States/Network/players_default_states.h"
#include "../../../../../Utils/Functions/Network/players_functions.h"

CPlayersSubmenu::ePlayersSubmenuID Submenu_Players = CPlayersSubmenu::Submenu_Players;
CPlayersSubmenu* g_PlayersSubmenu = nullptr;

void CPlayersSubmenu::Init() {
    const int submenuPriority = 8;

    int numPlayers = NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS();
    if (numPlayers < 1) {
        numPlayers = 1;
    }
    std::string submenuTitle = "Players " + std::to_string(numPlayers) + "/32";

    g_Menu->AddSubmenu("RageMenu", submenuTitle.c_str(), Submenu_players, submenuPriority, [](Submenu* sub) {
        Players_NetworkPlayersStatusFunction(sub);  
        });
}
