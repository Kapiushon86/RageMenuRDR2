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

SC_PROFANITY_CHECK_STRING_FUNC SC_PROFANITY_CHECK_STRING = nullptr;
SC_PROFANITY_GET_CHECK_IS_VALID_FUNC SC_PROFANITY_GET_CHECK_IS_VALID = nullptr;
SC_PROFANITY_GET_CHECK_IS_PENDING_FUNC SC_PROFANITY_GET_CHECK_IS_PENDING = nullptr;
SC_PROFANITY_GET_STRING_PASSED_FUNC SC_PROFANITY_GET_STRING_PASSED = nullptr;
SC_PROFANITY_GET_STRING_STATUS_FUNC SC_PROFANITY_GET_STRING_STATUS = nullptr;

void Bypasses_ProfanityCheckFunction() {
    if (bypasses_profanity_check_bool) {
        SC_PROFANITY_CHECK_STRING = [](const char* string, int* token) -> BOOL {
            return TRUE;
            };

        SC_PROFANITY_GET_CHECK_IS_VALID = [](int token) -> BOOL {
            return TRUE;
            };

        SC_PROFANITY_GET_CHECK_IS_PENDING = [](int token) -> BOOL {
            return FALSE;
            };

        SC_PROFANITY_GET_STRING_PASSED = [](int token) -> BOOL {
            return TRUE;
            };

        SC_PROFANITY_GET_STRING_STATUS = [](int token) -> int {
            return 1;
            };

    }
}