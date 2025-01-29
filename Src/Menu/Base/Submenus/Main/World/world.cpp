#include "World.h"
#include "Time.h"
#include "weather.h"
#include "../../../../../Utils/Saving/States/World/world_default_states.h"
#include "../../../../../Utils/Functions/World/world_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CWorldSubmenu::eWorldSubmenuID Submenu_World = CWorldSubmenu::Submenu_World;
CWorldSubmenu* g_WorldSubmenu = nullptr;

void CWorldSubmenu::Init() {
    const int submenuPriority = 8;


    g_TimeSubmenu = new CTimeSubmenu();
    g_TimeSubmenu->Init();

    g_WeatherSubmenu = new CWeatherSubmenu();
    g_WeatherSubmenu->Init();


    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > World" : "World";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_world, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Time", "", Submenu_time); 

        sub->AddSubmenuOption("Weather", "", Submenu_weather);


        });
}
