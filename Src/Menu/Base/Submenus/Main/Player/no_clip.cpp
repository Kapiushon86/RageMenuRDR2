#include "no_clip.h"
#include <functional>
#include "../../../../../Utils/Saving/States/Player/no_clip_default_states.h"
#include "../../../../../Utils/Functions/Player/no_clip_functions.h"

CNoclipSubmenu::eNoclipSubmenuID Submenu_Noclip = CNoclipSubmenu::Submenu_Noclip;
CNoclipSubmenu* g_NoclipSubmenu = nullptr;

void CNoclipSubmenu::Init()
{
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "No Clip", Submenu_no_clip, submenuPriority, [](Submenu* sub)
        {

            sub->AddBoolOption("No Clip", "W A S D to move, Shift up, Ctrl down", &noclip_no_clip_bool, [] {
                NoClip_NoClipFunction();
                });

            sub->AddBoolOption("Use Yaw Rotation", "Updates Movement On Yaw Axis", &noclip_use_yaw_rotation_bool, [] {
                NoClip_UseYawRotationFunction();
                });

            sub->AddBoolOption("Freeze Entity", "", &noclip_freeze_entity_bool, [] {
                NoClip_FreezeEntityFunction();
                });

         /*  sub->AddVectorOption("Speed", "", noclipSpeed, [] {
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

