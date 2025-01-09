#include "effects.h"
#include "../../../../../Utils/Saving/States/Player/effects_default_states.h"
#include "../../../../../Utils/Functions/Player/effects_functions.h"

CEffectsSubmenu::eEffectsSubmenuID Submenu_Effects = CEffectsSubmenu::Submenu_Effects;
CEffectsSubmenu* g_EffectsSubmenu = nullptr;

void CEffectsSubmenu::Init() {
    const int submenuPriority = 8;







    g_Menu->AddSubmenu("RageMenu", "Effects", Submenu_effects, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Screen", "", Submenu_effects_screen);

        sub->AddSubmenuOption("Particles", "", Submenu_effects_particles);

        });
}
