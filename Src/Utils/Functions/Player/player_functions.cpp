#include "player_functions.h"
#include "../../../Menu/Base/Submenus/Main/Player/player.h"
#include "../../Saving/States/Player/player_default_states.h"
#include "../Settings/logging_functions.h"
#include <map>

//  WriteLogEntry(logFile, "Suc", "Player Lawless Mode Enabled", logCounter);

void Player_InvincibilityFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        if (player_invincibility_bool) {
            int proofsBitset = 0xFFFF;
            bool specialFlag = true;

            ENTITY::SET_ENTITY_PROOFS(playerPed, proofsBitset, specialFlag);
            ENTITY::SET_ENTITY_INVINCIBLE(playerPed, true);
        }
        else {
            ENTITY::SET_ENTITY_INVINCIBLE(playerPed, false);
            ENTITY::SET_ENTITY_PROOFS(playerPed, 0, false);
        }
    }
}

void Player_InvisibilityFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        if (player_invisibility_bool) {
            ENTITY::SET_ENTITY_VISIBLE(playerPed, false);
        }
        else {
            ENTITY::SET_ENTITY_VISIBLE(playerPed, true);
        }
    }
}

void Player_LawlessFunction() {
    int playerId = PLAYER::PLAYER_ID();

    if (PLAYER::IS_PLAYER_PLAYING(playerId)) {
        if (player_lawless_bool) {
            PLAYER::CLEAR_PLAYER_WANTED_LEVEL(playerId);
            LAW::CLEAR_WANTED_SCORE(playerId);
            LAW::_SET_BOUNTY_HUNTER_PURSUIT_CLEARED();
            PLAYER::SET_MAX_WANTED_LEVEL(0);
            PLAYER::SET_WANTED_LEVEL_MULTIPLIER(0.0f);
            PLAYER::SUPPRESS_WITNESSES_CALLING_POLICE_THIS_FRAME(playerId);
        }
        else {
            PLAYER::SET_MAX_WANTED_LEVEL(5);
            PLAYER::SET_WANTED_LEVEL_MULTIPLIER(1.0f);
        }
    }
}

void Player_ClearPursuitFunction() {
    int playerId = PLAYER::PLAYER_ID();

    if (PLAYER::IS_PLAYER_PLAYING(playerId)) {
        {
            PLAYER::CLEAR_PLAYER_WANTED_LEVEL(playerId);
            LAW::CLEAR_WANTED_SCORE(playerId);
            LAW::_SET_BOUNTY_HUNTER_PURSUIT_CLEARED();
            PLAYER::SET_MAX_WANTED_LEVEL(0);
            PLAYER::SET_WANTED_LEVEL_MULTIPLIER(0.0f);
            PLAYER::SUPPRESS_WITNESSES_CALLING_POLICE_THIS_FRAME(playerId);

        }
    }
    else {
        PLAYER::SET_MAX_WANTED_LEVEL(5);
        PLAYER::SET_WANTED_LEVEL_MULTIPLIER(1.0f);
    }
}

void Player_AutoPayBountyFunction() {
    if (player_auto_pay_bounty_bool) {
        Player player = PLAYER::PLAYER_ID();
        int playerMoney = MONEY::_MONEY_GET_CASH_BALANCE();
        int bountyAmount = LAW::GET_BOUNTY(player);

        if (bountyAmount > 0 && playerMoney >= bountyAmount) {
            MONEY::_MONEY_DECREMENT_CASH_BALANCE(bountyAmount);
            LAW::CLEAR_BOUNTY(player);
        }
    }
}

void Player_LevitateFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        if (player_levitate_bool) {
            if (PAD::IS_CONTROL_PRESSED(0, INPUT_JUMP)) {
                Vector3 currentVelocity = ENTITY::GET_ENTITY_VELOCITY(playerPed, 0);

                Vector3 superJumpVelocity = { currentVelocity.x, currentVelocity.y, 10.0f };

                ENTITY::SET_ENTITY_VELOCITY(playerPed, superJumpVelocity.x, superJumpVelocity.y, superJumpVelocity.z);

                PED::SET_PED_CAN_RAGDOLL(playerPed, false);
            }
        }
        else {
            PED::SET_PED_CAN_RAGDOLL(playerPed, true);
        }
    }
}

void Player_SuperJumpFunction() {
    if (player_super_jump_bool) {
        MISC::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
    }
}

void Player_SuperPunchFunction() {
    Player player = PLAYER::PLAYER_ID();

    if (PLAYER::IS_PLAYER_PLAYING(player)) {
        if (player_super_punch_bool) {
            float damageMultiplier = 999999999.0f;
            PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(player, damageMultiplier);
        }
        else {
            PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(player, 1.0f);
        }
    }
}

