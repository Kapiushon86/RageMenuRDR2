#include "proofs.h"
#include "../../../../../Utils/Saving/States/Player/proofs_default_states.h"
#include "../../../../../Utils/Functions/Player/proofs_functions.h"

CProofsSubmenu::eProofsSubmenuID Submenu_Proofs = CProofsSubmenu::Submenu_Proofs;
CProofsSubmenu* g_ProofsSubmenu = nullptr;
const int submenuPriority = 8;

void CProofsSubmenu::Init() {

    g_Menu->AddSubmenu("RageMenu", "Main > Player > Proofs", Submenu_proofs, submenuPriority, [](Submenu* sub) {

        });
}
