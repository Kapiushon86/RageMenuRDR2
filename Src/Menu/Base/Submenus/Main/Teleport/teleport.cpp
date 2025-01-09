#include "teleport.h"
#include "../../../../../Utils/Saving/States/Teleport/teleport_default_states.h"
#include "../../../../../Utils/Functions/Teleport/teleport_functions.h"

CTeleportSubmenu::eTeleportSubmenuID Submenu_Teleport = CTeleportSubmenu::Submenu_Teleport;
CTeleportSubmenu* g_TeleportSubmenu = nullptr;



void CTeleportSubmenu::Init()
{
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Teleport", Submenu_teleport, submenuPriority, [](Submenu* sub) {

        sub->AddBoolOption("Auto Waypoint", "", &teleport_auto_waypoint_bool, [=] {
            Teleport_AutoWaypointFunction();
            });

        sub->AddRegularOption("Waypoint", "", [] {
            Teleport_WaypointFunction();
            });

        sub->AddRegularOption("Remove Waypoint", "", [] {
            Teleport_RemoveWaypointFunction();
            });

       /* sub->AddRegularOption("Objective", ".", [] {
            Teleport_TeleportToObjectiveFunction();
            });
        */

        /*sub->AddRegularOption("Camp", "", [] {
            Teleport_TeleportToCampFunction();
            });
            */



        });
}



