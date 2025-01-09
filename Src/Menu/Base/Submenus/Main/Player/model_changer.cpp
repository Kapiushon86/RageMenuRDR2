#include "model_changer.h"
#include "../../../../../Utils/Saving/States/Player/model_changer_default_states.h"
#include "../../../../../Utils/Functions/Player/model_changer_functions.h"

CModel_ChangerSubmenu::eModel_ChangerSubmenuID Submenu_Model_Changer = CModel_ChangerSubmenu::Submenu_Model_Changer;
CModel_ChangerSubmenu* g_Model_ChangerSubmenu = nullptr;

void CModel_ChangerSubmenu::Init() {
    const int submenuPriority = 8;







    g_Menu->AddSubmenu("RageMenu", "Model Changer", Submenu_model_changer, submenuPriority, [](Submenu* sub) {



        });
}
