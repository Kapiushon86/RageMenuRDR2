#pragma once
#include "../SubmenuInclude.h"
#include <string>
#include <vector>

class CMiscSubmenu
{
public:
    enum eMiscSubmenuID
    {
        Submenu_Misc,
    };

public:
    void Init();
};

extern void PlayWavFile(const std::string& fileName);
extern std::vector<std::string> GetWavFilesInWavPlayerFolder();

extern CMiscSubmenu::eMiscSubmenuID Submenu_Misc;
extern CMiscSubmenu* g_MiscSubmenu;
