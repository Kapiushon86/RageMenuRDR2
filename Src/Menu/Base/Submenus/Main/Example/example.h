#pragma once

#include "../SubmenuInclude.h"

class CExampleSubmenu
{
public:
    enum eExampleSubmenuID
    {
        Submenu_Example,
    };

public:
    void Init();
};

extern CExampleSubmenu::eExampleSubmenuID Submenu_Example;
extern CExampleSubmenu* g_ExampleSubmenu;
