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
    Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

    if (teleport_show_screen_fades_bool) {
        CAM::DO_SCREEN_FADE_OUT(450);
        WAIT(400);
    }

    const float PlayerGroundCheckHeights[] = {
        100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0,
        450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0
    };

    const float MountGroundCheckHeights[] = {
        100.0, 80.0, 60.0, 40.0, 20.0, 0.0, 120.0, 180.0, 240.0,
        300.0, 360.0, 420.0, 480.0, 540.0, 600.0
    };

    const float VehicleGroundCheckHeights[] = {
        100.0, 90.0, 70.0, 50.0, 30.0, 10.0, 0.0, 120.0, 180.0, 240.0,
        300.0, 360.0, 420.0, 480.0, 540.0
    };

    bool PlayerGroundFound = false;
    bool MountGroundFound = false;
    bool VehicleGroundFound = false;

    // Player Teleport
    if (!PED::IS_PED_IN_ANY_VEHICLE(playerPed, false) && !PED::IS_PED_ON_MOUNT(playerPed)) {
        for (float height : PlayerGroundCheckHeights) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, waypointCoords.x, waypointCoords.y, height, true, true, true);
            WAIT(100);

            if (MISC::GET_GROUND_Z_FOR_3D_COORD(waypointCoords.x, waypointCoords.y, height, &waypointCoords.z, false)) {
                waypointCoords.z += 3.0f;
                PlayerGroundFound = true;
                break;
            }
        }
    }

    // Mount Teleport
    if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
        for (float height : MountGroundCheckHeights) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, waypointCoords.x, waypointCoords.y, height, true, true, true);
            WAIT(100);

            if (MISC::GET_GROUND_Z_FOR_3D_COORD(waypointCoords.x, waypointCoords.y, height, &waypointCoords.z, false)) {
                waypointCoords.z += 3.0f;
                MountGroundFound = true;
                break;
            }
        }
    }

    // Vehicle Teleport
    if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false) && ENTITY::DOES_ENTITY_EXIST(vehicle) && !ENTITY::IS_ENTITY_DEAD(vehicle)) {
        for (float height : VehicleGroundCheckHeights) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehicle, waypointCoords.x, waypointCoords.y, height, true, true, true);
            WAIT(100);

            if (MISC::GET_GROUND_Z_FOR_3D_COORD(waypointCoords.x, waypointCoords.y, height, &waypointCoords.z, false)) {
                waypointCoords.z += 3.0f;
                VehicleGroundFound = true;
                break;
            }
        }
    }

    if (!PlayerGroundFound && !MountGroundFound && !VehicleGroundFound) {
        if (teleport_show_screen_fades_bool) {
            CAM::DO_SCREEN_FADE_IN(250);
        }
        UIUtil::PrintSubtitle("Teleport Failed: Unable to Find Ground.");
        return;
    }

    if (PlayerGroundFound) {
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, waypointCoords.x, waypointCoords.y, waypointCoords.z, true, true, true);
        ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(playerPed, false);
    }

    if (MountGroundFound) {
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, waypointCoords.x, waypointCoords.y, waypointCoords.z, true, true, true);
        ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(mount, false);
    }

    if (VehicleGroundFound) {
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehicle, waypointCoords.x, waypointCoords.y, waypointCoords.z, true, true, true);
        ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(vehicle, false);
    }

    if (teleport_show_screen_fades_bool) {
        CAM::DO_SCREEN_FADE_IN(450);
        WAIT(400);
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
    Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

    if (teleport_show_screen_fades_bool) {
        CAM::DO_SCREEN_FADE_OUT(450);
        WAIT(400);
    }

    const float PlayerGroundCheckHeights[] = {
        100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0,
        450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0
    };

    const float MountGroundCheckHeights[] = {
        100.0, 80.0, 60.0, 40.0, 20.0, 0.0, 120.0, 180.0, 240.0,
        300.0, 360.0, 420.0, 480.0, 540.0, 600.0
    };

    const float VehicleGroundCheckHeights[] = {
        100.0, 90.0, 70.0, 50.0, 30.0, 10.0, 0.0, 120.0, 180.0, 240.0,
        300.0, 360.0, 420.0, 480.0, 540.0
    };

    bool PlayerGroundFound = false;
    bool MountGroundFound = false;
    bool VehicleGroundFound = false;

    // Player Teleport
    if (!PED::IS_PED_IN_ANY_VEHICLE(playerPed, false) && !PED::IS_PED_ON_MOUNT(playerPed)) {
        for (float height : PlayerGroundCheckHeights) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, waypointCoords.x, waypointCoords.y, height, true, true, true);
            WAIT(100);

            if (MISC::GET_GROUND_Z_FOR_3D_COORD(waypointCoords.x, waypointCoords.y, height, &waypointCoords.z, false)) {
                waypointCoords.z += 3.0f;
                PlayerGroundFound = true;
                break;
            }
        }
    }

    // Mount Teleport
    if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
        for (float height : MountGroundCheckHeights) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, waypointCoords.x, waypointCoords.y, height, true, true, true);
            WAIT(100);

            if (MISC::GET_GROUND_Z_FOR_3D_COORD(waypointCoords.x, waypointCoords.y, height, &waypointCoords.z, false)) {
                waypointCoords.z += 3.0f;
                MountGroundFound = true;
                break;
            }
        }
    }

    // Vehicle Teleport
    if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false) && ENTITY::DOES_ENTITY_EXIST(vehicle) && !ENTITY::IS_ENTITY_DEAD(vehicle)) {
        for (float height : VehicleGroundCheckHeights) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehicle, waypointCoords.x, waypointCoords.y, height, true, true, true);
            WAIT(100);

            if (MISC::GET_GROUND_Z_FOR_3D_COORD(waypointCoords.x, waypointCoords.y, height, &waypointCoords.z, false)) {
                waypointCoords.z += 3.0f;
                VehicleGroundFound = true;
                break;
            }
        }
    }

    if (!PlayerGroundFound && !MountGroundFound && !VehicleGroundFound) {
        if (teleport_show_screen_fades_bool) {
            CAM::DO_SCREEN_FADE_IN(250);
        }
        UIUtil::PrintSubtitle("Teleport Failed: Unable to Find Ground.");
        return;
    }

    if (PlayerGroundFound) {
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, waypointCoords.x, waypointCoords.y, waypointCoords.z, true, true, true);
        ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(playerPed, false);
    }

    if (MountGroundFound) {
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, waypointCoords.x, waypointCoords.y, waypointCoords.z, true, true, true);
        ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(mount, false);
    }

    if (VehicleGroundFound) {
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehicle, waypointCoords.x, waypointCoords.y, waypointCoords.z, true, true, true);
        ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(vehicle, false);
    }

    if (teleport_show_screen_fades_bool) {
        CAM::DO_SCREEN_FADE_IN(450);
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
    Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
        float forwardOffset = 2.0f;
        float heading = teleport_use_yaw_rotation_bool ? CAM::GET_GAMEPLAY_CAM_ROT(2).z : ENTITY::GET_ENTITY_HEADING(playerPed);

        float radianHeading = heading * (static_cast<float>(M_PI) / 180.0f);
        float sinHeading = sinf(radianHeading);
        float cosHeading = cosf(radianHeading);

        Vector3 forwardPosition = {
            currentPosition.x + forwardOffset * -sinHeading,
            currentPosition.y + forwardOffset * cosHeading,
            currentPosition.z
        };

        float groundZ;
        if (MISC::GET_GROUND_Z_FOR_3D_COORD(forwardPosition.x, forwardPosition.y, forwardPosition.z + 10.0f, &groundZ, false)) {
            forwardPosition.z = groundZ + 1.0f;
        }

        if (vehicle) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehicle, forwardPosition.x, forwardPosition.y, forwardPosition.z, true, true, true);
        }
        else if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, forwardPosition.x, forwardPosition.y, forwardPosition.z, true, true, true);
        }
        else {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, forwardPosition.x, forwardPosition.y, forwardPosition.z, true, true, true);
        }
    }
}

