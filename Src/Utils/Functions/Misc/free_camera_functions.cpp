#include "free_camera_functions.h"
#include "../../../Menu/Base/Submenus/Main/Misc/free_camera.h" 
#include "../../Saving/States/Misc/free_camera_default_states.h" 

#include <cmath>

#ifndef PI
#define PI 3.14159265358979323846
#endif

template <typename T>
T clamp(T value, T min, T max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void FreeCamera_FreeCameraFunction() {
    static int freeCamHandle = 0;
    static Vector3 camPosition;
    static Vector3 camRotation;
    static bool initialized = false;
    static bool entityFrozen = false;
    static bool wasInvisible = false;

    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (freecamera_free_camera_bool) {
        if (!initialized) {
            freeCamHandle = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", true);
            camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
            camRotation = CAM::GET_GAMEPLAY_CAM_ROT(2);

            CAM::SET_CAM_COORD(freeCamHandle, camPosition.x, camPosition.y, camPosition.z);
            CAM::SET_CAM_ROT(freeCamHandle, camRotation.x, camRotation.y, camRotation.z, 2);
            CAM::SET_CAM_ACTIVE(freeCamHandle, true);
            CAM::RENDER_SCRIPT_CAMS(true, false, 0, true, true, 0);

            initialized = true;
        }

        if (freecamera_freeze_entity_bool) {
            if (!entityFrozen) {
                ENTITY::FREEZE_ENTITY_POSITION(playerPed, true);
                entityFrozen = true;
            }
        }
        else {
            if (entityFrozen) {
                ENTITY::FREEZE_ENTITY_POSITION(playerPed, false);
                entityFrozen = false;
            }
        }

        float moveSpeed = 0.3f;
        float mouseSensitivity = 4.0f;

        float mouseX = static_cast<float>(-PAD::GET_CONTROL_NORMAL(0, INPUT_LOOK_LR) * mouseSensitivity);
        float mouseY = static_cast<float>(-PAD::GET_CONTROL_NORMAL(0, INPUT_LOOK_UD) * mouseSensitivity);

        camRotation.x = clamp(camRotation.x + mouseY, -89.0f, 89.0f);

        if (freecamera_use_yaw_rotation_bool) {
            camRotation.z += mouseX;
        }

        float radiansZ = camRotation.z * (PI / 180.0f);
        float radiansX = camRotation.x * (PI / 180.0f);

        Vector3 forwardVector = {
            -sin(radiansZ) * cos(radiansX),
            cos(radiansZ) * cos(radiansX),
            sin(radiansX)
        };

        Vector3 rightVector = {
            forwardVector.y,
            -forwardVector.x,
            0.0f
        };

        Vector3 moveOffset = { 0.0f, 0.0f, 0.0f };

        if (PAD::IS_CONTROL_PRESSED(0, INPUT_MOVE_UP_ONLY)) {
            moveOffset.x += forwardVector.x * moveSpeed;
            moveOffset.y += forwardVector.y * moveSpeed;
            moveOffset.z += forwardVector.z * moveSpeed;
        }
        if (PAD::IS_CONTROL_PRESSED(0, INPUT_MOVE_DOWN_ONLY)) {
            moveOffset.x -= forwardVector.x * moveSpeed;
            moveOffset.y -= forwardVector.y * moveSpeed;
            moveOffset.z -= forwardVector.z * moveSpeed;
        }
        if (PAD::IS_CONTROL_PRESSED(0, INPUT_MOVE_LEFT_ONLY)) {
            moveOffset.x -= rightVector.x * moveSpeed;
            moveOffset.y -= rightVector.y * moveSpeed;
        }
        if (PAD::IS_CONTROL_PRESSED(0, INPUT_MOVE_RIGHT_ONLY)) {
            moveOffset.x += rightVector.x * moveSpeed;
            moveOffset.y += rightVector.y * moveSpeed;
        }
        if (PAD::IS_CONTROL_PRESSED(0, INPUT_SPRINT)) {
            moveOffset.z += moveSpeed;
        }
        if (PAD::IS_CONTROL_PRESSED(0, INPUT_DUCK)) {
            moveOffset.z -= moveSpeed;
        }

        camPosition.x += moveOffset.x;
        camPosition.y += moveOffset.y;
        camPosition.z += moveOffset.z;

        CAM::SET_CAM_COORD(freeCamHandle, camPosition.x, camPosition.y, camPosition.z);
        CAM::SET_CAM_ROT(freeCamHandle, camRotation.x, camRotation.y, camRotation.z, 2);

        if (freecamera_entity_invisibility_bool) {
            if (!wasInvisible) {
                ENTITY::SET_ENTITY_VISIBLE(playerPed, false);
                wasInvisible = true;
            }
        }
        else {
            if (wasInvisible) {
                ENTITY::SET_ENTITY_VISIBLE(playerPed, true);
                wasInvisible = false;
            }
        }

    }

    else {
        if (freeCamHandle != 0) {
            CAM::SET_CAM_ACTIVE(freeCamHandle, false);
            CAM::RENDER_SCRIPT_CAMS(false, false, 0, true, true, 0);
            CAM::DESTROY_CAM(freeCamHandle, false);

            freeCamHandle = 0;
            initialized = false;
        }

        if (entityFrozen) {
            ENTITY::FREEZE_ENTITY_POSITION(playerPed, false);
            entityFrozen = false;
        }

        if (wasInvisible) {
            ENTITY::SET_ENTITY_VISIBLE(playerPed, true);
            wasInvisible = false;
        }
    }
}

void FreeCamera_UseYawRotationFunction() {
    if (freecamera_use_yaw_rotation_bool) {
    }
}

void FreeCamera_FreezeEntityFunction() {
    if (freecamera_freeze_entity_bool) {

    }

}

void  FreeCamera_EntityInvisibilityFunction() {
    if (freecamera_entity_invisibility_bool) {

    }
}

void FreeCamera_SpeedFunction() {

}