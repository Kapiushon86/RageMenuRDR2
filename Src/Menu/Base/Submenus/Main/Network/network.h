#pragma once
#include "../SubmenuInclude.h"

class CNetworkSubmenu
{
public:
    enum NetworkSubmenuID
    {
        Submenu_Network,
    };

public:
    void Init();
};

extern CNetworkSubmenu::NetworkSubmenuID Submenu_Network;
extern CNetworkSubmenu* g_NetworkSubmenu;
