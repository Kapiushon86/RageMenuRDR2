#pragma once

#include "../SubmenuInclude.h"

class CThemesSubmenu
{
public:
    enum eThemesSubmenuID
    {
        Submenu_Themes,
    };

public:

    void Init();
};

extern CThemesSubmenu::eThemesSubmenuID Submenu_Themes;
extern CThemesSubmenu* g_ThemesSubmenu;


