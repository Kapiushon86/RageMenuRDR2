#pragma once
#include "../SubmenuInclude.h"

class CMountSubmenu
{
public:
    enum eMountSubmenuID
    {
        Submenu_Mount,
    };

public:
    void Init();
};

extern CMountSubmenu::eMountSubmenuID Submenu_Mount;
extern CMountSubmenu* g_MountSubmenu;
