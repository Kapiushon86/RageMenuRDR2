#include "weapon_update_features_loop.h"
#include "../weapon_functions.h"   

void WeaponsUpdateFeaturesLoop() {

    Weapon_InfiniteAmmoFunction();
    Weapon_InfiniteClipFunction();
    Weapon_RapidFireFunction();
    Weapon_OneShotKillFunction();
    Weapon_AutoCockFunction();
    Weapon_NoSpreadFunction();
    Weapon_NoWeaponWheelSlowDownFunction();
    Weapon_AlwaysKillCamFunction();
    Weapon_AlwaysCleanFunction();
}
