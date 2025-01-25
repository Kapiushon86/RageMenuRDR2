#include "mount_functions.h"
#include "../../../Menu/Base/Submenus/Main/Player/mount.h" 
#include "../../Saving/States/Player/mount_default_states.h" 
#include "../Settings/logging_functions.h"
#include <cmath>

Ped LastMount = 0;

void Mount_DismountFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        Ped currentMount = PED::GET_MOUNT(playerPed);
        if (ENTITY::DOES_ENTITY_EXIST(currentMount) && !ENTITY::IS_ENTITY_DEAD(currentMount)) {
            LastMount = currentMount;
        }
    }
    else {
        if (LastMount != 0) {
            if (mount_invisibility_bool) {
                ENTITY::SET_ENTITY_VISIBLE(LastMount, false);
            }
            else {
                ENTITY::SET_ENTITY_VISIBLE(LastMount, true);
            }
        }
    }
}

void Mount_InvincibilityFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Ped targetMount = PED::GET_MOUNT(playerPed);

        if (PED::IS_PED_ON_MOUNT(playerPed)) {
            LastMount = targetMount;

            if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
                if (mount_invincibility_bool) {
                    int proofsBitset = 0xFFFF;
                    bool specialFlag = true;

                    ENTITY::SET_ENTITY_PROOFS(targetMount, proofsBitset, specialFlag);
                    ENTITY::SET_ENTITY_INVINCIBLE(targetMount, true);
                }
                else {
                    ENTITY::SET_ENTITY_INVINCIBLE(targetMount, false);
                    ENTITY::SET_ENTITY_PROOFS(targetMount, 0, false);
                }
            }
        }
        else if (LastMount != 0 && ENTITY::DOES_ENTITY_EXIST(LastMount) && !ENTITY::IS_ENTITY_DEAD(LastMount)) {
            if (mount_invincibility_bool) {
                int proofsBitset = 0xFFFF;
                bool specialFlag = true;

                ENTITY::SET_ENTITY_PROOFS(LastMount, proofsBitset, specialFlag);
                ENTITY::SET_ENTITY_INVINCIBLE(LastMount, true);
            }
            else {
                ENTITY::SET_ENTITY_INVINCIBLE(LastMount, false);
                ENTITY::SET_ENTITY_PROOFS(LastMount, 0, false);
            }
        }
    }
}

void Mount_InvisibilityFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        Ped targetMount = 0;

        if (PED::IS_PED_ON_MOUNT(playerPed)) {
            targetMount = PED::GET_MOUNT(playerPed);
            LastMount = targetMount; 
        }
        else if (LastMount != 0) {
            targetMount = LastMount; 
        }

        if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
            if (mount_invisibility_bool) {
                ENTITY::SET_ENTITY_VISIBLE(targetMount, false);
                ENTITY::SET_ENTITY_VISIBLE(playerPed, true);
            }
            else {
                ENTITY::SET_ENTITY_VISIBLE(targetMount, true);
            }
        }
    }
}

void Mount_LevitateFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        Ped targetMount = PED::GET_MOUNT(playerPed);

        if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
            if (mount_levitate_bool) {
                if (PAD::IS_CONTROL_PRESSED(0, INPUT_JUMP)) {
                    Vector3 currentVelocity = ENTITY::GET_ENTITY_VELOCITY(targetMount, 0);

                    Vector3 superJumpVelocity = { currentVelocity.x, currentVelocity.y, 10.0f };

                    ENTITY::SET_ENTITY_VELOCITY(targetMount, superJumpVelocity.x, superJumpVelocity.y, superJumpVelocity.z);

                    PED::SET_PED_CAN_RAGDOLL(targetMount, false);
                }
            }
            else {
                PED::SET_PED_CAN_RAGDOLL(targetMount, true);
            }
        }
    }
}

void Mount_InfiniteStaminaFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped targetMount = 0;

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        targetMount = PED::GET_MOUNT(playerPed);
    }

    if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
        if (mount_infinite_stamina_bool) {
            float stamina_bar = PED::_GET_PED_STAMINA(targetMount);
            ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(targetMount, AttributeCore::ATTRIBUTE_CORE_STAMINA, 100.0f);
            PED::_CHANGE_PED_STAMINA(targetMount, stamina_bar);

            mount_was_infinite_stamina_bool = true;
        }
        else if (!mount_infinite_stamina_bool && mount_was_infinite_stamina_bool) {
            mount_was_infinite_stamina_bool = false;
        }
    }
}

