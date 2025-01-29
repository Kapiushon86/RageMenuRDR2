#include "weapons.h"
#include "../../../../../Utils/Saving/States/Weapons/weapons_default_states.h"
#include "../../../../../Utils/Functions/Weapons/weapon_functions.h"
#include "../../../../../Utils/Saving/States/Settings/settings_default_states.h"

CWeaponsSubmenu::eWeaponsSubmenuID Submenu_Weapons = CWeaponsSubmenu::Submenu_Weapons;
CWeaponsSubmenu* g_WeaponsSubmenu = nullptr;

void CWeaponsSubmenu::Init()
{
    const int submenuPriority = 8;

    std::string menuTitle = settings_show_bread_crumbs_bool ? "Main > Weapons" : "Weapons";

    g_Menu->AddSubmenu("RageMenu", menuTitle, Submenu_weapons, submenuPriority, [](Submenu* sub) {

        sub->AddRegularOption("Unlock All Weapons", "", [] {
            Weapon_UnlockAllFunction();
            });

        sub->AddRegularOption("Lock All Weapons", "", [] {
            Weapon_LockAllFunction();
            });

        sub->AddRegularOption("Add All Weapons", "Weapons Need To Be Unlocked In Order For You To Obtain.", [] {
            Weapon_AddAllWeaponsFunction();
            });


        sub->AddRegularOption("Remove All Weapons", "", [] {
            Weapon_RemoveAllWeaponsFunction();
            });

        sub->AddRegularOption("Add All Ammo", "Adds Max Ammo Of Each Type.", [] {
            Weapon_AddAllAmmoFunction();
            });

        sub->AddEmptyOption("Settings");

        sub->AddBoolOption("Infinite Ammo", "", &weapon_infinite_ammo_bool, [] {
            Weapon_InfiniteAmmoFunction();
            });

        sub->AddBoolOption("Infinite Clip", "", &weapon_infinite_clip_bool, [] {
            Weapon_InfiniteClipFunction();
            });

        sub->AddBoolOption("Rapid Fire", "", &weapon_rapid_fire_bool, [] {
            Weapon_RapidFireFunction();
            });

        sub->AddBoolOption("One Shot Kill", "", &weapon_one_shot_kill_bool, [] {
            Weapon_OneShotKillFunction();
            });

        sub->AddBoolOption("Auto Cock", "", &weapon_auto_cock_bool, [] {
            Weapon_AutoCockFunction();
            });

        sub->AddBoolOption("No Spread", "", &weapon_no_spread_bool, [] {
            Weapon_NoSpreadFunction();
            });

        sub->AddBoolOption("No Weapon Wheel Slow Down", "", &weapon_no_weapon_wheel_slow_down_bool, [] {
            Weapon_NoWeaponWheelSlowDownFunction();
            });

         /*sub->AddBoolOption("Always Kill Cam", "", &weapon_always_kill_cam_bool, [] {
            Weapon_AlwaysKillCamFunction();
            });
            */

       /* sub->AddBoolOption("Bleed Out", "", &weapon_bleed_out_bool, [] {
            Weapon_BleedOutFunction();
            });
            */

    /*    sub->AddBoolOption("Revive", "", &weapon_revive_bool, [] {
            Weapon_ReviveFunction();
            });
            */

        sub->AddBoolOption("Always Clean", "", &weapon_always_clean_bool, [] {
            Weapon_AlwaysCleanFunction();
            });

        sub->AddRegularOption("Clean", "", [] {
            Weapon_CleanFunction();
            });

        });
}
