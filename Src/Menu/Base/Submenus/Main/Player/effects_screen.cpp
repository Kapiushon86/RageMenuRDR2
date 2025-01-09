#include "effects_screen.h"
#include "../../../../../Utils/Saving/States/Player/effects_screen_default_states.h"
#include "../../../../../Utils/Functions/Player/effects_screen_functions.h"

CEffects_ScreenSubmenu::eEffects_ScreenID Submenu_Effects_Screen = CEffects_ScreenSubmenu::Submenu_Effects_Screen;
CEffects_ScreenSubmenu* g_Effects_ScreenSubmenu = nullptr;

void CEffects_ScreenSubmenu::Init() {
    const int submenuPriority = 8;







    g_Menu->AddSubmenu("RageMenu", "Screen Effects ", Submenu_effects_screen, submenuPriority, [](Submenu* sub) {



        });
}
