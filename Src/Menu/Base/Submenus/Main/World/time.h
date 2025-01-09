#pragma once
#include "../SubmenuInclude.h"

class CTimeSubmenu
{
public:
    enum eTimeSubmenuID
    {
        Submenu_Time, 
    };

public:
    void Init();
};

extern CTimeSubmenu::eTimeSubmenuID Submenu_Time; 
extern CTimeSubmenu* g_TimeSubmenu;
