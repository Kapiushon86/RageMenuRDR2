#include "weather_update_features_loop.h"
#include "../weather_functions.h"   

void WeatherUpdateFeaturesLoop() {

	Weather_FreezeWeatherFunction();
	Weather_LoopWeatherFunction();
	Weather_GroundSnowFunction();

}
