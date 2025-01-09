#pragma once

#include "../SubmenuInclude.h"

class CRagemenuSubmenu
{
public:
    enum eRagemenuSubmenuID
    {
        Submenu_Ragemenu,
    };

public:
    void Init();
};

extern CRagemenuSubmenu::eRagemenuSubmenuID Submenu_Ragemenu;
extern CRagemenuSubmenu* g_RagemenuSubmenu;
