#include "misc_update_features_loop.h"
#include "../misc_functions.h"   
#include "../../Settings/settings_functions.h"

void MiscUpdateFeaturesLoop() {

	Misc_WelcomeMessageFunction();
	Misc_SeasonalGreetingsFunction();
	Misc_DiscordPresenceFunction();
	Misc_RealAltF4Function();
	Misc_FogOfWarFunction();
   
}
