#include "teleport_functions.h"
#include "../../../Menu/Base/Submenus/Main/Teleport/teleport.h" 
#include "../../Saving/States/Teleport/teleport_default_states.h" 
#include <math.h>

void Teleport_ShowScreenFadesFunction() {

}

void Teleport_AutoWaypointFunction() {
    if (!teleport_auto_waypoint_bool || !MAP::IS_WAYPOINT_ACTIVE()) {
        return;
    }

    Vector3 waypointCoords = MAP::_GET_WAYPOINT_COORDS();
    if (waypointCoords.x == 0.0f && waypointCoords.y == 0.0f && waypointCoords.z == 0.0f) {
        UIUtil::PrintSubtitle("Teleport Failed: Invalid Waypoint.");
        return;
    }

    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);

    if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
        PED::SET_PED_CAN_RAGDOLL(playerPed, false);
        PED::SET_PED_CAN_RAGDOLL(mount, false);
    }

    const float groundCheckHeights[] = {
        100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0,
        450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0
    };

    bool groundFound = false;
    bool mountGroundFound = false;

    for (float height : groundCheckHeights) {
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, waypointCoords.x, waypointCoords.y, height, true, true, true);
        WAIT(100);

        if (MISC::GET_GROUND_Z_FOR_3D_COORD(waypointCoords.x, waypointCoords.y, height, &waypointCoords.z, false)) {
            waypointCoords.z += 3.0f;
            groundFound = true;
            break;
        }
    }

    if (!groundFound) {
        UIUtil::PrintSubtitle("Teleport Failed: Unable to Find Ground.");
        return;
    }

    if (teleport_show_screen_fades_bool) {
        CAM::DO_SCREEN_FADE_OUT(200);
        WAIT(200);
    }

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, waypointCoords.x, waypointCoords.y, waypointCoords.z, true, true, true);
        ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(playerPed, false);

        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, waypointCoords.x, waypointCoords.y, waypointCoords.z, true, true, true);
        ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(mount, false);
    }
    else {
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, waypointCoords.x, waypointCoords.y, waypointCoords.z, true, true, true);
        ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(playerPed, false);
    }

    if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
        PED::SET_PED_CAN_RAGDOLL(playerPed, true);
        PED::SET_PED_CAN_RAGDOLL(mount, true);
    }

    if (teleport_show_screen_fades_bool) {
        CAM::DO_SCREEN_FADE_IN(250);
        WAIT(250);
    }
}

void Teleport_WaypointFunction() {
    if (!MAP::IS_WAYPOINT_ACTIVE()) {
        UIUtil::PrintSubtitle("Teleport Failed: No Waypoint Active.");
        return;
    }

    Vector3 waypointCoords = MAP::_GET_WAYPOINT_COORDS();
    if (waypointCoords.x == 0.0f && waypointCoords.y == 0.0f && waypointCoords.z == 0.0f) {
        UIUtil::PrintSubtitle("Teleport Failed: Invalid Waypoint.");
        return;
    }

    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);

    if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
        PED::SET_PED_CAN_RAGDOLL(playerPed, false);
        PED::SET_PED_CAN_RAGDOLL(mount, false);
    }

    const float groundCheckHeights[] = {
        100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0,
        450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0
    };

    bool groundFound = false;
    bool mountGroundFound = false;

    for (float height : groundCheckHeights) {
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, waypointCoords.x, waypointCoords.y, height, true, true, true);
        WAIT(100);

        if (MISC::GET_GROUND_Z_FOR_3D_COORD(waypointCoords.x, waypointCoords.y, height, &waypointCoords.z, false)) {
            waypointCoords.z += 3.0f;
            groundFound = true;
            break;
        }
    }

    if (!groundFound) {
        UIUtil::PrintSubtitle("Teleport Failed: Unable to Find Ground.");
        return;
    }

    if (teleport_show_screen_fades_bool) {
        CAM::DO_SCREEN_FADE_OUT(200);
        WAIT(400); 
    }

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, waypointCoords.x, waypointCoords.y, waypointCoords.z, true, true, true);
        ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(playerPed, false);

        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, waypointCoords.x, waypointCoords.y, waypointCoords.z, true, true, true);
        ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(mount, false);
    }
    else {
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, waypointCoords.x, waypointCoords.y, waypointCoords.z, true, true, true);
        ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(playerPed, false);
    }

    if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
        PED::SET_PED_CAN_RAGDOLL(playerPed, true);
        PED::SET_PED_CAN_RAGDOLL(mount, true);
    }

    if (teleport_show_screen_fades_bool) {
        CAM::DO_SCREEN_FADE_IN(250);
        WAIT(400);
    }
}

