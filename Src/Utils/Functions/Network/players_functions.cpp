#include "players_functions.h"
#include "../../../Menu/Base/Submenus/Main/Network/players.h"
#include "../../Saving/States/Network/players_default_states.h"

void Players_NetworkPlayersStatusFunction(Submenu* sub) {
    if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && NETWORK::NETWORK_HAS_SOCIAL_CLUB_ACCOUNT()) {
        Player playerId = PLAYER::PLAYER_ID();
        const char* playerName = PLAYER::GET_PLAYER_NAME(playerId);
        std::string status = NETWORK::NETWORK_IS_SIGNED_ONLINE() ? "~COLOR_GREEN~Online" : "~COLOR_RED~Offline";

        sub->AddRegularOption(playerName, "", [playerName, status] {
            UIUtil::PrintSubtitle(
                "Account Name: " + std::string(playerName) +
                "\nStatus: " + status
            );
            });
    }
    else {
        sub->AddRegularOption("~COLOR_RED~Not signed in to a Social Club account.", "");
    }
}
