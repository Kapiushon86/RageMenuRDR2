#include "mount_default_states.h"
#include <thread>

bool mount_apply_to_owned_mount = false;
bool mount_invincibility_bool = false;
bool mount_invisibility_bool = false;
bool mount_levitate_bool = false;
bool mount_infinite_stamina_bool = false;
bool mount_infinite_swim_bool = false;
bool mount_no_ragdoll_bool = false;
bool mount_fearless_bool = false;
bool mount_fire_hooves_bool = false;
bool mount_teleport_mount_whistle_bool = false;
bool mount_teleport_on_whistle_bool = false;
bool mount_always_show_cores_bool = false;
bool mount_always_clean_bool = false;

// Vectors 

std::vector<std::string> preferenceOptionVector = {
    "Owned", "Current"
};

int preferenceOptionIndex = 0;