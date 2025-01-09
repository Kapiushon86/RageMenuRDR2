#include "free_camera.h"
#include <functional>
#include "../../../../../Utils/Saving/States/Misc/free_camera_default_states.h"
#include "../../../../../Utils/Functions/Misc/free_camera_functions.h"

CFreecameraSubmenu::eFreecameraSubmenuID Submenu_Freecamera = CFreecameraSubmenu::Submenu_Freecamera;
CFreecameraSubmenu* g_FreecameraSubmenu = nullptr;

void CFreecameraSubmenu::Init()
{
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Free Camera", Submenu_free_camera, submenuPriority, [](Submenu* sub)
        {

            sub->AddBoolOption("Free Camera", "W A S D to move, Shift up, Ctrl down", &freecamera_free_camera_bool, [] {
                FreeCamera_FreeCameraFunction();
                });

            sub->AddBoolOption("Use Yaw Rotation", "Updates Movement On Yaw Axis", &freecamera_use_yaw_rotation_bool, [] {
                FreeCamera_UseYawRotationFunction();
                });

            sub->AddBoolOption("Freeze Entity", "", &freecamera_freeze_entity_bool, [] {
                FreeCamera_FreezeEntityFunction();
                });

            sub->AddBoolOption("Entity Invisibility", "", &freecamera_entity_invisibility_bool, [] {
                FreeCamera_EntityInvisibilityFunction();
                });

            /*sub->AddVectorOption("Speed", "", freeCamSpeedOptions, [] {
                if (freeCamSpeedIndex < freeCamSpeedOptions.size() - 1) {
                    freeCamSpeedIndex++;
                }
                else {
                    freeCamSpeedIndex = 0;
                }
                FreeCamera_SpeedFunction();
                });
                */

        });
}

