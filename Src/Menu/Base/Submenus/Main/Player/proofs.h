#pragma once

#include "../SubmenuInclude.h"

class CProofsSubmenu
{
public:
    enum eProofsSubmenuID
    {
        Submenu_Proofs,
    };

public:
    void Init();
};

extern CProofsSubmenu::eProofsSubmenuID Submenu_Proofs;
extern CProofsSubmenu* g_ProofsSubmenu;
