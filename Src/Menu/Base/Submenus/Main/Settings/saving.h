#pragma once
#pragma once

#include "../SubmenuInclude.h"

class CSavingSubmenu
{
public:
    enum eSavingSubmenuID
    {
        Submenu_Saving,
    };

public:

    void Init();
};

extern CSavingSubmenu::eSavingSubmenuID Submenu_Saving;
extern CSavingSubmenu* g_SavingSubmenu;


