#pragma once

#include "../SubmenuInclude.h"

class CModelSubmenu
{
public:
    enum eModelSubmenuID
    {
        Submenu_Model,
    };

public:
    void Init();
};

extern CModelSubmenu::eModelSubmenuID Submenu_Model;
extern CModelSubmenu* g_ModelSubmenu;
