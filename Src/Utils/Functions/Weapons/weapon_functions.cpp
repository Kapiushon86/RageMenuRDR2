#include "weapon_functions.h"
#include "../../../Menu/Base/Submenus/Main/Weapons/weapons.h" 
#include "../../Saving/States/Weapons/weapons_default_states.h" 

std::vector<std::string> WeaponsList = {
    // ------------ Pistols ------------
    "WEAPON_PISTOL_VOLCANIC",    // Volcanic Pistol
    "WEAPON_PISTOL_MAUSER",      // Mauser Pistol
    "WEAPON_PISTOL_MAUSER_DRUNK", // Mauser Drunk Pistol
    "WEAPON_PISTOL_SEMIAUTO",    // Semi Auto Pistol
    "WEAPON_PISTOL_M1899",       // M1899 Pistol

    // ------------ Revolvers ------------
    "WEAPON_REVOLVER_CATTLEMAN",     // Cattleman Revolver
    "WEAPON_REVOLVER_CATTLEMAN_JOHN", // John CattleMan Revolver
    "WEAPON_REVOLVER_CATTLEMAN_MEXICAN", // Mexican Cattleman Revolver
    "WEAPON_REVOLVER_CATTLEMAN_PIG",  // Pig Cattleman Revolver
    "WEAPON_REVOLVER_DOUBLEACTION_MICAH", // Micah's Double Action Revolver
    "WEAPON_REVOLVER_DOUBLEACTION_GAMBLER", // Gambler's Double Action Revolver
    "WEAPON_REVOLVER_DOUBLEACTION_EXOTIC", // Exotic Double Action Revolver
    "WEAPON_REVOLVER_SCHOFIELD_CALLOWAY", // Calloway Schofield Revolver
    "WEAPON_REVOLVER_DOUBLEACTION_GOLDEN", // Golden Double Action Revolver
    "WEAPON_REVOLVER_DOUBLEACTION", // Double Action Revolver
    "WEAPON_REVOLVER_SCHOFIELD",   // Schofield Revolver
    "WEAPON_REVOLVER_LEMAT",       // LeMat Revolver

    // ------------ Shotguns ------------
    "WEAPON_SHOTGUN_DOUBLEBARREL",    // Double Barrel Shotgun
    "WEAPON_SHOTGUN_DOUBLEBARREL_EXOTIC", // Exotic Double Barrel Shotgun
    "WEAPON_SHOTGUN_SAWEDOFF",       // Sawed-Off Shotgun
    "WEAPON_SHOTGUN_SEMIAUTO",       // Semi-Auto Shotgun
    "WEAPON_SHOTGUN_REPEATING",      // Repeating Shotgun
    "WEAPON_SHOTGUN_PUMP",           // Pump-Action Shotgun

    // ------------ Repeaters ------------
    "WEAPON_REPEATER_CARBINE",       // Carbine Repeater
    "WEAPON_REPEATER_WINCHESTER",    // Lancaster Repeater
    "WEAPON_REPEATER_HENRY",         // Henry Repeater
    "WEAPON_REPEATER_EVANS",         // Evans Repeater

    // ------------ Rifles ------------
    "WEAPON_RIFLE_VARMINT",          // Varmint Rifle
    "WEAPON_RIFLE_SPRINGFIELD",      // Springfield Rifle
    "WEAPON_RIFLE_BOLTACTION",       // Bolt-Action Rifle

    // ------------ Sniper Rifles ------------
    "WEAPON_SNIPERRIFLE_ROLLINGBLOCK",       // Rolling Block Sniper Rifle
    "WEAPON_SNIPERRIFLE_CARCANO",            // Carcano Sniper Rifle
    "WEAPON_SNIPERRIFLE_ROLLINGBLOCK_EXOTIC" // Rolling Block Sniper Rifle (Exotic Variant)

    // ------------ Bows ------------
    "WEAPON_BOW",                    // Bow

    // ------------ Melee Weapons ------------
    "WEAPON_KNIFE",                  // Knife
    "WEAPON_MACHETE",                // Machete
    "WEAPON_HATCHET"                 // Hatchet
};

