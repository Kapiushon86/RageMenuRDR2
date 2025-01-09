#pragma once

#include "../SubmenuInclude.h"

class CExamplesubSubmenu
{
public:
    enum eExamplesubSubmenuID
    {
        Submenu_Examplesub,
    };

public:
    void Init();
};

extern CExamplesubSubmenu::eExamplesubSubmenuID Submenu_Examplesub;
extern CExamplesubSubmenu* g_ExamplesubSubmenu;
