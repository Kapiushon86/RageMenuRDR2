#include "logging.h"
#include "../../../../../Utils/Saving/States/Settings/logging_default_states.h"
#include "../../../../../Utils/Functions/Settings/logging_functions.h"

CLoggingSubmenu::eLoggingSubmenuID Submenu_Logging = CLoggingSubmenu::Submenu_Logging;
CLoggingSubmenu* g_LoggingSubmenu = nullptr;


void CLoggingSubmenu::Init()
{
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Main > Settings > Logging", Submenu_logging, submenuPriority, [](Submenu* sub) {

        sub->AddBoolOption("Logging", "Log Output To RageMenu.log.", &logging_logging_bool, [] {
            Logging_LoggingFunction();
            });

      /*  sub->AddBoolOption("Detailed Logging", "Log More Detailed Information.", &logging_detailed_logging_bool, [] {
            Logging_DetailedLoggingFunction();
            });

        sub->AddBoolOption("Console", "Log Output To An External Console.", &logging_console_bool, [] {
            Logging_ConsoleFunction();
            });
            */

        });
}