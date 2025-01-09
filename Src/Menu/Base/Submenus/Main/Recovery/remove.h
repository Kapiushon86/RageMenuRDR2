#pragma once
#include "../SubmenuInclude.h"

class CRemoveSubmenu
{
public:
    enum eRemoveSubmenuID
    {
        Submenu_Remove,
    };

public:
    void Init();
};

extern CRemoveSubmenu::eRemoveSubmenuID Submenu_Remove;
extern CRemoveSubmenu* g_RemoveSubmenu;