void Teleport_RemoveWaypointFunction() {
    if (MAP::IS_WAYPOINT_ACTIVE()) {
        MAP::SET_WAYPOINT_OFF();
    }
}

void Teleport_TeleportToObjectiveFunction() {

}

void Teleport_TeleportToCampFunction() {

}

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void Teleport_UseYawRotationFunction() {

}

void Teleport_ForwardFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
        float forwardOffset = 2.0f;
        float heading = 0.0f;

        if (teleport_use_yaw_rotation_bool) {
            Vector3 camRot = CAM::GET_GAMEPLAY_CAM_ROT(2);
            heading = camRot.z;
        }
        else {
            heading = ENTITY::GET_ENTITY_HEADING(playerPed);
        }

        // Convert to radians and cast sin/cos to float
        float radianHeading = static_cast<float>(heading * (M_PI / 180.0));
        float sinHeading = static_cast<float>(sin(radianHeading));
        float cosHeading = static_cast<float>(cos(radianHeading));

        Vector3 forwardPosition = {
            currentPosition.x + forwardOffset * -sinHeading,
            currentPosition.y + forwardOffset * cosHeading,
            currentPosition.z
        };

        float groundZ;
        if (MISC::GET_GROUND_Z_FOR_3D_COORD(forwardPosition.x, forwardPosition.y, forwardPosition.z + 10.0f, &groundZ, false)) {
            forwardPosition.z = groundZ + 1.0f;
        }

        if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
            PED::SET_PED_CAN_RAGDOLL(playerPed, false);
            PED::SET_PED_CAN_RAGDOLL(mount, false);

            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, forwardPosition.x, forwardPosition.y, forwardPosition.z, true, true, true);
            ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(mount, false);

            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, forwardPosition.x, forwardPosition.y, forwardPosition.z, true, true, true);
            ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(playerPed, false);

            PED::SET_PED_CAN_RAGDOLL(playerPed, true);
            PED::SET_PED_CAN_RAGDOLL(mount, true);
        }
        else {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, forwardPosition.x, forwardPosition.y, forwardPosition.z, true, true, true);
            ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(playerPed, false);
        }
    }
}

void Teleport_BackwardsFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
        float forwardOffset = 2.0f;
        float heading = ENTITY::GET_ENTITY_HEADING(playerPed);

        // Convert to radians and cast sin/cos to float
        float radianHeading = static_cast<float>(heading * (M_PI / 180.0));
        float sinHeading = static_cast<float>(sin(radianHeading));
        float cosHeading = static_cast<float>(cos(radianHeading));

        Vector3 backwardPosition = {
            currentPosition.x - forwardOffset * -sinHeading,
            currentPosition.y - forwardOffset * cosHeading,
            currentPosition.z
        };

        float groundZ;
        if (MISC::GET_GROUND_Z_FOR_3D_COORD(backwardPosition.x, backwardPosition.y, backwardPosition.z + 10.0f, &groundZ, false)) {
            backwardPosition.z = groundZ + 1.0f;
        }

        if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
            PED::SET_PED_CAN_RAGDOLL(playerPed, false);
            PED::SET_PED_CAN_RAGDOLL(mount, false);

            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, backwardPosition.x, backwardPosition.y, backwardPosition.z, true, true, true);
            ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(mount, false);

            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, backwardPosition.x, backwardPosition.y, backwardPosition.z, true, true, true);
            ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(playerPed, false);

            PED::SET_PED_CAN_RAGDOLL(playerPed, true);
            PED::SET_PED_CAN_RAGDOLL(mount, true);
        }
        else {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, backwardPosition.x, backwardPosition.y, backwardPosition.z, true, true, true);
            ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(playerPed, false);
        }
    }
}