void Mount_RefillAllCoresFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped targetMount = 0;

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        targetMount = PED::GET_MOUNT(playerPed);
        LastMount = targetMount;
    }
    else if (LastMount != 0) {
        targetMount = LastMount;
    }

    if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
        ENTITY::SET_ENTITY_HEALTH(targetMount, ENTITY::GET_ENTITY_MAX_HEALTH(targetMount, false), 0);

        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(targetMount, (int)AttributeCore::ATTRIBUTE_CORE_HEALTH,
            (int)std::round(ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(targetMount, AttributeCore::ATTRIBUTE_CORE_HEALTH)));
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(targetMount, (int)AttributeCore::ATTRIBUTE_CORE_HEALTH, 100);

        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(targetMount, (int)AttributeCore::ATTRIBUTE_CORE_STAMINA,
            (int)std::round(ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(targetMount, AttributeCore::ATTRIBUTE_CORE_STAMINA)));
        PED::_CHANGE_PED_STAMINA(targetMount, PED::_GET_PED_MAX_STAMINA(targetMount));
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(targetMount, (int)AttributeCore::ATTRIBUTE_CORE_STAMINA, 100);
    }
}

void Mount_RefillHealthCoreFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped targetMount = 0;

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        targetMount = PED::GET_MOUNT(playerPed);
        LastMount = targetMount;
    }
    else if (LastMount != 0) {
        targetMount = LastMount;
    }

    if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
        ENTITY::SET_ENTITY_HEALTH(targetMount, ENTITY::GET_ENTITY_MAX_HEALTH(targetMount, false), 0);
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(targetMount, (int)AttributeCore::ATTRIBUTE_CORE_HEALTH,
            (int)std::round(ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(targetMount, AttributeCore::ATTRIBUTE_CORE_HEALTH)));
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(targetMount, (int)AttributeCore::ATTRIBUTE_CORE_HEALTH, 100);
    }
}

void Mount_RefillStaminaCoreFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped targetMount = 0;

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        targetMount = PED::GET_MOUNT(playerPed);
        LastMount = targetMount;
    }
    else if (LastMount != 0) {
        targetMount = LastMount;
    }

    if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(targetMount, (int)AttributeCore::ATTRIBUTE_CORE_STAMINA,
            (int)std::round(ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(targetMount, AttributeCore::ATTRIBUTE_CORE_STAMINA)));
        PED::_CHANGE_PED_STAMINA(targetMount, PED::_GET_PED_MAX_STAMINA(targetMount));
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(targetMount, (int)AttributeCore::ATTRIBUTE_CORE_STAMINA, 100);
    }
}

void Mount_FearlessFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped targetMount = 0;

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        targetMount = PED::GET_MOUNT(playerPed);
        LastMount = targetMount;
    }
    else if (LastMount != 0) {
        targetMount = LastMount;
    }

    if (!targetMount || PED::IS_PED_DEAD_OR_DYING(targetMount, true)) {
        return;
    }

    float agitation = PED::_GET_PED_MOTIVATION(targetMount, 3, 0);

    if (agitation > 0.0f && mount_fearless_bool) {
        PED::_SET_PED_MOTIVATION(targetMount, 3, 0.0f, 0);
    }

    PED::_SET_PED_MOTIVATION_STATE_OVERRIDE(targetMount, 3, false);
}

void Mount_NoRagdollFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped targetMount = 0;

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        targetMount = PED::GET_MOUNT(playerPed);
        LastMount = targetMount;
    }
    else if (LastMount != 0) {
        targetMount = LastMount;
    }

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
            if (mount_no_ragdoll_bool) {
                PED::SET_PED_CAN_RAGDOLL(targetMount, false);
            }
            else {
                PED::SET_PED_CAN_RAGDOLL(targetMount, true);
            }
        }
    }
}

void Mount_FireHoovesFunction() {


}

void Mount_TeleportMountWhistleFunction() {
    if (mount_teleport_mount_whistle_bool) {
    
    }
}

void Mount_MaxBondingFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped targetMount = 0;

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        targetMount = PED::GET_MOUNT(playerPed);
    }

    if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
        int tamingState = PED::_GET_HORSE_TAMING_STATE(targetMount);

        if (tamingState == 5) {
            UIUtil::PrintSubtitle("Pat Your Horse");

            ATTRIBUTE::SET_ATTRIBUTE_BASE_RANK(targetMount, 13, 4);
            PED::_SET_MOUNT_BONDING_LEVEL(targetMount, 4);
            COMPENDIUM::COMPENDIUM_HORSE_BONDING(targetMount, 4);
        }
    }
}

