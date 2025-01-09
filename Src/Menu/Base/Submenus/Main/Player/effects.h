#pragma once

#include "../SubmenuInclude.h"

class CEffectsSubmenu
{
public:
    enum eEffectsSubmenuID
    {
        Submenu_Effects,
    };

public:
    void Init();
};

extern CEffectsSubmenu::eEffectsSubmenuID Submenu_Effects;
extern CEffectsSubmenu* g_EffectsSubmenu;
