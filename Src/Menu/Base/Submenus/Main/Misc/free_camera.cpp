#include "free_camera.h"
#include <functional>
#include "../../../../../Utils/Saving/States/Misc/free_camera_default_states.h"
#include "../../../../../Utils/Functions/Misc/free_camera_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CFreecameraSubmenu::eFreecameraSubmenuID Submenu_Freecamera = CFreecameraSubmenu::Submenu_Freecamera;
CFreecameraSubmenu* g_FreecameraSubmenu = nullptr;

void CFreecameraSubmenu::Init()
{
    const int submenuPriority = 8;

    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Misc > Free Camera" : "Free Camera";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_free_camera, submenuPriority, [](Submenu* sub) {
        sub->AddBoolOption("Free Camera", "W A S D To Move, Shift Up, Ctrl Down, Use Mouse.", &freecamera_free_camera_bool, [] {
            FreeCamera_FreeCameraFunction();
            });

        sub->AddBoolOption("Use Yaw Rotation", "Movement Is Based On Camera Rotation", &freecamera_use_yaw_rotation_bool, [] {
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
