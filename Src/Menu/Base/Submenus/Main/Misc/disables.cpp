#include "disables.h"
#include "../../../../../Utils/Saving/States/Misc/disables_default_states.h"
#include "../../../../../Utils/Functions/Misc/disables_functions.h"

CDisablesSubmenu::eDisablesSubmenuID Submenu_Disables = CDisablesSubmenu::Submenu_Disables;
CDisablesSubmenu* g_DisablesSubmenu = nullptr;

const int submenuPriority = 8;

void CDisablesSubmenu::Init()
{
    g_Menu->AddSubmenu("RageMenu", "Disables", Submenu_disables, submenuPriority, [](Submenu* sub)
        {
            
            sub->AddBoolOption("Disable Help Text", "No more annoying tips.", &disables_disable_help_text_bool, [] {
                Disables_DisableHelpTextFunction();
                });

            sub->AddBoolOption("Disable Location Info", "", &disables_disable_location_info_bool, [] {
                Disables_DisableLocationInfoFunction();
                });

            sub->AddBoolOption("Disable Radar When Menu Is Open", "Prevent showing radar when menu is open.", &disables_disable_radar_when_menu_open_bool, [] {
                Disables_DisableRadarWhenMenuOpenFunction();
                });

            sub->AddBoolOption("Disable Horse Whistle On Gamepad", "Prevents horse whistling when menu is open on gamepad.", &disables_disable_horse_whistling_bool, [] {
                Disables_DisableHorseWhistlingFunction();
                });

          
        });
}
