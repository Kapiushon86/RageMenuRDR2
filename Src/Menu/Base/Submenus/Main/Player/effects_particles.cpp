#include "effects_particles.h"
#include "../../../../../Utils/Saving/States/Player/effects_particles_default_states.h"
#include "../../../../../Utils/Functions/Player/effects_particles_functions.h"

CEffects_ParticlesSubmenu::eEffects_ParticlesSubmenuID Submenu_Effects_Particles = CEffects_ParticlesSubmenu::Submenu_Effects_Particles;
CEffects_ParticlesSubmenu* g_Effects_ParticlesSubmenu = nullptr;

void CEffects_ParticlesSubmenu::Init() {
    const int submenuPriority = 8;







    g_Menu->AddSubmenu("RageMenu", "Particle Effects", Submenu_effects_particles, submenuPriority, [](Submenu* sub) {



        });
}
