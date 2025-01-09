#ifndef TIME_FUNCTIONS_H
#define TIME_FUNCTIONS_H

#include <vector>
#include <tuple>
#include <string>


void Time_FreezeTimeFunction();
void Time_LoopTimeFunction();
void Time_SyncWithSystemFunction();
void Time_RandomTimeFunction();

extern std::vector<std::tuple<std::string, int, int, int>> TimePresets;

#endif 
