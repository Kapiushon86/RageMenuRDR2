#pragma once
#include "../SubmenuInclude.h"

class CLinksSubmenu
{
public:
    enum eLinksSubmenuID
    {
        Submenu_Links,
    };

public:
    void Init();
};

extern CLinksSubmenu::eLinksSubmenuID Submenu_Links;
extern CLinksSubmenu* g_LinksSubmenu;
