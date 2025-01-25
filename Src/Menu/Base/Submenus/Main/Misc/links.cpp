#include "links.h"
#include "../../../../../Utils/Saving/States/Misc/links_default_states.h"
#include "../../../../../Utils/Functions/Misc/links_functions.h"

CLinksSubmenu::eLinksSubmenuID Submenu_Links = CLinksSubmenu::Submenu_Links;
CLinksSubmenu* g_LinksSubmenu = nullptr;

void CLinksSubmenu::Init()
{
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Main > Misc > Links", Submenu_links, submenuPriority, [](Submenu* sub)
        {

            sub->AddRegularOption("Discord Link", "Join The RageMenu Community.", [] {
                Misc_DiscordLinkFunction();
                });

            sub->AddRegularOption("Github Link", "", [] {
                Misc_GithubLinkFunction();
                });

            sub->AddRegularOption("Nexus Link", "", [] {
                Misc_NexusLinkFunction();
                });
          
        });
}

