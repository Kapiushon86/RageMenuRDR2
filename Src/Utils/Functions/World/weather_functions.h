#ifndef WEATHER_FUNCTIONS_H
#define WEATHER_FUNCTIONS_H

#include <vector>
#include <tuple>
#include <string>

using Hash = uint32_t;  

void Weather_FreezeWeatherFunction();
void Weather_LoopWeatherFunction();
void Weather_GroundSnowFunction();
void Weather_RandomWeatherFunction();

extern std::vector<std::tuple<std::string, Hash>> WeatherPresets;

#endif
