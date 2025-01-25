#include "bypasses.h"
#include "../../../../../Utils/Saving/States/Misc/bypasses_default_states.h"
#include "../../../../../Utils/Functions/Misc/bypasses_functions.h"

CBypassesSubmenu::eBypassesSubmenuID Submenu_Bypasses = CBypassesSubmenu::Submenu_Bypasses;
CBypassesSubmenu* g_BypassesSubmenu = nullptr;

const int submenuPriority = 8;

void CBypassesSubmenu::Init()
{
    g_Menu->AddSubmenu("RageMenu", "Main > Misc > Bypasses", Submenu_bypasses, submenuPriority, [](Submenu* sub)
        {
            sub->AddBoolOption("Guard Zones", "Enter Restricted Areas", &bypasses_guard_zones_bool, [] {
                Bypasses_GuardZonesFunction();
                });

        });
}
