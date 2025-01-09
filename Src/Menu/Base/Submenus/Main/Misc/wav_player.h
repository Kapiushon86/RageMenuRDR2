#pragma once
#include "../SubmenuInclude.h"

class CWav_PlayerSubmenu
{
public:
    enum eWav_PlayerSubmenuID
    {
        Submenu_Wav_Player,
    };

public:
    void Init();
};

extern CWav_PlayerSubmenu::eWav_PlayerSubmenuID Submenu_WavPlayer;
extern CWav_PlayerSubmenu* g_Wav_PlayerSubmenu;
