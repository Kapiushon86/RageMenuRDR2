#include "teleport.h"
#include "locations.h"
#include "../../../../../Utils/Saving/States/Teleport/teleport_default_states.h"
#include "../../../../../Utils/Functions/Teleport/teleport_functions.h"

CTeleportSubmenu::eTeleportSubmenuID Submenu_Teleport = CTeleportSubmenu::Submenu_Teleport;
CTeleportSubmenu* g_TeleportSubmenu = nullptr;

void CTeleportSubmenu::Init()
{
    const int submenuPriority = 8;

    g_LocationsSubmenu = new CLocationsSubmenu();
    g_LocationsSubmenu->Init();

    g_Menu->AddSubmenu("RageMenu", "Main > Teleport", Submenu_teleport, submenuPriority, [](Submenu* sub) {

      //  sub->AddSubmenuOption("Locations", "", Submenu_locations);

        //sub->AddEmptyOption("Settings");

        sub->AddBoolOption("Show Screen Fades", "Show Screen Fades When Teleporting.", &teleport_show_screen_fades_bool, [=] {
            Teleport_ShowScreenFadesFunction();
            });

        sub->AddBoolOption("Auto Waypoint", "If You Die Just Enable Invincibility.", &teleport_auto_waypoint_bool, [=] {
            Teleport_AutoWaypointFunction();
            });

        sub->AddRegularOption("Waypoint", "If You Die Just Enable Invincibility.", [] {
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

        sub->AddEmptyOption("Directional");

        sub->AddBoolOption("Use Yaw Rotation", "Should You Teleport Based On Player Heading Or Camera Rot.", &teleport_use_yaw_rotation_bool, [] {
            Teleport_UseYawRotationFunction();
            });

        sub->AddRegularOption("Forward", "Use Yaw Rotation Is Really Only Useful For Forward Directional.", [] {
            Teleport_ForwardFunction();
            });

        sub->AddRegularOption("Backwards", "", [] {
            Teleport_BackwardsFunction();
            });

        sub->AddRegularOption("Left", "", [] {
            Teleport_LeftFunction();
            });

        sub->AddRegularOption("Right", "", [] {
            Teleport_RightFunction();
            });

        sub->AddRegularOption("Up", "", [] {
            Teleport_UpFunction();
            });

        sub->AddRegularOption("Down", "", [] {
            Teleport_DownFunction();
            });

        });
}