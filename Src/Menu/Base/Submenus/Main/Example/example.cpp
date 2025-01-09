#include "example.h"
#include "examplesub.h"

CExampleSubmenu::eExampleSubmenuID Submenu_Example = CExampleSubmenu::Submenu_Example;
CExampleSubmenu* g_ExampleSubmenu = nullptr;

void CExampleSubmenu::Init() {
    const int submenuPriority = 8;

   

    g_ExampleSubmenu = new CExampleSubmenu();
    g_ExampleSubmenu->Init();



    g_Menu->AddSubmenu("Kapiushon", "Example", Submenu_example, submenuPriority, [](Submenu* sub) {
       


        sub->AddSubmenuOption("Example", "", Submenu_examplesub);

       

        });
}
