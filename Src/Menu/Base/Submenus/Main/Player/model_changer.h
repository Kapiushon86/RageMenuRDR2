#pragma once

#include "../SubmenuInclude.h"

class CModel_ChangerSubmenu
{
public:
    enum eModel_ChangerSubmenuID
    {
        Submenu_Model_Changer,
    };

public:
    void Init();
};

extern CModel_ChangerSubmenu::eModel_ChangerSubmenuID Submenu_Model_Changer;
extern CModel_ChangerSubmenu* g_Model_ChangerSubmenu;
