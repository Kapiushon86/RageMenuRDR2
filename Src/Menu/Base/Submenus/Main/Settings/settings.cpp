#include "settings.h"
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

    g_Menu->AddSubmenu("RageMenu", "Settings", Submenu_settings, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Saving", "", Submenu_saving);

      //  sub->AddSubmenuOption("Logging", "", Submenu_logging);

        /*sub->AddRegularOption("Unload Menu", "", [] {
            Settings_UnloadMenuFunction();
            });
            */

      //  sub->AddEmptyOption("Settings");

        /*sub->AddBoolOption("Show Breadcrumbs", "", &settings_show_breadcrumbs_bool, [] {
            Settings_ShowBreadcrumbsFunction();
            });
            */
       
        });

        
}