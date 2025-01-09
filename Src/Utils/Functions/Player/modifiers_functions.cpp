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
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed))
    {
        if (modifiers_infinite_stamina_bool)
        {
            float current_stamina_core = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_STAMINA);
            float current_stamina_bar = PLAYER::_GET_PLAYER_STAMINA(PLAYER::PLAYER_ID());

            ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_STAMINA, current_stamina_core);

            PED::_CHANGE_PED_STAMINA(playerPed, current_stamina_bar - PLAYER::_GET_PLAYER_STAMINA(PLAYER::PLAYER_ID()));

            modifiers_was_infinite_stamina_bool = true;
        }
        else
        {
            if (modifiers_was_infinite_stamina_bool)
            {
                modifiers_was_infinite_stamina_bool = false;
            }
        }
    }
}

void Modifiers_InfiniteDeadEyeFunction()
{
    static float cached_deadeye_core = -1.0f; 
    static float cached_deadeye_bar = -1.0f; 

    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed))
    {
        if (modifiers_infinite_dead_eye_bool)
        {
            if (!modifiers_was_infinite_dead_eye_bool)
            {
                cached_deadeye_core = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_DEADEYE);
                cached_deadeye_bar = PLAYER::_GET_PLAYER_DEAD_EYE(PLAYER::PLAYER_ID());
                modifiers_was_infinite_dead_eye_bool = true;
            }

            ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(playerPed, AttributeCore::ATTRIBUTE_CORE_DEADEYE, cached_deadeye_core);
            PLAYER::_SPECIAL_ABILITY_RESTORE_BY_AMOUNT(
                PLAYER::PLAYER_ID(),
                cached_deadeye_bar - PLAYER::_GET_PLAYER_DEAD_EYE(PLAYER::PLAYER_ID()),
                0,
                0,
                1
            );
        }
        else
        {
            if (modifiers_was_infinite_dead_eye_bool)
            {
                cached_deadeye_core = -1.0f;
                cached_deadeye_bar = -1.0f;
                modifiers_was_infinite_dead_eye_bool = false;
            }
        }
    }
}

void Modifiers_InfiniteEagleEyeFunction()
{
    Ped playerPed = PLAYER::PLAYER_PED_ID();

    if (ENTITY::DOES_ENTITY_EXIST(playerPed) && !ENTITY::IS_ENTITY_DEAD(playerPed))
    {
        auto playerId = PLAYER::PLAYER_ID();

        if (modifiers_infinite_eagle_eye_bool)
        {
            PLAYER::_MODIFY_INFINITE_TRAIL_VISION(playerId, 1);
            PLAYER::_EAGLE_EYE_SET_PLUS_FLAG_DISABLED(playerId, false);

            modifiers_was_infinite_eagle_eye_bool = true;
        }
        else
        {
            if (modifiers_was_infinite_eagle_eye_bool)
            {
                PLAYER::_MODIFY_INFINITE_TRAIL_VISION(playerId, 0);
                PLAYER::_EAGLE_EYE_SET_PLUS_FLAG_DISABLED(playerId, true);

                modifiers_was_infinite_eagle_eye_bool = false;
            }
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
