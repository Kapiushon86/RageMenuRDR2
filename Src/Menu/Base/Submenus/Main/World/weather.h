#pragma once
#include "../SubmenuInclude.h"

class CWeatherSubmenu
{
public:
    enum eWeatherSubmenuID
    {
        Submenu_Weather,
    };

public:
    void Init();
};

extern CWeatherSubmenu::eWeatherSubmenuID Submenu_Weather;
extern CWeatherSubmenu* g_WeatherSubmenu;
