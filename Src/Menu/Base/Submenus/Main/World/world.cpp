#include "World.h"
#include "Time.h"
#include "weather.h"
#include "../../../../../Utils/Saving/States/World/world_default_states.h"
#include "../../../../../Utils/Functions/World/world_functions.h"

CWorldSubmenu::eWorldSubmenuID Submenu_World = CWorldSubmenu::Submenu_World;
CWorldSubmenu* g_WorldSubmenu = nullptr;

void CWorldSubmenu::Init() {
    const int submenuPriority = 8;


    g_TimeSubmenu = new CTimeSubmenu();
    g_TimeSubmenu->Init();

    g_WeatherSubmenu = new CWeatherSubmenu();
    g_WeatherSubmenu->Init();



    g_Menu->AddSubmenu("RageMenu", "World", Submenu_world, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Time", "", Submenu_time); 

        sub->AddSubmenuOption("Weather", "", Submenu_weather);


        });
}
