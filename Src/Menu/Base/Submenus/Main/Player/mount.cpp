#include "mount.h"
#include <functional>
#include "../../../../../Utils/Saving/States/Player/mount_default_states.h"
#include "../../../../../Utils/Functions/Player/mount_functions.h"

CMountSubmenu::eMountSubmenuID Submenu_Mount = CMountSubmenu::Submenu_Mount;
CMountSubmenu* g_MountSubmenu = nullptr;

void CMountSubmenu::Init()
{
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Mount", Submenu_mount, submenuPriority, [](Submenu* sub)
        {

            sub->AddVectorOption("Preference", "", preferenceOptionVector, [] {
                if (preferenceOptionIndex < preferenceOptionVector.size() - 1) {
                    preferenceOptionIndex++;
                }
                else {
                    preferenceOptionIndex = 0;
                }
                std::string preferenceString = preferenceOptionVector[preferenceOptionIndex];
                MountTarget preference = StringToMountTargetEnum(preferenceString);
                Mount_PreferenceFunction(preference);
                });

            sub->AddEmptyOption("Settings");

            sub->AddBoolOption("Invincibility", "", &mount_invincibility_bool, [=] {
                Mount_InvincibilityFunction();
                });

            sub->AddBoolOption("Invisibility", "", &mount_invisibility_bool, [=] {
                Mount_InvisibilityFunction();
                });

           sub->AddBoolOption("Infinite Stamina", "", &mount_infinite_stamina_bool, [=] {
                Mount_InfiniteStaminaFunction();
                });

           sub->AddRegularOption("Refill All Cores", "", [] {
               Mount_RefillAllCoresFunction();
               });

           sub->AddRegularOption("Refill Health Core", "", [] {
               Mount_RefillHealthCoreFunction();
               });

           sub->AddRegularOption("Refill Stamina Core", "", [] {
               Mount_RefillStaminaCoreFunction();
               });
                
           sub->AddBoolOption("Fearless", "", &mount_fearless_bool, [=] {
               Mount_FearlessFunction();
               });

            sub->AddBoolOption("No Ragdoll", "", &mount_no_ragdoll_bool, [=] {
                Mount_NoRagdollFunction();
                });

            /*sub->AddBoolOption("Fire Hooves", "", &mount_fire_hooves_bool, [=] {
                Mount_FireHoovesFunction();
                });
                */
                
           /* sub->AddBoolOption("Teleport Mount Whistle", "", &mount_teleport_mount_whistle_bool, [=] {
                Mount_TeleportMountWhistleFunction();
                });

            sub->AddRegularOption("Max Bonding", "", [] {
                Mount_MaxBondingFunction();
                });

                */

            sub->AddBoolOption("Always Show Cores", "", &mount_always_show_cores_bool, [] {
                Mount_AlwaysShowCoresFunction();
                });

            sub->AddBoolOption("Always Clean", "", &mount_always_clean_bool, [=] {
                Mount_AlwaysCleanFunction();
                });

            sub->AddRegularOption("Clean", "", [] {
                Mount_CleanFunction();
                });

            sub->AddRegularOption("Clear Pelts", "", [] {
                Mount_ClearPeltsFunction();
                });

           /* sub->AddRegularOption("Fix", "", [] {
                Mount_FixFunction();
                });
                */

            sub->AddRegularOption("Suicide", "", [] {
                Mount_SuicideFunction();
                });

            sub->AddRegularOption("Delete", "", [] {
                Mount_DeleteFunction();
                });
                
        });
}
