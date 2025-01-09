#include "bypasses_functions.h"
#include "../../../Menu/Base/Submenus/Main/Misc/bypasses.h" 
#include "../../Saving/States/Misc/bypasses_default_states.h" 

const char* GuardZonesLocations[] = {
    "ANNESBURG_MINES", "ANNESBURG_FACTORY", "CALIGA_HALL", "BUTCHER_CREEK", "CARMODY_DELL", "TWIN_ROCKS",
    "CORNWALL_KEROSENE", "GUTHRIE_FARM", "DAIRY_FARM", "DOWNS_RANCH", "GRANGERS_HOGGERY", "OLD_FORT_WALLACE",
    "LARNED_SOD", "MACFARLANES_RANCH", "MACLEANS_RANCH", "ORANGE_PLANTATION", "PAINTED_SKY", "RATHSKELLER_FORK",
    "BRONTE", "SCARLET_HORSE_SHOP_OUTSIDE_PENS", "BRAITHWAITE_MANOR", "SISIKA"
};

void Bypasses_GuardZonesFunction() {
    if (bypasses_guard_zones_bool) {
        for (const char* GuardZoneLocation : GuardZonesLocations) {
            LAW::_DISABLE_GUARD_ZONE(GuardZoneLocation);
            LAW::_REMOVE_GUARD_ZONE(GuardZoneLocation);
        }
    }
    else {

    }
}
