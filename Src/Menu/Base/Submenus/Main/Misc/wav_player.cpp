#include "wav_player.h"
#include "../../../../../Utils/Saving/States/Misc/wav_player_default_states.h"
#include "../../../../../Utils/Functions/Misc/wav_player_functions.h"

CWav_PlayerSubmenu::eWav_PlayerSubmenuID Submenu_Wav_Player = CWav_PlayerSubmenu::Submenu_Wav_Player;
CWav_PlayerSubmenu* g_Wav_PlayerSubmenu = nullptr;

const int submenuPriority = 8;
const size_t maxFileNameLength = 25;

void CWav_PlayerSubmenu::Init()
{
    g_Menu->AddSubmenu("RageMenu", "Wav Player", Submenu_wav_player, submenuPriority, [](Submenu* sub)
        {
          /*  sub->AddBoolOption("Loop", "", &wavplayer_loop_bool_value, [] {
                WavPlayer_loopFunction();
                });
                */

            /* sub->AddVectorOption("Volume", "", volumeOptionVector, [] {
                 if (volumeOptionIndex < volumeOptionVector.size() - 1) {
                     volumeOptionIndex++;
                 }
                 else {
                     volumeOptionIndex = 0;
                 }

                 WavPlayer_SetVolumeFunction();
                 });
                 */


           /* sub->AddRegularOption("Pause", "", [] {
                WavPlayer_PauseFunction();
                });

            sub->AddRegularOption("Resume", "", [] {
                WavPlayer_ResumeFunction();
                });
                */

            sub->AddRegularOption("Stop", "", [] {
                WavPlayer_StopFunction();
                });

            /*sub->AddRegularOption("Refresh", "", [] {
                WavPlayer_RefreshFunction();
                });
                */

            sub->AddEmptyOption("Wav Files");

            WavPlayer_RefreshFunction();

            if (wavFiles.empty()) {
                sub->AddRegularOption("~COLOR_RED~No \".Wav\" files found.", "", [] {});
            }
            else {
                for (const auto& fileName : wavFiles) {
                    std::string displayName = fileName.substr(0, fileName.find_last_of('.'));
                    size_t displayNameLength = displayName.length();

                    if (displayNameLength > maxFileNameLength) {
                        std::string message = "\"" + displayName + "\" is " + std::to_string(displayNameLength) + " characters long. Max is " + std::to_string(maxFileNameLength) + " characters.";
                        sub->AddRegularOption("~COLOR_RED~" + message, "", [] {});
                    }
                    else {
                        sub->AddRegularOption(displayName.c_str(), "", [fileName] {
                            try {
                                PlayWavFileMCI(fileName);
                            }
                            catch (const std::exception& e) {
                                std::cerr << "Error: " << e.what() << std::endl;
                            }
                            });
                    }
                }
            }
        });
}
