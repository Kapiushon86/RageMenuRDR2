#include "mount_update_features_loop.h" 
#include "../mount_functions.h"      
#include "../../../Saving/States/Player/mount_default_states.h"

void MountUpdateFeaturesLoop() {

    Mount_PreferenceFunction(mount_target_preference);
    Mount_FearlessFunction();
    Mount_AlwaysShowCoresFunction();
    Mount_AlwaysCleanFunction();

    if (mount_infinite_stamina_bool || mount_was_infinite_stamina_bool)
    {
        Mount_InfiniteStaminaFunction();
    }
}