void Mount_AlwaysShowCoresFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped targetMount = 0;

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        targetMount = PED::GET_MOUNT(playerPed);
        LastMount = targetMount;
    }
    else if (LastMount != 0) {
        targetMount = LastMount;
    }

    if (mount_always_show_cores_bool) {
        if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
            HUD::_SHOW_HORSE_CORES(true);
        }
        else if (ENTITY::DOES_ENTITY_EXIST(LastMount) && !ENTITY::IS_ENTITY_DEAD(LastMount)) {
            HUD::_SHOW_HORSE_CORES(true);
        }
        else {
            Ped ownedHorse = PLAYER::GET_MOUNT_OWNED_BY_PLAYER(PLAYER::PLAYER_ID());
            if (ENTITY::DOES_ENTITY_EXIST(ownedHorse) && !ENTITY::IS_ENTITY_DEAD(ownedHorse)) {
                LastMount = ownedHorse;
                HUD::_SHOW_HORSE_CORES(true);
            }
            else {
                HUD::_SHOW_HORSE_CORES(false);
            }
        }
    }
    else {
        HUD::_SHOW_HORSE_CORES(false);
    }
}

void Mount_AlwaysCleanFunction() {
    if (mount_always_clean_bool) {
        Ped playerPed = PLAYER::PLAYER_PED_ID();

        if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
            Ped targetMount = 0;

            if (PED::IS_PED_ON_MOUNT(playerPed)) {
                targetMount = PED::GET_MOUNT(playerPed);
                LastMount = targetMount;
            }
            else if (LastMount != 0) {
                targetMount = LastMount;
            }

            if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
                PED::CLEAR_PED_BLOOD_DAMAGE(targetMount);
                PED::CLEAR_PED_BLOOD_DAMAGE_BY_ZONE(targetMount, 0);
                PED::CLEAR_PED_WETNESS(targetMount);
                PED::CLEAR_PED_ENV_DIRT(targetMount);
            }
        }
    }
}

void Mount_CleanFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped targetMount = 0;

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        targetMount = PED::GET_MOUNT(playerPed);
        LastMount = targetMount;
    }
    else if (LastMount != 0) {
        targetMount = LastMount;
    }

    if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
        PED::CLEAR_PED_BLOOD_DAMAGE(targetMount);
        PED::CLEAR_PED_BLOOD_DAMAGE_BY_ZONE(targetMount, 0);
        PED::CLEAR_PED_WETNESS(targetMount);
        PED::CLEAR_PED_ENV_DIRT(targetMount);
    }
}

void Mount_ClearPeltsFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped targetMount = 0;

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        targetMount = PED::GET_MOUNT(playerPed);
        LastMount = targetMount;
    }
    else if (LastMount != 0) {
        targetMount = LastMount;
    }

    if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
        ENTITY::CLEAR_ENTITY_LAST_DAMAGE_ENTITY(targetMount);
    }
}

void Mount_FixFunction() {
   
}

void Mount_SuicideFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped targetMount = 0;

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        targetMount = PED::GET_MOUNT(playerPed);
        LastMount = targetMount;
    }
    else if (LastMount != 0) {
        targetMount = LastMount;
    }

    if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
        ENTITY::SET_ENTITY_INVINCIBLE(targetMount, false);
        ENTITY::SET_ENTITY_PROOFS(targetMount, 0, false);
        ENTITY::SET_ENTITY_HEALTH(targetMount, 0, 0);
    }
}

void Mount_DeleteFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Ped targetMount = 0;

    if (PED::IS_PED_ON_MOUNT(playerPed)) {
        targetMount = PED::GET_MOUNT(playerPed);
        LastMount = targetMount;
    }
    else if (LastMount != 0) {
        targetMount = LastMount;
    }

    if (ENTITY::DOES_ENTITY_EXIST(targetMount) && !ENTITY::IS_ENTITY_DEAD(targetMount)) {
        ENTITY::SET_ENTITY_AS_MISSION_ENTITY(targetMount, true, true);
        ENTITY::DELETE_ENTITY(&targetMount);
    }
}