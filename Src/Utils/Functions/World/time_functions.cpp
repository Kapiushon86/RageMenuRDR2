#include "time_functions.h"
#include "../../../Menu/Base/Submenus/Main/World/time.h"
#include "../../Saving/States/World/time_default_states.h"
#include <thread>
#include <random>
#include <chrono>
#include <iostream>

std::vector<std::tuple<std::string, int, int, int>> TimePresets = {
    {"Sunrise", 6, 0, 0},        // 6:00 AM
    {"Morning", 7, 30, 0},       // 7:30 AM
    {"Late Morning", 9, 0, 0},   // 9:00 AM
    {"Noon", 12, 0, 0},          // 12:00 PM
    {"Afternoon", 13, 30, 0},    // 1:30 PM
    {"Late Afternoon", 15, 30, 0}, // 3:30 PM
    {"Evening", 17, 30, 0},      // 5:30 PM
    {"Twilight", 19, 0, 0},      // 7:00 PM
    {"Sunset", 20, 30, 0},       // 8:30 PM
    {"Dusk", 21, 0, 0},          // 9:00 PM
    {"Night", 22, 0, 0},         // 10:00 PM
    {"Late Night", 23, 30, 0},   // 11:30 PM
    {"Midnight", 0, 0, 0},       // 12:00 AM
    {"Early Morning", 3, 30, 0}, // 3:30 AM
    {"Dawn", 5, 0, 0}            // 5:00 AM
};


// Static variables for state tracking
static int frozenHour = -1, frozenMinute = -1, frozenSecond = -1;
static size_t presetIndex = 0;
static std::chrono::time_point<std::chrono::steady_clock> lastUpdateTime = std::chrono::steady_clock::now();
static const std::chrono::seconds timeInterval(1);
static size_t lastRandomIndex = static_cast<size_t>(-1);

// Preinitialize random generator
static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> dis(0, static_cast<int>(TimePresets.size()) - 1);

void Time_FreezeTimeFunction() {
    if (time_freeze_time_bool) {
        if (frozenHour == -1) {
            frozenHour = CLOCK::GET_CLOCK_HOURS();
            frozenMinute = CLOCK::GET_CLOCK_MINUTES();
            frozenSecond = CLOCK::GET_CLOCK_SECONDS();
        }
        CLOCK::SET_CLOCK_TIME(frozenHour, frozenMinute, frozenSecond);
    }
}

void Time_LoopTimeFunction() {
    if (time_loop_time_bool && !time_freeze_time_bool) {
        auto currentTime = std::chrono::steady_clock::now();
        if (currentTime - lastUpdateTime >= timeInterval) {
            const auto& [timeName, hour, minute, second] = TimePresets[presetIndex];
            CLOCK::SET_CLOCK_TIME(hour, minute, second);
            presetIndex = (presetIndex + 1) % TimePresets.size(); 
            lastUpdateTime = currentTime;
        }
    }
}

void Time_SyncWithSystemFunction() {
    if (time_sync_with_system_bool) {
        std::time_t currentTime = std::time(nullptr);
        std::tm localTime;
        localtime_s(&localTime, &currentTime);

        CLOCK::SET_CLOCK_TIME(localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
    }
}

void Time_RandomTimeFunction() {
    if (!time_freeze_time_bool) {
        size_t newIndex;
        do {
            newIndex = dis(gen);
        } while (newIndex == lastRandomIndex);

        lastRandomIndex = newIndex;

        const auto& [timeName, hour, minute, second] = TimePresets[newIndex];
        CLOCK::SET_CLOCK_TIME(hour, minute, second);
    }
}