std::vector<std::string> AmmoList = {
    // ------------ Pistols ------------
    "AMMO_PISTOL",                // Regular Pistol Ammo
    "AMMO_PISTOL_HIGH_VELOCITY",  // High Velocity Pistol Ammo
    "AMMO_PISTOL_SPLIT_POINT",    // Split Point Pistol Ammo
    "AMMO_PISTOL_EXPRESS",        // Express Pistol Ammo
    "AMMO_PISTOL_EXPRESS_EXPLOSIVE", // Explosive Pistol Ammo

    // ------------ Revolvers ------------
    "AMMO_REVOLVER",              // Regular Revolver Ammo
    "AMMO_REVOLVER_HIGH_VELOCITY",// High Velocity Revolver Ammo
    "AMMO_REVOLVER_SPLIT_POINT",  // Split Point Revolver Ammo
    "AMMO_REVOLVER_EXPRESS",      // Express Revolver Ammo
    "AMMO_REVOLVER_EXPRESS_EXPLOSIVE", // Explosive Revolver Ammo

    // ------------ Shotguns ------------
    "AMMO_SHOTGUN",               // Regular Shotgun Ammo
    "AMMO_SHOTGUN_BUCKSHOT_INCENDIARY", // Incendiary Shotgun Ammo
    "AMMO_SHOTGUN_SLUG",          // Slug Shotgun Ammo
    "AMMO_SHOTGUN_EXPRESS_EXPLOSIVE", // Explosive Shotgun Ammo

    // ------------ Repeaters ------------
    "AMMO_REPEATER",              // Regular Repeater Ammo
    "AMMO_REPEATER_EXPRESS",      // Express Repeater Ammo
    "AMMO_REPEATER_HIGH_VELOCITY", // High Velocity Repeater Ammo
    "AMMO_REPEATER_EXPRESS_EXPLOSIVE", // Explosive Repeater Ammo

    // ------------ Rifles ------------
    "AMMO_RIFLE",                 // Regular Rifle Ammo
    "AMMO_RIFLE_EXPRESS",         // Express Rifle Ammo
    "AMMO_RIFLE_EXPRESS_EXPLOSIVE", // Explosive Rifle Ammo
    "AMMO_RIFLE_HIGH_VELOCITY",   // High Velocity Rifle Ammo
    "AMMO_RIFLE_SPLIT_POINT",     // Split Point Rifle Ammo
    "AMMO_RIFLE_VARMINT",         // Varmint Rifle Ammo

    // ------------ Bow ------------
    "AMMO_ARROW",                 // Regular Arrow
    "AMMO_ARROW_IMPROVED",        // Improved Arrow
    "AMMO_ARROW_SMALL_GAME",      // Small Game Arrow
    "AMMO_ARROW_POISON",          // Poison Arrow
    "AMMO_ARROW_FIRE",            // Fire Arrow
    "AMMO_ARROW_DYNAMITE",        // Dynamite Arrow

    // ------------ Throwing Knives ------------
    "AMMO_THROWING_KNIFE",         // Throwing Knife
    "AMMO_THROWING_KNIVES_IMPROVED", // Improved Throwing Knife
    "AMMO_THROWING_KNIVES_POISON",  // Poison Throwing Knife

    // ------------ Tomahawks ------------
    "AMMO_TOMAHAWK",               // Regular Tomahawk
    "AMMO_TOMAHAWK_IMPROVED",      // Improved Tomahawk
    "AMMO_TOMAHAWK_HOMING",        // Homing Tomahawk

    // ------------ Dynamite ------------
    "AMMO_DYNAMITE",               // Regular Dynamite
    "AMMO_DYNAMITE_VOLATILE",      // Volatile Dynamite

    // ------------ Molotov ------------
    "AMMO_MOLOTOV",                // Regular Molotov
    "AMMO_MOLOTOV_VOLATILE",       // Volatile Molotov
};

void Weapon_LockAllFunction() {
    for (size_t i = 0; i < WeaponsList.size(); ++i) {
        std::string weapon = WeaponsList[i];
        Hash weaponHash = MISC::GET_HASH_KEY(weapon.c_str());

        UNLOCK::UNLOCK_SET_UNLOCKED(weaponHash, FALSE);

        UNLOCK::UNLOCK_SET_VISIBLE(weaponHash, FALSE);
    }
}

void Weapon_UnlockAllFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        for (size_t i = 0; i < WeaponsList.size(); ++i) {
            std::string weapon = WeaponsList[i];
            Hash weaponHash = MISC::GET_HASH_KEY(weapon.c_str());

            if (!WEAPON::HAS_PED_GOT_WEAPON(playerPed, weaponHash, 0, true)) {
                UNLOCK::UNLOCK_SET_UNLOCKED(weaponHash, true);
                UNLOCK::UNLOCK_SET_VISIBLE(weaponHash, true);
            }
        }
    }
}

void Weapon_AddAllWeaponsFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        for (size_t i = 0; i < WeaponsList.size(); ++i) {
            std::string weapon = WeaponsList[i];
            Hash weaponHash = MISC::GET_HASH_KEY(weapon.c_str());

            if (!WEAPON::HAS_PED_GOT_WEAPON(playerPed, weaponHash, 0, true)) {
                WEAPON::GIVE_WEAPON_TO_PED(playerPed, weaponHash, 100, false, true, 0, true, 0.0f, 0.0f, 0, false, 0.0f, false);
            }
        }
    }
}

