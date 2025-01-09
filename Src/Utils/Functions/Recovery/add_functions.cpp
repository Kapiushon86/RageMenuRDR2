#include "add_functions.h"
#include "../../../Menu/Base/Submenus/Main/Recovery/add.h" 
#include "../../Saving/States/Recovery/add_default_states.h" 
#include "recovery_functions.h"

std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now(); 

void Add_Add10kLoopFunction() {
    if (recovery_add_10k_loop_bool) {
        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedSeconds = currentTime - lastTime;
        if (elapsedSeconds.count() >= 1.0) {
            lastTime = currentTime;

            Ped playerPed = PLAYER::PLAYER_PED_ID();
            int playerMoney = PED::GET_PED_MONEY(playerPed);

            MONEY::_MONEY_INCREMENT_CASH_BALANCE(1000000, 0xA16ABDC2);
        }
    }
    else {
    }
}

void Add_Add10kFunction() {
    Ped playerPed = PLAYER::PLAYER_PED_ID();
    int currentMoney = PED::GET_PED_MONEY(playerPed);
    int amountToAdd = 1000000;

    if (currentMoney + amountToAdd <= 99999999) {
        MONEY::_MONEY_INCREMENT_CASH_BALANCE(amountToAdd, 0xA16ABDC2);
    }
}
