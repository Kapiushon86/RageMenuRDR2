#pragma once
#include "../SubmenuInclude.h"

class CAddSubmenu
{
public:
    enum eAddSubmenuID
    {
        Submenu_Add,
    };

public:
    void Init();
};

extern CAddSubmenu::eAddSubmenuID Submenu_Add;
extern CAddSubmenu* g_AddSubmenu;
