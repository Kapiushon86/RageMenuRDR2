#include "time_update_features_loop.h"
#include "../time_functions.h"   

void TimeUpdateFeaturesLoop() {

	Time_FreezeTimeFunction();
	Time_LoopTimeFunction();
	Time_SyncWithSystemFunction();

}
