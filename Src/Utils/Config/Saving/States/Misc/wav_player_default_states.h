#ifndef WAV_PLAYER_DEFAULT_STATES_H
#define WAV_PLAYER_DEFAULT_STATES_H

#include <vector>
#include <string>
#include <thread>
#include <atomic>

extern std::atomic<bool> wavplayer_loop_bool;

extern bool wavplayer_loop_bool_value;

// Vectors

extern int volumeOptionIndex;
extern std::vector<std::string> volumeOptionVector;

#endif
