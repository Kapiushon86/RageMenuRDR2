#include "no_clip.h"
#include <functional>
#include "../../../../../Utils/Saving/States/Player/no_clip_default_states.h"
#include "../../../../../Utils/Functions/Player/no_clip_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CNoclipSubmenu::eNoclipSubmenuID Submenu_Noclip = CNoclipSubmenu::Submenu_Noclip;
CNoclipSubmenu* g_NoclipSubmenu = nullptr;

void CNoclipSubmenu::Init()
{
    const int submenuPriority = 8;

    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > No Clip" : "No Clip";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_no_clip, submenuPriority, [](Submenu* sub) {
        sub->AddBoolOption("No Clip", "W A S D To Move, Shift Up, Ctrl Down, Use Mouse.", &noclip_no_clip_bool, [] {
            NoClip_NoClipFunction();
            });

        sub->AddBoolOption("Use Yaw Rotation", "Movement Is Based On Camera Rotation", &noclip_use_yaw_rotation_bool, [] {
            NoClip_UseYawRotationFunction();
            });

        sub->AddBoolOption("Freeze Entity", "", &noclip_freeze_entity_bool, [] {
            NoClip_FreezeEntityFunction();
            });

        // Optional: Un-comment the block for speed option if needed
        /*
        sub->AddVectorOption("Speed", "", noclipSpeed, [] {
            if (noclipSpeedIndex < noclipSpeed.size() - 1) {
                noclipSpeedIndex++;
            }
            else {
                noclipSpeedIndex = 0;
            }
            NoClip_NoClipSpeedFunction();
        });
        */
        });
}
