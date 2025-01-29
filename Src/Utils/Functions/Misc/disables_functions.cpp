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

void Disables_DisableAllHudFunction() {
    if (disables_disable_all_hud_bool) {
        HUD::HIDE_HUD_AND_RADAR_THIS_FRAME();
    }
}

void Disables_DisableSimpleHudFunction() {
    if (disables_disable_simple_hud_bool) {
        HUD::_HIDE_HUD_THIS_FRAME();

    }
}

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

uint64_t* getGlobalPtr(uint64_t index) {
    return reinterpret_cast<uint64_t*>(index); 
}

void Disables_DisableNewAustinSniperFunction() {
    uint64_t* sniperTimer = getGlobalPtr(1879534 + 44);

    if (sniperTimer) {
        if (disables_disable_new_austin_sniper_bool) {
            *sniperTimer = INT_MAX;
        }
        else {
            *sniperTimer = 0; 
        }
    }
}

void Disables_DisableRadarWhenMenuOpenIsFunction() {
    // Done inside Ui/Menu.cpp
}

void Disables_DisableHorseWhistleOnControllerFunction() {
    // Done inside Ui/menu.cpp
}
