#include "modifiers_functions.h"
#include "../../../Menu/Base/Submenus/Main/Player/modifiers.h" 
#include "../../Saving/States/Player/modifiers_default_states.h" 

enum AttributeCore {
    ATTRIBUTE_CORE_HEALTH = 0,
    ATTRIBUTE_CORE_STAMINA = 1,
    ATTRIBUTE_CORE_DEADEYE = 2
};

void Modifiers_InfiniteStaminaFunction()
{
    if (modifiers_infinite_stamina_bool) {

        Ped playerPed = PLAYER::PLAYER_PED_ID();

        if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
            ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_STAMINA,
                ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(playerPed, AttributeCore::ATTRIBUTE_CORE_STAMINA));
            PED::_CHANGE_PED_STAMINA(playerPed, PED::_GET_PED_MAX_STAMINA(playerPed));
            ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, (int)AttributeCore::ATTRIBUTE_CORE_STAMINA, 100);
        }
    }
}

void Modifiers_InfiniteSwimFunction()
{
    if (modifiers_infinite_swim_bool)
    {
        Ped playerPed = PLAYER::PLAYER_PED_ID();

        if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed))
        {
            if (PED::IS_PED_SWIMMING(playerPed))
            {
                ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_STAMINA,
                    ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(playerPed, AttributeCore::ATTRIBUTE_CORE_STAMINA));
                PED::_CHANGE_PED_STAMINA(playerPed, PED::_GET_PED_MAX_STAMINA(playerPed));
                ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, (int)AttributeCore::ATTRIBUTE_CORE_STAMINA, 100);
            }
        }
    }
}

void Modifiers_InfiniteDeadEyeFunction()
{
    if (modifiers_infinite_dead_eye_bool) {

        Ped playerPed = PLAYER::PLAYER_PED_ID();

        if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
            ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_DEADEYE,
                ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(playerPed, AttributeCore::ATTRIBUTE_CORE_DEADEYE));
            PLAYER::_SPECIAL_ABILITY_RESTORE_BY_AMOUNT(PLAYER::PLAYER_ID(),
                PLAYER::_GET_PLAYER_MAX_DEAD_EYE(PLAYER::PLAYER_ID(), 0), 0, 0, 1);
            ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, (int)AttributeCore::ATTRIBUTE_CORE_DEADEYE, 100);
        }
    }
}

void Modifiers_InfiniteEagleEyeFunction()
{
    if (modifiers_infinite_eagle_eye_bool)
    {
        Ped playerPed = PLAYER::PLAYER_PED_ID();

        if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed))
        {
            auto playerId = PLAYER::PLAYER_ID();
            PLAYER::_MODIFY_INFINITE_TRAIL_VISION(playerId, 1);
            PLAYER::_EAGLE_EYE_SET_PLUS_FLAG_DISABLED(playerId, false);
        }
    }
    else
    {
        Ped playerPed = PLAYER::PLAYER_PED_ID();

        if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed))
        {
            auto playerId = PLAYER::PLAYER_ID();
            PLAYER::_MODIFY_INFINITE_TRAIL_VISION(playerId, 0);
            PLAYER::_EAGLE_EYE_SET_PLUS_FLAG_DISABLED(playerId, true);
        }
    }
}


void Modifiers_SuperChargedCoresFunction() {
}

void Modifiers_RefillAllCoresFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {

        ENTITY::SET_ENTITY_HEALTH(playerPed, ENTITY::GET_ENTITY_MAX_HEALTH(playerPed, false), 0);
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_HEALTH,
            ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(playerPed, AttributeCore::ATTRIBUTE_CORE_HEALTH));
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, (int)AttributeCore::ATTRIBUTE_CORE_HEALTH, 100);

        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_STAMINA,
            ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(playerPed, AttributeCore::ATTRIBUTE_CORE_STAMINA));
        PED::_CHANGE_PED_STAMINA(playerPed, PED::_GET_PED_MAX_STAMINA(playerPed));
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, (int)AttributeCore::ATTRIBUTE_CORE_STAMINA, 100);

        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_DEADEYE,
            ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(playerPed, AttributeCore::ATTRIBUTE_CORE_DEADEYE));
        PLAYER::_SPECIAL_ABILITY_RESTORE_BY_AMOUNT(PLAYER::PLAYER_ID(),
            PLAYER::_GET_PLAYER_MAX_DEAD_EYE(PLAYER::PLAYER_ID(), 0), 0, 0, 1);
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, (int)AttributeCore::ATTRIBUTE_CORE_DEADEYE, 100);
    }
}

void Modifiers_RefillHealthCoreFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {

        ENTITY::SET_ENTITY_HEALTH(playerPed, ENTITY::GET_ENTITY_MAX_HEALTH(playerPed, false), 0);
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_HEALTH,
            ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(playerPed, AttributeCore::ATTRIBUTE_CORE_HEALTH));
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, (int)AttributeCore::ATTRIBUTE_CORE_HEALTH, 100);
    }
}

void Modifiers_RefillStaminaCoreFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_STAMINA,
            ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(playerPed, AttributeCore::ATTRIBUTE_CORE_STAMINA));
        PED::_CHANGE_PED_STAMINA(playerPed, PED::_GET_PED_MAX_STAMINA(playerPed));
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, (int)AttributeCore::ATTRIBUTE_CORE_STAMINA, 100);
    }
}

void Modifiers_RefillDeadEyeCoreFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed)) {
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_DEADEYE,
            ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(playerPed, AttributeCore::ATTRIBUTE_CORE_DEADEYE));
        PLAYER::_SPECIAL_ABILITY_RESTORE_BY_AMOUNT(PLAYER::PLAYER_ID(),
            PLAYER::_GET_PLAYER_MAX_DEAD_EYE(PLAYER::PLAYER_ID(), 0), 0, 0, 1);
        ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, (int)AttributeCore::ATTRIBUTE_CORE_DEADEYE, 100);
    }
}