void Teleport_LeftFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
        float horizontalOffset = 2.0f;
        float heading = ENTITY::GET_ENTITY_HEADING(playerPed);

        // Precompute sin and cos values and explicitly cast to float
        float sinHeading = static_cast<float>(sin(heading * (M_PI / 180.0)));
        float cosHeading = static_cast<float>(cos(heading * (M_PI / 180.0)));

        Vector3 leftPosition = {
            currentPosition.x - horizontalOffset * cosHeading,
            currentPosition.y - horizontalOffset * sinHeading,
            currentPosition.z
        };

        // Only use ground Z check if absolutely necessary (skip for optimization)
        /*
        float groundZ;
        if (MISC::GET_GROUND_Z_FOR_3D_COORD(leftPosition.x, leftPosition.y, leftPosition.z + 10.0f, &groundZ, false)) {
            leftPosition.z = groundZ + 1.0f;
        }
        */

        if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
            PED::SET_PED_CAN_RAGDOLL(playerPed, false);
            PED::SET_PED_CAN_RAGDOLL(mount, false);

            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, leftPosition.x, leftPosition.y, leftPosition.z, true, true, true);
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, leftPosition.x, leftPosition.y, leftPosition.z, true, true, true);

            PED::SET_PED_CAN_RAGDOLL(playerPed, true);
            PED::SET_PED_CAN_RAGDOLL(mount, true);
        }
        else {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, leftPosition.x, leftPosition.y, leftPosition.z, true, true, true);
        }
    }
}

void Teleport_RightFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
        float horizontalOffset = 2.0f;
        float heading = ENTITY::GET_ENTITY_HEADING(playerPed);

        // Precompute sin and cos values and explicitly cast to float
        float sinHeading = static_cast<float>(sin(heading * (M_PI / 180.0)));
        float cosHeading = static_cast<float>(cos(heading * (M_PI / 180.0)));

        Vector3 rightPosition = {
            currentPosition.x + horizontalOffset * cosHeading,
            currentPosition.y + horizontalOffset * sinHeading,
            currentPosition.z
        };

        // Only use ground Z check if absolutely necessary (skip for optimization)
        /*
        float groundZ;
        if (MISC::GET_GROUND_Z_FOR_3D_COORD(rightPosition.x, rightPosition.y, rightPosition.z + 10.0f, &groundZ, false)) {
            rightPosition.z = groundZ + 1.0f;
        }
        */

        if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
            PED::SET_PED_CAN_RAGDOLL(playerPed, false);
            PED::SET_PED_CAN_RAGDOLL(mount, false);

            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, rightPosition.x, rightPosition.y, rightPosition.z, true, true, true);
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, rightPosition.x, rightPosition.y, rightPosition.z, true, true, true);

            PED::SET_PED_CAN_RAGDOLL(playerPed, true);
            PED::SET_PED_CAN_RAGDOLL(mount, true);
        }
        else {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, rightPosition.x, rightPosition.y, rightPosition.z, true, true, true);
        }
    }
}

void Teleport_UpFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
        float verticalOffset = 2.0f; 

        Vector3 upPosition = {
            currentPosition.x,
            currentPosition.y,
            currentPosition.z + verticalOffset
        };

        if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
            PED::SET_PED_CAN_RAGDOLL(playerPed, false);
            PED::SET_PED_CAN_RAGDOLL(mount, false);

            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, upPosition.x, upPosition.y, upPosition.z, true, true, true);

            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, upPosition.x, upPosition.y, upPosition.z, true, true, true);

            PED::SET_PED_CAN_RAGDOLL(playerPed, true);
            PED::SET_PED_CAN_RAGDOLL(mount, true);
        }
        else {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, upPosition.x, upPosition.y, upPosition.z, true, true, true);
        }
    }
}

void Teleport_DownFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
        float verticalOffset = 5.0f;

        Vector3 downPosition = {
            currentPosition.x,
            currentPosition.y,
            currentPosition.z - verticalOffset 
        };

        if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
            PED::SET_PED_CAN_RAGDOLL(playerPed, false);
            PED::SET_PED_CAN_RAGDOLL(mount, false);

            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, downPosition.x, downPosition.y, downPosition.z, true, true, true);
            ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(mount, false);

            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, downPosition.x, downPosition.y, downPosition.z, true, true, true);
            ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(playerPed, false);

            PED::SET_PED_CAN_RAGDOLL(playerPed, true);
            PED::SET_PED_CAN_RAGDOLL(mount, true);
        }
        else {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, downPosition.x, downPosition.y, downPosition.z, true, true, true);
            ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(playerPed, false);
        }
    }
}
