#include "vehicle_functions.h"
#include "../../../Menu/Base/Submenus/Main/Player/vehicle.h" 
#include "../../Saving/States/Player/vehicle_default_states.h" 

std::vector<Vehicle> invincibleVehicles;

void Vehicle_InvincibilityFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false)) {
            Vehicle currentVehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

            if (vehicle_invincibility_bool) { 
                int proofsBitset = 0xFFFF;
                bool specialFlag = true;

                ENTITY::SET_ENTITY_PROOFS(currentVehicle, proofsBitset, specialFlag);
                ENTITY::SET_ENTITY_INVINCIBLE(currentVehicle, true);

                if (std::find(invincibleVehicles.begin(), invincibleVehicles.end(), currentVehicle) == invincibleVehicles.end()) {
                    invincibleVehicles.push_back(currentVehicle);
                }
            }
            else {
                for (Vehicle vehicle : invincibleVehicles) {
                    if (ENTITY::DOES_ENTITY_EXIST(vehicle) && !ENTITY::IS_ENTITY_DEAD(vehicle)) {
                        ENTITY::SET_ENTITY_INVINCIBLE(vehicle, false);
                        ENTITY::SET_ENTITY_PROOFS(vehicle, 0, false);
                    }
                }
                invincibleVehicles.clear();
            }
        }
    }
}

void Vehicle_InvisibilityFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false)) {
            Vehicle currentVehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

            if (vehicle_invisibility_bool) {
                ENTITY::SET_ENTITY_VISIBLE(currentVehicle, false);
                ENTITY::SET_ENTITY_VISIBLE(playerPed, true);
            }
            else { 
                ENTITY::SET_ENTITY_VISIBLE(currentVehicle, true);
            }
        }
    }
}

Vehicle lastVehicle = NULL;
Ped lastMount = NULL;

void Vehicle_DisableKnockoffFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (vehicle_disable_knock_off_bool) { 
        if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false)) {
            Vehicle currentVehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
            lastVehicle = currentVehicle;
            PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(currentVehicle, 0);
            VEHICLE::SET_BREAKABLE_VEHICLE_LOCKS_UNBREAKABLE(currentVehicle, true);

            if (!PED::IS_PED_IN_VEHICLE(playerPed, currentVehicle, false)) {
                TASK::TASK_ENTER_VEHICLE(playerPed, currentVehicle, -1, -1, 1.0f, 1, 0);
            }
        }
        else if (PED::IS_PED_ON_MOUNT(playerPed)) {
            lastVehicle = NULL;
            Ped currentMount = PED::GET_MOUNT(playerPed);
            lastMount = currentMount;
            PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(currentMount, 0);
        }
    }
    else { 
        if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false)) {
            Vehicle currentVehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
            PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(currentVehicle, 1);
            VEHICLE::SET_BREAKABLE_VEHICLE_LOCKS_UNBREAKABLE(currentVehicle, false);
        }
        else if (PED::IS_PED_ON_MOUNT(playerPed)) {
            Ped currentMount = PED::GET_MOUNT(playerPed);
            PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(currentMount, 1);
        }
    }

    if (vehicle_disable_knock_off_bool) {
        if (lastVehicle != NULL && !PED::IS_PED_IN_VEHICLE(playerPed, lastVehicle, false)) {
            TASK::TASK_ENTER_VEHICLE(playerPed, lastVehicle, -1, -1, 1.0f, 1, 0);
        }
    }
}

void Vehicle_NoRagdollFunction() {
   
}

void Vehicle_AlwaysCleanFunction() {
    if (vehicle_always_clean_bool) { 
        Ped playerPed = PLAYER::PLAYER_PED_ID();

        if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
            if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false)) {
                Vehicle currentVehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

                VEHICLE::SET_VEHICLE_DIRT_LEVEL(currentVehicle, 0.0f);
            }
        }
    }
}

void Vehicle_CleanFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false)) {
            Vehicle currentVehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

            VEHICLE::SET_VEHICLE_DIRT_LEVEL(currentVehicle, 0.0f);
        }
    }
}

