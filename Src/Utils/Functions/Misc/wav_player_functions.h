#ifndef WAV_PLAYER_FUNCTIONS_H
#define WAV_PLAYER_FUNCTIONS_H

#include <string>
#include <vector>
#include "../../../Utils/Config/config.h"
#include <filesystem>
#include <mutex>

extern std::vector<std::string> wavFiles;
extern std::mutex playMutex; 

void WavPlayer_loopFunction();
void WavPlayer_SetVolumeFunction();
void WavPlayer_PauseFunction();
void WavPlayer_ResumeFunction();
void WavPlayer_StopFunction();
void WavPlayer_RefreshFunction();

std::string GetRootFolderPathFromMisc();
std::vector<std::string> GetWavFilesInWavPlayerFolder();

void PlayWavFileMCI(const std::string& fileName);

#endif
