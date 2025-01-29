#include "disables.h"
#include "../../../../../Utils/Saving/States/Misc/disables_default_states.h"
#include "../../../../../Utils/Functions/Misc/disables_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CDisablesSubmenu::eDisablesSubmenuID Submenu_Disables = CDisablesSubmenu::Submenu_Disables;
CDisablesSubmenu* g_DisablesSubmenu = nullptr;

const int submenuPriority = 8;

void CDisablesSubmenu::Init()
{
    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Misc > Disables" : "Disables";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_disables, submenuPriority, [](Submenu* sub) {
        sub->AddBoolOption("Disable All Hud", "", &disables_disable_all_hud_bool, [] {
            Disables_DisableAllHudFunction();
            });

        sub->AddBoolOption("Disable Simple Hud", "", &disables_disable_simple_hud_bool, [] {
            Disables_DisableSimpleHudFunction();
            });

        sub->AddBoolOption("Disable Help Text", "", &disables_disable_help_text_bool, [] {
            Disables_DisableHelpTextFunction();
            });

        sub->AddBoolOption("Disable Location Info", "", &disables_disable_location_info_bool, [] {
            Disables_DisableLocationInfoFunction();
            });

        sub->AddBoolOption("Disable New Austin Sniper", "", &disables_disable_new_austin_sniper_bool, [] {
            Disables_DisableNewAustinSniperFunction();
            });

        sub->AddBoolOption("Disable Radar When Menu Is Open", "Disable Showing Radar When Menu Is Open.", &disables_disable_radar_when_menu_is_open_bool, [] {
            Disables_DisableRadarWhenMenuOpenIsFunction();
            });

        sub->AddBoolOption("Disable Horse Whistle On Controller", "Disable Horse Whistling When Menu Is Open On Controller.", &disables_disable_horse_whistle_on_controller_bool, [] {
            Disables_DisableHorseWhistleOnControllerFunction();
            });
        });
}