void Player_OneHitKOFunction() {
    if (PLAYER::IS_PLAYER_PLAYING(PLAYER::PLAYER_ID())) {
        Ped playerPed = PLAYER::PLAYER_PED_ID();

        if (player_one_hit_ko_bool) {
            PED::_SET_PED_KNOCKED_BY_ONE_HIT(playerPed, 1.0f);
        }
        else {
            PED::_SET_PED_KNOCKED_BY_ONE_HIT(playerPed, 0.0f);
        }
    }
}

void Player_AntiMeleeFunction() {
    if (PLAYER::PLAYER_PED_ID()) {
        for (int i = 0; i < 35; i++) {
            if (player_anti_melee_bool) {
                PED::_SET_PED_TARGET_ACTION_DISABLE_FLAG(PLAYER::PLAYER_PED_ID(), i);
            }
            else {
                PED::_CLEAR_PED_TARGET_ACTION_DISABLE_FLAG(PLAYER::PLAYER_PED_ID(), i);
            }
        }
    }
}

void Player_EveryoneIgnoreFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        if (player_everyone_ignore_bool) {
            PLAYER::SET_EVERYONE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), true);
        }
        else {
            PLAYER::SET_EVERYONE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), false);
        }
    }
}

void Player_NoRagdollFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        if (player_no_ragdoll_bool) {
            PED::SET_PED_CAN_RAGDOLL(playerPed, false);
        }
        else {
            PED::SET_PED_CAN_RAGDOLL(playerPed, true);
        }
    }
}

void Player_QuickSkinFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        if (player_quick_skin_bool) {
            if (TASK::GET_IS_TASK_ACTIVE(playerPed, 628)) {
                TASK::CLEAR_PED_TASKS_IMMEDIATELY(playerPed, true, true);
            }
        }
    }
}

void Player_NeverLooseHatFunction() {
   
}

void Player_ClimbSteepSlopesFunction() {
   
}

void Player_AlwaysShowCoresFunction() {
    if (player_always_show_cores_bool) {
        HUD::_SHOW_PLAYER_CORES(true);
    }
    else {
        HUD::_SHOW_PLAYER_CORES(false);
    }
}

void Player_AlwaysCleanFunction() {
    #define PED_DAMAGE_CLEANLINESS_PERFECT 2
    Ped playerPed = PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID());

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        if (player_always_clean_bool) {
            PED::CLEAR_PED_BLOOD_DAMAGE(playerPed);
            PED::CLEAR_PED_BLOOD_DAMAGE(playerPed);
            PED::CLEAR_PED_BLOOD_DAMAGE_BY_ZONE(playerPed, 0);
            PED::CLEAR_PED_WETNESS(playerPed);
            PED::CLEAR_PED_ENV_DIRT(playerPed);
            PED::_CLEAR_PED_BLOOD_DAMAGE_FACIAL(playerPed, 1);
            PED::_SET_PED_DAMAGE_CLEANLINESS(playerPed, PED_DAMAGE_CLEANLINESS_PERFECT);
            PED::_SET_PED_DIRT_CLEANED(playerPed, 0.0f, -1, true, true);
        }
    }
}

void Player_CleanFunction() {
    #define PED_DAMAGE_CLEANLINESS_PERFECT 2
    Ped playerPed = PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID());

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        PED::CLEAR_PED_BLOOD_DAMAGE(playerPed);
        PED::CLEAR_PED_BLOOD_DAMAGE_BY_ZONE(playerPed, 0);
        PED::CLEAR_PED_WETNESS(playerPed);
        PED::CLEAR_PED_ENV_DIRT(playerPed);
        PED::_CLEAR_PED_BLOOD_DAMAGE_FACIAL(playerPed, 1);
        PED::_SET_PED_DAMAGE_CLEANLINESS(playerPed, PED_DAMAGE_CLEANLINESS_PERFECT);
        PED::_SET_PED_DIRT_CLEANED(playerPed, 0.0f, -1, true, true);
    }
}


void Player_ApplyDirtFunction() {
}

void Player_SuicideFunction() {
    Ped playerPed = PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID());

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        ENTITY::SET_ENTITY_INVINCIBLE(playerPed, false);
        ENTITY::SET_ENTITY_PROOFS(playerPed, 0, false);
        ENTITY::SET_ENTITY_HEALTH(playerPed, 0, 0);

        if (player_invincibility_bool) {
            ENTITY::SET_ENTITY_INVINCIBLE(playerPed, true);
            ENTITY::SET_ENTITY_PROOFS(playerPed, 0xFFFF, true);
        }
    }
}
