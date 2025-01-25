#include "ragemenu_functions.h"
#include <Windows.h>
#include <string>
#include <thread> 
#include <iostream>
#include <mutex> 

#include "../../../Menu/Base/Submenus/Main/Credits/ragemenu.h" 
#include "../../Saving/States/Credits/ragemenu_default_states.h" 


void UserInterface_RockstarGamesFunction() {
    UIUtil::PrintSubtitle("Creator | Created Red Dead Redemption 2.");
}

void UserInterface_Halen84Function() {
    UIUtil::PrintSubtitle("Original UI Developer | Base Used to Create RageMenu.");
}

void UserInterface_JJFunction() {
    UIUtil::PrintSubtitle("Lead UI Developer | Refined, Enhanced, and Current UI State of RageMenu, Ongoing UI Improvements.");
}

void UserInterface_GhostoneFunction() {
    UIUtil::PrintSubtitle("Contributor | Fixed a minor issue with submenu indicator positioning (\">>>\") in RageMenu Drawing System.");
}