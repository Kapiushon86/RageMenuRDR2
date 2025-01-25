#include "disables_update_features_loop.h"
#include "../disables_functions.h"   

void DisablesUpdateFeaturesLoop() {

	Disables_DisableAllHudFunction();
	Disables_DisableSimpleHudFunction();
	Disables_DisableHelpTextFunction();
	Disables_DisableLocationInfoFunction();
	Disables_DisableRadarWhenMenuOpenIsFunction();
	Disables_DisableHorseWhistleOnControllerFunction();

}
