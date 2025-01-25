#include "free_camera_default_states.h"

#include <thread>
#include <vector>
#include <string>

bool freecamera_free_camera_bool = false;
bool freecamera_use_yaw_rotation_bool = true;
bool freecamera_freeze_entity_bool = true;
bool freecamera_entity_invisibility_bool = false;

std::vector<std::string> freeCamSpeedOptions = {
    "1.00", "2.00", "3.00", "4.00", "5.00", "6.00", "7.00", "8.00", "9.00",
    "10.00"
};

int freeCamSpeedIndex = 0;
