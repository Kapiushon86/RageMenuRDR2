#pragma once

#include "../SubmenuInclude.h"

class CEffects_ParticlesSubmenu
{
public:
    enum eEffects_ParticlesSubmenuID
    {
        Submenu_Effects_Particles,
    };

public:
    void Init();
};

extern CEffects_ParticlesSubmenu::eEffects_ParticlesSubmenuID Submenu_Effects_Particles;
extern CEffects_ParticlesSubmenu* g_Effects_ParticlesSubmenu;
