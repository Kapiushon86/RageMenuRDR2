#include "no_clip_default_states.h"

#include <thread>

bool noclip_no_clip_bool = false;
bool noclip_use_yaw_rotation_bool = false;
bool noclip_freeze_entity_bool = true;

std::vector<std::string> noclipSpeed = {
    "1.00", "2.00", "3.00", "4.00", "5.00", "6.00", "7.00", "8.00", "9.00",
    "10.00"
};

int noclipSpeedIndex = 0;
