#include "disables_functions.h"
#include "../../../Menu/Base/Submenus/Main/Misc/disables.h" 
#include "../../Saving/States/Misc/disables_default_states.h" 
#include "../../../UI/Menu.hpp"

enum eUIFeedChannel
{
    kFeedChannel_Invalid = 0,
    kFeedChannel_Help = 1,
    kFeedChannel_Location = 2,
    kFeedChannel_Objective = 3,
    kFeedChannel_Subtitle = 4,
    kFeedChannel_Ticker = 5,
    kFeedChannel_Toast = 6,
    kFeedChannel_Isolated = 7,
    kFeedChannel_Transportation = 8,
    kFeedChannel_MissionName = 9,
    kFeedChannel_ReticleMessage = 10,
    kFeedChannel_Shards = 11,
    kFeedChannel_ScoretimerMessage = 12,
    kFeedChannel_VoiceChat = 13,
    kFeedChannel_Count = 14,
};

void Disables_DisableHelpTextFunction() {
    if (disables_disable_help_text_bool) {
        UIFEED::UI_FEED_CLEAR_CHANNEL(kFeedChannel_Help, true, true);
    }
}

void Disables_DisableLocationInfoFunction() {
    if (disables_disable_location_info_bool) {
        UIFEED::UI_FEED_CLEAR_CHANNEL(kFeedChannel_Location, true, true);
    }
}

void Disables_DisableRadarWhenMenuOpenFunction() {

}

void Disables_DisableHorseWhistlingFunction() {

}
