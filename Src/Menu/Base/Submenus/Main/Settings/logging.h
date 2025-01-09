#pragma once
#pragma once

#include "../SubmenuInclude.h"

class CLoggingSubmenu
{
public:
    enum eLoggingSubmenuID
    {
        Submenu_Logging,
    };

public:

    void Init();
};

extern CLoggingSubmenu::eLoggingSubmenuID Submenu_Logging;
extern CLoggingSubmenu* g_LoggingSubmenu;


