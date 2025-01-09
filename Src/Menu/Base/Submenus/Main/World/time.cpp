#include "time.h"
#include "../../../../../Utils/Saving/States/World/time_default_states.h"
#include "../../../../../Utils/Functions/World/time_functions.h"

CTimeSubmenu::eTimeSubmenuID Submenu_Time = CTimeSubmenu::Submenu_Time;
CTimeSubmenu* g_TimeSubmenu = nullptr;

const int submenuPriority = 8;

void CTimeSubmenu::Init() {
    g_Menu->AddSubmenu("RageMenu", "Time", Submenu_time, submenuPriority, [](Submenu* sub) {

        sub->AddBoolOption("Freeze Time", "", &time_freeze_time_bool, [] {
            Time_FreezeTimeFunction();
            });

        sub->AddBoolOption("Loop Time", "", &time_loop_time_bool, [] {
            Time_LoopTimeFunction();
            });

        sub->AddBoolOption("Sync With System", "", &time_sync_with_system_bool, [] {
            Time_SyncWithSystemFunction();
            });

        sub->AddRegularOption("Random Time", "", [] {
            Time_RandomTimeFunction();
            });

        sub->AddEmptyOption("Presets");

        for (const auto& timePreset : TimePresets) {
            const auto& [timeName, hour, minute, second] = timePreset;

            sub->AddRegularOption(timeName, "", [hour, minute, second] {
                CLOCK::SET_CLOCK_TIME(hour, minute, second);
                });
        }
        });
}
