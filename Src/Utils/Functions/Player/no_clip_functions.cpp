#include "no_clip_functions.h"
#include "../../../Menu/Base/Submenus/Main/Player/no_clip.h" 
#include "../../Saving/States/Player/no_clip_default_states.h" 
#include <cmath>

// Ngl I think I have a better no clip functionality then most other menus, Def better then how Rampage does there no clip...just sayin lol

#define PI 3.1415927f

float NoClip_GetYawRotation() {
    Vector3 camRot = CAM::GET_GAMEPLAY_CAM_ROT(2);
    return camRot.z;
}

float NoClip_GetCurrentSpeed() {
    return std::stof(noclipSpeed[noclipSpeedIndex]);
}

void NoClip_NoClipFunction() {
    static bool initialized = false;

    float currentSpeed = std::stof(noclipSpeed[noclipSpeedIndex]);
    Entity playerPed = PLAYER::PLAYER_PED_ID();

    Entity mount = PED::IS_PED_ON_MOUNT(playerPed) ? PED::GET_MOUNT(playerPed) : NULL;
    Entity vehicle = PED::IS_PED_IN_ANY_VEHICLE(playerPed, false) ? PED::GET_VEHICLE_PED_IS_IN(playerPed, false) : NULL;

    if (noclip_no_clip_bool) {
        if (!initialized) {
            ENTITY::SET_ENTITY_COLLISION(playerPed, false, false);
            if (mount != NULL) {
                ENTITY::SET_ENTITY_COLLISION(mount, false, false);
                ENTITY::FREEZE_ENTITY_POSITION(mount, true); 
            }
            if (vehicle != NULL) {
                ENTITY::SET_ENTITY_COLLISION(vehicle, false, false);
                ENTITY::FREEZE_ENTITY_POSITION(vehicle, true); 
            }
            initialized = true;
        }

        NoClip_FreezeEntityFunction();

        Vector3 currentPosition = ENTITY::GET_ENTITY_COORDS(playerPed, true, false);
        Entity camEntity = playerPed;
        Vector3 camForward = ENTITY::GET_ENTITY_FORWARD_VECTOR(camEntity);
        Vector3 camRight = { camForward.y, -camForward.x, 0.0f };

        float yawRotation = NoClip_GetYawRotation();
        if (noclip_use_yaw_rotation_bool) {
            float yawRadians = yawRotation * (PI / 180.0f); // Convert degrees to radians
            camForward = { -sin(yawRadians), cos(yawRadians), 0.0f };
            camRight = { camForward.y, -camForward.x, 0.0f };
        }

        Vector3 movement = { 0.0f, 0.0f, 0.0f };

        // Handle forward/backward movement
        if (PAD::IS_CONTROL_PRESSED(0, INPUT_MOVE_UP_ONLY)) {
            movement.x += camForward.x * currentSpeed;
            movement.y += camForward.y * currentSpeed;
        }

        if (PAD::IS_CONTROL_PRESSED(0, INPUT_MOVE_DOWN_ONLY)) {
            movement.x -= camForward.x * currentSpeed;
            movement.y -= camForward.y * currentSpeed;
        }

        // Handle left/right movement
        if (PAD::IS_CONTROL_PRESSED(0, INPUT_MOVE_LEFT_ONLY)) {
            movement.x -= camRight.x * currentSpeed;
            movement.y -= camRight.y * currentSpeed;
        }

        if (PAD::IS_CONTROL_PRESSED(0, INPUT_MOVE_RIGHT_ONLY)) {
            movement.x += camRight.x * currentSpeed;
            movement.y += camRight.y * currentSpeed;
        }

        // Handle upward (Sprint) and downward (Duck) movement
        if (PAD::IS_CONTROL_PRESSED(0, INPUT_SPRINT)) {
            movement.z += currentSpeed; // Straight up
        }

        if (PAD::IS_CONTROL_PRESSED(0, INPUT_DUCK)) {
            movement.z -= currentSpeed; // Straight down
        }

        // Apply the movement to the current position
        currentPosition.x += movement.x;
        currentPosition.y += movement.y;
        currentPosition.z += movement.z;

        // Set the new position
        ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, currentPosition.x, currentPosition.y, currentPosition.z, false, false, false);

        // Update mount and vehicle positions (if any)
        if (mount != NULL) {
            Vector3 mountPosition = ENTITY::GET_ENTITY_COORDS(mount, true, false);
            mountPosition.x += movement.x;
            mountPosition.y += movement.y;
            mountPosition.z += movement.z;

            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(mount, mountPosition.x, mountPosition.y, mountPosition.z, false, false, false);
        }

        if (vehicle != NULL) {
            Vector3 vehiclePosition = ENTITY::GET_ENTITY_COORDS(vehicle, true, false);
            vehiclePosition.x += movement.x;
            vehiclePosition.y += movement.y;
            vehiclePosition.z += movement.z;

            ENTITY::SET_ENTITY_COORDS_NO_OFFSET(vehicle, vehiclePosition.x, vehiclePosition.y, vehiclePosition.z, false, false, false);
        }

    }
    else {
        if (initialized) {
            ENTITY::SET_ENTITY_COLLISION(playerPed, true, true);
            if (mount != NULL) {
                ENTITY::SET_ENTITY_COLLISION(mount, true, true);
                ENTITY::FREEZE_ENTITY_POSITION(mount, false); 
            }
            if (vehicle != NULL) {
                ENTITY::SET_ENTITY_COLLISION(vehicle, true, true);
                ENTITY::FREEZE_ENTITY_POSITION(vehicle, false); 
            }
            ENTITY::FREEZE_ENTITY_POSITION(playerPed, false);
            PHYSICS::ACTIVATE_PHYSICS(playerPed);
            TASK::CLEAR_PED_TASKS_IMMEDIATELY(playerPed, true, true);
            initialized = false;
        }
    }
}