void Teleport_BackwardsFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);
    Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
        float backwardOffset = 2.0f;
        float heading = ENTITY::GET_ENTITY_HEADING(playerPed);

        float radianHeading = heading * (static_cast<float>(M_PI) / 180.0f);
        float sinHeading = sinf(radianHeading);
        float cosHeading = cosf(radianHeading);

        Vector3 backwardPosition = {
            currentPosition.x - backwardOffset * -sinHeading,
            currentPosition.y - backwardOffset * cosHeading,
            currentPosition.z
        };

        float groundZ;
        if (MISC::GET_GROUND_Z_FOR_3D_COORD(backwardPosition.x, backwardPosition.y, backwardPosition.z + 10.0f, &groundZ, false)) {
            backwardPosition.z = groundZ + 1.0f;
        }

        if (vehicle) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehicle, backwardPosition.x, backwardPosition.y, backwardPosition.z, true, true, true);
        }
        else if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, backwardPosition.x, backwardPosition.y, backwardPosition.z, true, true, true);
        }
        else {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, backwardPosition.x, backwardPosition.y, backwardPosition.z, true, true, true);
        }
    }
}

void Teleport_LeftFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);
    Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
        float horizontalOffset = 2.0f;
        float heading = ENTITY::GET_ENTITY_HEADING(playerPed);

        float radianHeading = static_cast<float>(heading * (M_PI / 180.0));
        float sinHeading = static_cast<float>(sin(radianHeading));
        float cosHeading = static_cast<float>(cos(radianHeading));

        Vector3 leftPosition = {
            currentPosition.x - horizontalOffset * cosHeading,
            currentPosition.y - horizontalOffset * sinHeading,
            currentPosition.z
        };

        float groundZ;
        if (MISC::GET_GROUND_Z_FOR_3D_COORD(leftPosition.x, leftPosition.y, leftPosition.z + 10.0f, &groundZ, false)) {
            leftPosition.z = groundZ + 1.0f;
        }

        if (vehicle) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehicle, leftPosition.x, leftPosition.y, leftPosition.z, true, true, true);
        }
        else if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, leftPosition.x, leftPosition.y, leftPosition.z, true, true, true);
        }
        else {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, leftPosition.x, leftPosition.y, leftPosition.z, true, true, true);
        }
    }
}

