#include "weather.h"
#include "../../../../../Utils/Saving/States/World/weather_default_states.h"
#include "../../../../../Utils/Functions/World/weather_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CWeatherSubmenu::eWeatherSubmenuID Submenu_Weather = CWeatherSubmenu::Submenu_Weather;
CWeatherSubmenu* g_WeatherSubmenu = nullptr;

const int submenuPriority = 8;

void CWeatherSubmenu::Init() {

    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > World > Weather" : "Weather";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_weather, submenuPriority, [](Submenu* sub) {

        sub->AddBoolOption("Freeze Weather", "", &weather_freeze_weather_bool, [] {
            Weather_FreezeWeatherFunction();
            });

        sub->AddBoolOption("Loop Weather", "", &weather_loop_weather_bool, [] {
            Weather_LoopWeatherFunction();
            });

        sub->AddBoolOption("Ground Snow", "Cover The Ground With Snow", &weather_ground_snow_bool, [] {
            Weather_GroundSnowFunction();
            });

       /* sub->AddBoolOption("Smooth Transition", "", &weather_smooth_transition_bool, [] {
            Weather_SmoothTransitionFunction();
            });
            */

        sub->AddRegularOption("Random Weather", "", [] {
            Weather_RandomWeatherFunction();
            });

        sub->AddEmptyOption("Presets");

        for (const auto& WeatherPreset : WeatherPresets) {
            const auto& [WeatherName, WeatherHash] = WeatherPreset;

            sub->AddRegularOption(WeatherName, "", [WeatherHash] {
                MISC::_SET_OVERRIDE_WEATHER(WeatherHash);
                });
        }
        });
}