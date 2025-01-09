#include "model.h"
#include "../../../../../Utils/Saving/States/Player/model_default_states.h"
#include "../../../../../Utils/Functions/Player/model_functions.h"

CModelSubmenu::eModelSubmenuID Submenu_Model = CModelSubmenu::Submenu_Model;
CModelSubmenu* g_ModelSubmenu = nullptr;

void CModelSubmenu::Init() {
    const int submenuPriority = 8;







    g_Menu->AddSubmenu("RageMenu", "Model", Submenu_model, submenuPriority, [](Submenu* sub) {

        sub->AddSubmenuOption("Model Changer", "", Submenu_model_changer);

        });
}
