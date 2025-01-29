#include "themes.h"
#include "../../../../../Utils/Saving/States/Settings/themes_default_states.h"
#include "../../../../../Utils/Functions/Settings/themes_functions.h"

CThemesSubmenu::eThemesSubmenuID Submenu_Themes = CThemesSubmenu::Submenu_Themes;
CThemesSubmenu* g_ThemesSubmenu = nullptr;

void CThemesSubmenu::Init() {
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Main > Settings > Themes", Submenu_themes, submenuPriority, [](Submenu* sub) {

        });
}