#pragma once
#include "../SubmenuInclude.h"

class CNoclipSubmenu
{
public:
    enum eNoclipSubmenuID
    {
        Submenu_Noclip,
    };

public:
    void Init();
};

extern CNoclipSubmenu::eNoclipSubmenuID Submenu_Noclip;
extern CNoclipSubmenu* g_NoclipSubmenu;
