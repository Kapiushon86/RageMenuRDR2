#include "disables_update_features_loop.h"
#include "../disables_functions.h"   

void DisablesUpdateFeaturesLoop() {

	Disables_DisableHelpTextFunction();
	Disables_DisableLocationInfoFunction();
	Disables_DisableRadarWhenMenuOpenFunction();
	Disables_DisableHorseWhistlingFunction();

}