void Weapon_RemoveAllWeaponsFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    WEAPON::REMOVE_ALL_PED_WEAPONS(playerPed, true, true);
}

void Weapon_AddAllAmmoFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        const int MAX_AMMO = 9999; 

        for (size_t i = 0; i < AmmoList.size(); ++i) {
            std::string ammoType = AmmoList[i];
            Hash ammoHash = MISC::GET_HASH_KEY(ammoType.c_str());

            int currentAmmo = WEAPON::GET_PED_AMMO_BY_TYPE(playerPed, ammoHash);
            if (currentAmmo < MAX_AMMO) {
                WEAPON::_ADD_AMMO_TO_PED_BY_TYPE(playerPed, ammoHash, MAX_AMMO - currentAmmo, 0xC0A3098D);
            }
        }
    }
}

void Weapon_InfiniteAmmoFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Hash currentWeaponHash;
        if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &currentWeaponHash, true, 0, false)) {
            if (weapon_infinite_ammo_bool) {
                Hash ammoType = WEAPON::_GET_AMMO_TYPE_FOR_WEAPON(currentWeaponHash);

                if (ammoType != 0) {
                    PLAYER::_SET_PLAYER_MAX_AMMO_OVERRIDE_FOR_AMMO_TYPE(PLAYER::PLAYER_ID(), ammoType, INT_MAX);

                    WEAPON::SET_PED_AMMO_BY_TYPE(playerPed, ammoType, INT_MAX);

                    WEAPON::SET_PED_INFINITE_AMMO(playerPed, true, currentWeaponHash);
                }
            }
            else {
                WEAPON::SET_PED_INFINITE_AMMO(playerPed, false, currentWeaponHash);

                Hash ammoType = WEAPON::_GET_AMMO_TYPE_FOR_WEAPON(currentWeaponHash);
                if (ammoType != 0) {
                    PLAYER::_SET_PLAYER_MAX_AMMO_OVERRIDE_FOR_AMMO_TYPE(PLAYER::PLAYER_ID(), ammoType, 0);
                }
            }
        }
    }
}

void Weapon_InfiniteClipFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        if (weapon_infinite_clip_bool) {
            WEAPON::_SET_PED_INFINITE_AMMO_CLIP(playerPed, true);
        }
        else {
            WEAPON::_SET_PED_INFINITE_AMMO_CLIP(playerPed, false);
        }
    }
}

void Weapon_OneShotKillFunction() {
    Player player = PLAYER::PLAYER_ID();

    if (PLAYER::IS_PLAYER_PLAYING(player)) {
        if (weapon_one_shot_kill_bool) {
            float damageMultiplier = 999999999.0f;
            PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(player, damageMultiplier);
        }
        else {
            PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(player, 1.0f);
        }
    }
}

void Weapon_AutoCockFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (!ENTITY::DOES_ENTITY_EXIST(playerPed) || ENTITY::IS_ENTITY_DEAD(playerPed)) {
        return;
    }

    if (weapon_auto_cock_bool) {
        if (WEAPON::IS_PED_ARMED(playerPed, 6)) {
            WEAPON::_SET_FORCE_CURRENT_WEAPON_INTO_COCKED_STATE(playerPed, 0);
        }
    }
}

void Weapon_NoSpreadFunction() {
    if (weapon_no_spread_bool) {
        Ped playerPed = PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID());
        Hash currentWeaponHash;

        if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &currentWeaponHash, true, 0, false)) {
            float maxAccuracy = 100.0f;
            PED::_SET_ACCURACY_AGAINST_LOCAL_PLAYER_MODIFIER(playerPed, maxAccuracy);
        }
    }
    else {
        Ped playerPed = PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID());
        float defaultAccuracy = 1.0f;
        PED::_SET_ACCURACY_AGAINST_LOCAL_PLAYER_MODIFIER(playerPed, defaultAccuracy);
    }
}

void Weapon_BleedOutFunction() {
   
}

void Weapon_ReviveFunction() {
 
}

void Weapon_AlwaysCleanFunction() {
    if (weapon_always_clean_bool) {
        Ped playerPed = PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID());
        Hash currentWeaponHash;
        if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &currentWeaponHash, true, 0, false)) {
            Object weaponObject = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(playerPed, 0);
            if (weaponObject != 0) {
                WEAPON::_SET_WEAPON_DEGRADATION(weaponObject, 0.0f);
            }
        }
    }
}

void Weapon_CleanFunction() {
    Ped playerPed = PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID());
    Hash currentWeaponHash;
    if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &currentWeaponHash, true, 0, false)) {
        Object weaponObject = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(playerPed, 0);
        if (weaponObject != 0) {
            WEAPON::_SET_WEAPON_DEGRADATION(weaponObject, 0.0f);
        }
    }
}

void Weapon_AlwaysKillCamFunction() {
    
}