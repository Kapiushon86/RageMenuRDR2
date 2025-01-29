#include "weather_functions.h"
#include "../../../Menu/Base/Submenus/Main/World/weather.h"
#include "../../Saving/States/World/weather_default_states.h"
#include <thread>
#include <random>
#include <chrono>
#include <iostream>
#include <vector>
#include <tuple>

std::vector<std::tuple<std::string, Hash>> WeatherPresets = {
    // Sunny Weather
    {"Sunny", 0x614A1F91},
    {"Clouds", 0x30FDAF5C},
    {"Misty", 0x5974E8E5},
    {"Highpressure", 0xF5A87B65},

    // Rainy Weather
    {"Drizzle", 0x995C7F44},
    {"Rain", 0x54A69840},
    {"Shower", 0xE72679D5},
    {"Hail", 0x75A9E268},

    // Thunderstorms
    {"Thunder", 0xB677829F},
    {"Thunderstorm", 0x7C1C4A13},

    // Snowy Weather
    {"Blizzard", 0x27EA2814},
    {"Groundblizzard", 0x7F622122},
    {"Snow", 0xEFB6EFF6},
    {"Snowlight", 0x23FB812B},
    {"Sleet", 0x0CA71D7C},
    {"Whiteout", 0x2B402288},
    {"Snowclearing", 0x641DFC11},

    // Overcast Weather
    {"Fog", 0xD61BDE01},
    {"Overcast", 0xBB898D2D},
    {"Overcastdark", 0x19D4F1D9},

    // Extreme Weather
    {"Hurricane", 0x320D0951},
    {"Sandstorm", 0xB17F6111}
};

static size_t lastRandomWeatherIndex = -1;
static size_t WeatherPresetsIndex = 0;
static std::chrono::time_point<std::chrono::steady_clock> lastWeatherUpdateTime;
static const std::chrono::seconds weatherInterval(1);

static Hash frozenWeatherType1 = 0;
static Hash frozenWeatherType2 = 0;
static float frozenWeatherPercent2 = 0;

void Weather_FreezeWeatherFunction() {
    if (weather_freeze_weather_bool) {
        if (frozenWeatherType1 == 0) {
            MISC::GET_CURR_WEATHER_STATE(&frozenWeatherType1, &frozenWeatherType2, &frozenWeatherPercent2);
        }
        MISC::_SET_OVERRIDE_WEATHER(frozenWeatherType1);
    }
}

void Weather_LoopWeatherFunction() {
    if (weather_loop_weather_bool && !weather_freeze_weather_bool) {
        auto currentWeatherTime = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(currentWeatherTime - lastWeatherUpdateTime) >= weatherInterval) {
            const auto& weatherPreset = WeatherPresets[WeatherPresetsIndex];
            const auto& [WeatherName, WeatherHash] = weatherPreset;
            MISC::_SET_OVERRIDE_WEATHER(WeatherHash);
            WeatherPresetsIndex = (WeatherPresetsIndex + 1) % WeatherPresets.size();
            lastWeatherUpdateTime = currentWeatherTime;
        }
    }
}

void Weather_GroundSnowFunction() {
    if (weather_ground_snow_bool != lastGroundSnowState) {
        if (weather_ground_snow_bool) {
            GRAPHICS::_SET_SNOW_COVERAGE_TYPE(3);
            MISC::_SET_SNOW_LEVEL(10.0f);
        }
        else {
            GRAPHICS::_SET_SNOW_COVERAGE_TYPE(0);
            MISC::_SET_SNOW_LEVEL(0.0f);
        }
        lastGroundSnowState = weather_ground_snow_bool;
    }
}

void  Weather_SmoothTransitionFunction() {
    if (weather_smooth_transition_bool) {

    }
}

void Weather_RandomWeatherFunction() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, static_cast<int>(WeatherPresets.size()) - 1);

    size_t newWeatherIndex;
    do {
        newWeatherIndex = dis(gen);
    } while (newWeatherIndex == lastRandomWeatherIndex);

    lastRandomWeatherIndex = newWeatherIndex;

    const auto& weatherPreset = WeatherPresets[newWeatherIndex];
    const auto& [WeatherName, WeatherHash] = weatherPreset;

    if (!weather_freeze_weather_bool) {
        MISC::_SET_OVERRIDE_WEATHER(WeatherHash);
    }
}
