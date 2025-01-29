#include "settings.h"
#include "themes.h"
#include "saving.h"
#include "logging.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"
#include "../../../../../Utils/Functions/Settings/settings_functions.h"

CSettingsSubmenu::eSettingsSubmenuID Submenu_Settings = CSettingsSubmenu::Submenu_Settings;
CSettingsSubmenu* g_SettingsSubmenu = nullptr;

const int submenuPriority = 8;

void CSettingsSubmenu::Init() {
    g_SavingSubmenu = new CSavingSubmenu();
    g_SavingSubmenu->Init();

    g_LoggingSubmenu = new CLoggingSubmenu();
    g_LoggingSubmenu->Init();

    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Settings" : "Settings";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_settings, submenuPriority, [](Submenu* sub) {
        sub->AddSubmenuOption("Saving", "", Submenu_saving);
        sub->AddSubmenuOption("Logging", "", Submenu_logging);

   /*     sub->AddEmptyOption("Position");
        sub->AddBoolOption("Left", "should the menu align left or right.", &settings_left_position_bool, [] {
            Settings_LeftPositionFunction();
            });

            */

        sub->AddEmptyOption("Background");

        sub->AddBoolOption("Full Alpha", "", &settings_full_alpha_bool, [] {
            SettingsFullAlphaFunction();
            });

        sub->AddEmptyOption("UI Elements");

        sub->AddBoolOption("Show Scroller", "", &settings_show_scroller_bool, [] {
            Settings_ShowScrollerFunction();
            });

        sub->AddBoolOption("Show Submenu Indicators", "", &settings_show_submenu_indicators_bool, [] {
            Settings_ShowSubmenuIndicatorsFunction();
            });

        sub->AddBoolOption("Show Check Boxes", "", &settings_show_check_boxes_bool, [] {
            Settings_ShowCheckBoxesFunction();
            });

        sub->AddBoolOption("Show X For False Values", "", &settings_show_x_for_false_values_bool, [] {
            Settings_ShowXForFalseValuesFunction();
            });

        sub->AddBoolOption("Show Tool Tips", "", &settings_show_tool_tips_bool, [] {
            Settings_ShowToolTipsFunction();
            });

        sub->AddBoolOption("Show Option Counter", "", &settings_show_option_counter_bool, [] {
            Settings_ShowOptionCouterFunction();
            });

        sub->AddBoolOption("Show Empty Options", "", &settings_show_empty_options_bool, [] {
            Settings_ShowEmptyOptionsFunction();
            });

        sub->AddBoolOption("Show Title", "", &settings_show_title_bool, [] {
            Settings_ShowTitleFunction();
            });

        sub->AddBoolOption("Show Header", "", &settings_show_header_bool, [] {
            Settings_ShowHeaderFunction();
            });

        sub->AddBoolOption("Show Sub Header", "", &settings_show_sub_header_bool, [] {
            Settings_ShowSubHeaderFunction();
            });

        sub->AddBoolOption("Show Bread Crumbs", "True = Main > Settings, False = Settings.", &settings_show_bread_crumbs_bool, [] {
            Settings_ShowBreadCrumbsFunction();
            });

        sub->AddBoolOption("Show Version", "", &settings_show_version_bool, [] {
            Settings_ShowVersionFunction();
            });

        sub->AddBoolOption("Show Outliners", "", &settings_show_outliners_bool, [] {
            Settings_ShowOutlinersFunction();
            });

        sub->AddBoolOption("Show Footer", "", &settings_show_footer_bool, [] {
            Settings_ShowFooterFunction();
            });
        });
}
