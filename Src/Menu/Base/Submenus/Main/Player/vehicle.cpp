#include "vehicle.h"
#include "../../../../../Utils/Saving/States/Player/vehicle_default_states.h"
#include "../../../../../Utils/Functions/Player/vehicle_functions.h"

CVehicleSubmenu::eVehicleSubmenuID Submenu_Vehicle = CVehicleSubmenu::Submenu_Vehicle;
CVehicleSubmenu* g_VehicleSubmenu = nullptr;

void CVehicleSubmenu::Init() {
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Vehicle", Submenu_vehicle, submenuPriority, [](Submenu* sub) {

        sub->AddBoolOption("Invincibility", "", &vehicle_invincibility_bool, [=] {
            Vehicle_InvincibilityFunction();
            });

        sub->AddBoolOption("Invisibility", "", &vehicle_invisibility_bool, [=] {
            Vehicle_InvisibilityFunction();
            });

        sub->AddBoolOption("Disable Knock Off", "", &vehicle_disable_knock_off_bool, [=] {
            Vehicle_DisableKnockoffFunction();
            });

        /*sub->AddBoolOption("No Ragdoll", "", &vehicle_no_ragdoll_bool, [=] {
            Vehicle_NoRagdollFunction();
            });
            */

        sub->AddBoolOption("Always Clean", "", &vehicle_always_clean_bool, [=] {
            Vehicle_AlwaysCleanFunction();
            });

        sub->AddRegularOption("Clean", "", [] {
            Vehicle_CleanFunction();
            });

        sub->AddRegularOption("Fix", "", [] {
            Vehicle_FixFunction();
            });

        sub->AddRegularOption("Suicide", "", [] {
            Vehicle_SuicideFunction();
            });

        sub->AddRegularOption("Delete", "", [] {
            Vehicle_DeleteFunction();
            });

        });
}
