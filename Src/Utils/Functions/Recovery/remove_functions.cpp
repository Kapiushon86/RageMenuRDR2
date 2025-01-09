#include "remove_functions.h"
#include "../../../Menu/Base/Submenus/Main/Recovery/remove.h" 
#include "../../Saving/States/Recovery/remove_default_states.h" 
#include "recovery_functions.h"

void Remove_Remove10kLoopFunction() {
    if (recovery_remove_10k_loop_bool) {
        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedSeconds = currentTime - lastTime;
        if (elapsedSeconds.count() >= 1.0) {
            lastTime = currentTime;

            Ped playerPed = PLAYER::PLAYER_PED_ID();
            int playerMoney = PED::GET_PED_MONEY(playerPed);
            int amountToRemove = 1000000;

            if (playerMoney >= amountToRemove) {
                PED::SET_PED_MONEY(playerPed, playerMoney - amountToRemove);
            }
        }
    }
}

void Remove_Remove10kFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    int currentMoney = PED::GET_PED_MONEY(playerPed);
    int amountToRemove = 1000000;

    if (currentMoney >= amountToRemove) {
        PED::SET_PED_MONEY(playerPed, currentMoney - amountToRemove);
    }
}
