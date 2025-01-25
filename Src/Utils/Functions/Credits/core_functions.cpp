#include "credits_functions.h"
#include <Windows.h>
#include <string>
#include <thread> 
#include <iostream>
#include <mutex> 

#include "../../../Menu/Base/Submenus/Main/Credits/core.h" 
#include "../../Saving/States/credits/core_default_states.h" 

void Core_RagemenuFunction() {

    UIUtil::PrintSubtitle("Built within Visual Studio 2022 using C++ and C.");
}