void Vehicle_FixFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Vehicle currentVehicle;

    if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false)) {
        currentVehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
    }
    else {
        currentVehicle = PLAYER::GET_PLAYERS_LAST_VEHICLE();
    }

    if (ENTITY::DOES_ENTITY_EXIST(currentVehicle) && !ENTITY::IS_ENTITY_DEAD(currentVehicle)) {
        VEHICLE::SET_VEHICLE_FIXED(currentVehicle);
        VEHICLE::SET_VEHICLE_ENGINE_ON(currentVehicle, true, true);

        for (int i = 0; i < DRAFT_HARNESS_COUNT; ++i) {
            Ped draftHorse = VEHICLE::_GET_PED_IN_DRAFT_HARNESS(currentVehicle, i);

            if (ENTITY::DOES_ENTITY_EXIST(draftHorse)) {
                if (ENTITY::IS_ENTITY_DEAD(draftHorse)) {
                    ENTITY::SET_ENTITY_AS_MISSION_ENTITY(draftHorse, true, true);
                    ENTITY::DELETE_ENTITY(&draftHorse); 

                    Ped newHorse = PED::_GET_LAST_VEHICLE_DRAFT_HORSE_WAS_ATTACHED_TO(draftHorse);
                    if (ENTITY::DOES_ENTITY_EXIST(newHorse) && !ENTITY::IS_ENTITY_DEAD(newHorse)) {
                        int maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(newHorse, true);
                        ENTITY::SET_ENTITY_HEALTH(newHorse, maxHealth, 0);
                        VEHICLE::_SET_VEHICLE_WET_LEVEL(currentVehicle, 0.0f);
                        PED::CLEAR_PED_BLOOD_DAMAGE(newHorse);
                        PED::CLEAR_PED_BLOOD_DAMAGE_BY_ZONE(newHorse, 0);
                        PED::CLEAR_PED_ENV_DIRT(newHorse);
                    }
                }
            }
        }
    }

    PED::RESET_PED_LAST_VEHICLE(playerPed);
}

void Vehicle_SuicideFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Vehicle currentVehicle;

    if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false)) {
        currentVehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

        if (ENTITY::DOES_ENTITY_EXIST(currentVehicle) && !ENTITY::IS_ENTITY_DEAD(currentVehicle)) {
            ENTITY::SET_ENTITY_INVINCIBLE(currentVehicle, false);
            ENTITY::SET_ENTITY_PROOFS(currentVehicle, 0, false);

            ENTITY::SET_ENTITY_HEALTH(currentVehicle, 0, 0);

            for (int i = 0; i < DRAFT_HARNESS_COUNT; ++i) {
                Ped draftHorse = VEHICLE::_GET_PED_IN_DRAFT_HARNESS(currentVehicle, i);

                if (ENTITY::DOES_ENTITY_EXIST(draftHorse) && !ENTITY::IS_ENTITY_DEAD(draftHorse)) {
                    ENTITY::SET_ENTITY_INVINCIBLE(draftHorse, false);
                    ENTITY::SET_ENTITY_PROOFS(draftHorse, 0, false);
                    ENTITY::SET_ENTITY_HEALTH(draftHorse, 0, 0);
                }
            }

            if (vehicle_invincibility_bool) {
                ENTITY::SET_ENTITY_INVINCIBLE(currentVehicle, true);
                ENTITY::SET_ENTITY_PROOFS(currentVehicle, 0xFFFF, true);
            }
        }
    }
}

void Vehicle_DeleteFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    Vehicle currentVehicle;

    if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false)) {
        currentVehicle = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);

        if (ENTITY::DOES_ENTITY_EXIST(currentVehicle) && !ENTITY::IS_ENTITY_DEAD(currentVehicle)) {
            ENTITY::SET_ENTITY_AS_MISSION_ENTITY(currentVehicle, true, true);
            ENTITY::DELETE_ENTITY(&currentVehicle);

            for (int i = 0; i < DRAFT_HARNESS_COUNT; ++i) {
                Ped draftHorse = VEHICLE::_GET_PED_IN_DRAFT_HARNESS(currentVehicle, i);

                if (ENTITY::DOES_ENTITY_EXIST(draftHorse) && !ENTITY::IS_ENTITY_DEAD(draftHorse)) {
                    ENTITY::SET_ENTITY_AS_MISSION_ENTITY(draftHorse, true, true);
                    ENTITY::DELETE_ENTITY(&draftHorse);
                }
            }
        }
    }
}
