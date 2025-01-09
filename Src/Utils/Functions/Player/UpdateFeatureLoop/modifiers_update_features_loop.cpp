#include "modifiers_update_features_loop.h"
#include "../modifiers_functions.h"  
#include "../../../Saving/States/Player/modifiers_default_states.h"

void ModifiersUpdateFeaturesLoop() {


    if (modifiers_infinite_stamina_bool || modifiers_was_infinite_stamina_bool)
    {
        Modifiers_InfiniteStaminaFunction();
    }

    if (modifiers_infinite_dead_eye_bool || modifiers_was_infinite_dead_eye_bool)
    {
        Modifiers_InfiniteDeadEyeFunction();
    }

    if (modifiers_infinite_eagle_eye_bool || modifiers_was_infinite_eagle_eye_bool)
    {
        Modifiers_InfiniteEagleEyeFunction();
    }

}
