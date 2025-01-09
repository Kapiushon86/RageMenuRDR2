#include "examplesub.h"

CExamplesubSubmenu::eExamplesubSubmenuID Submenu_Examplesub = CExamplesubSubmenu::Submenu_Examplesub;
CExamplesubSubmenu* g_ExamplesubSubmenu = nullptr;

void CExamplesubSubmenu::Init() {
    const int submenuPriority = 8;







    g_Menu->AddSubmenu("Kapiushon", "Examplesub", Submenu_examplesub, submenuPriority, [](Submenu* sub) {

        

        });
}