void Teleport_RightFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);
    Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
        float horizontalOffset = 2.0f;
        float heading = ENTITY::GET_ENTITY_HEADING(playerPed);

        float radianHeading = static_cast<float>(heading * (M_PI / 180.0));
        float sinHeading = static_cast<float>(sin(radianHeading));
        float cosHeading = static_cast<float>(cos(radianHeading));

        Vector3 rightPosition = {
            currentPosition.x + horizontalOffset * cosHeading,
            currentPosition.y + horizontalOffset * sinHeading,
            currentPosition.z
        };

        float groundZ;
        if (MISC::GET_GROUND_Z_FOR_3D_COORD(rightPosition.x, rightPosition.y, rightPosition.z + 10.0f, &groundZ, false)) {
            rightPosition.z = groundZ + 1.0f;
        }

        if (vehicle) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehicle, rightPosition.x, rightPosition.y, rightPosition.z, true, true, true);
        }
        else if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, rightPosition.x, rightPosition.y, rightPosition.z, true, true, true);
        }
        else {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, rightPosition.x, rightPosition.y, rightPosition.z, true, true, true);
        }
    }
}

void Teleport_UpFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);
    Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
        float verticalOffset = 2.0f;

        Vector3 upPosition = {
            currentPosition.x,
            currentPosition.y,
            currentPosition.z + verticalOffset
        };

        if (vehicle) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehicle, upPosition.x, upPosition.y, upPosition.z, true, true, true);
        }
        else if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, upPosition.x, upPosition.y, upPosition.z, true, true, true);
        }
        else {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, upPosition.x, upPosition.y, upPosition.z, true, true, true);
        }
    }
}

void Teleport_DownFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped mount = PED::GET_MOUNT(playerPed);
    Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
        float verticalOffset = 2.0f;

        Vector3 downPosition = {
            currentPosition.x,
            currentPosition.y,
            currentPosition.z - verticalOffset
        };

        float groundZ;
        if (MISC::GET_GROUND_Z_FOR_3D_COORD(downPosition.x, downPosition.y, downPosition.z + 10.0f, &groundZ, false)) {
            downPosition.z = groundZ - 10.0f;
        }
        else {
            downPosition.z = currentPosition.z - verticalOffset;
        }

        if (vehicle) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehicle, downPosition.x, downPosition.y, downPosition.z, true, true, true);
        }
        else if (PED::IS_PED_ON_MOUNT(playerPed) && ENTITY::DOES_ENTITY_EXIST(mount) && !ENTITY::IS_ENTITY_DEAD(mount)) {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, downPosition.x, downPosition.y, downPosition.z, true, true, true);
        }
        else {
            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, downPosition.x, downPosition.y, downPosition.z, true, true, true);
        }
    }
}

