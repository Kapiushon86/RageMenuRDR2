#pragma once

#include "../SubmenuInclude.h"

class CEffects_ScreenSubmenu
{
public:
    enum eEffects_ScreenID
    {
        Submenu_Effects_Screen,
    };

public:
    void Init();
};

extern CEffects_ScreenSubmenu::eEffects_ScreenID Submenu_Effects_Screen;
extern CEffects_ScreenSubmenu* g_Effects_ScreenSubmenu;