void NoClip_UseYawRotationFunction() {
    Entity entity = PLAYER::PLAYER_PED_ID();

    if (noclip_no_clip_bool) {
        if (noclip_use_yaw_rotation_bool) {
            float yawRotation = NoClip_GetYawRotation();
            ENTITY::SET_ENTITY_HEADING(entity, yawRotation);
        }
        else {
            ENTITY::SET_ENTITY_HEADING(entity, ENTITY::GET_ENTITY_HEADING(entity));
        }
    }
}

void NoClip_FreezeEntityFunction() {
    Entity playerPed = PLAYER::PLAYER_PED_ID();
    Entity mount = PED::IS_PED_ON_MOUNT(playerPed) ? PED::GET_MOUNT(playerPed) : NULL;
    Entity vehicle = PED::IS_PED_IN_ANY_VEHICLE(playerPed, false) ? PED::GET_VEHICLE_PED_IS_IN(playerPed, false) : NULL;

    if (noclip_no_clip_bool) {
        if (noclip_freeze_entity_bool) {
            ENTITY::FREEZE_ENTITY_POSITION(playerPed, true);
        }
        else {
            ENTITY::FREEZE_ENTITY_POSITION(playerPed, false);
        }

        if (mount != NULL) {
            if (noclip_freeze_entity_bool) {
                ENTITY::FREEZE_ENTITY_POSITION(mount, true);
            }
            else {
                ENTITY::FREEZE_ENTITY_POSITION(mount, false);
            }
        }

        if (vehicle != NULL) {
            if (noclip_freeze_entity_bool) {
                ENTITY::FREEZE_ENTITY_POSITION(vehicle, true);
            }
            else {
                ENTITY::FREEZE_ENTITY_POSITION(vehicle, false);
            }
        }
    }
}

void NoClip_NoClipSpeedFunction() {
    float currentSpeed = std::stof(noclipSpeed[noclipSpeedIndex]);
}