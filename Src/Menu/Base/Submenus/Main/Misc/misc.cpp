#include "misc.h"
#include "free_camera.h"
#include "wav_player.h"
#include "disables.h"
#include "bypasses.h"
#include "../../../../../Utils/Saving/States/Misc/misc_default_states.h"
#include "../../../../../Utils/Functions/Misc/misc_functions.h"

CMiscSubmenu::eMiscSubmenuID Submenu_Misc = CMiscSubmenu::Submenu_Misc;
CMiscSubmenu* g_MiscSubmenu = nullptr;

const int submenuPriority = 8;

void CMiscSubmenu::Init()
{
    g_FreecameraSubmenu = new CFreecameraSubmenu();
    g_FreecameraSubmenu->Init();

    g_Wav_PlayerSubmenu = new CWav_PlayerSubmenu();
    g_Wav_PlayerSubmenu->Init();

    g_DisablesSubmenu = new CDisablesSubmenu();
    g_DisablesSubmenu->Init();

  //  g_BypassesSubmenu = new CBypassesSubmenu();
    //g_BypassesSubmenu->Init();

    g_Menu->AddSubmenu("RageMenu", "Misc", Submenu_misc, submenuPriority, [](Submenu* sub) {
        sub->AddSubmenuOption("Free Camera", "", Submenu_free_camera);
        sub->AddSubmenuOption("Wav Player", "", Submenu_wav_player);
        sub->AddSubmenuOption("Disables", "", Submenu_disables);
      //  sub->AddSubmenuOption("Bypasses", "", Submenu_bypasses);
        sub->AddEmptyOption("Settings");

        /*sub->AddBoolOption("Online Checks", "Prevents you from going online if ScriptHook fails.", &misc_online_checks_bool, [] {
            Misc_OnlineChecksFunction();
            });
            */

        sub->AddBoolOption("Seasonal Greetings", "", &misc_seasonal_greetings_bool, [] {
            Misc_SeasonalGreetingsFunction();
            });

        sub->AddBoolOption("Real Alt F4", "Bypass All Exit Prompts. (Alt + F4)", &misc_real_alt_f4_bool, [] {
            Misc_RealAltF4Function();
            });

        sub->AddRegularOption("Alt F4", "Exit Game Immediately.", [] {
            Misc_AltF4Function();
            });

        /*sub->AddBoolOption("Bypass Startup Intros", "This will take effect on next startup.", &misc_bypass_startup_intros_bool, [] {
            Misc_BypassStartupIntrosFunction();
            });
            */

        sub->AddBoolOption("Discord Presence", "", &misc_discord_presence_bool, [] {
            Misc_DiscordPresenceFunction();
            });

        sub->AddRegularOption("Reveal Map", "", [] {
            Misc_RevealMapFunction();
            });

        sub->AddRegularOption("Unreveal Map", "", [] {
            Misc_UnrevealMapFunction();
            });
                 

        sub->AddRegularOption("Discord Link", "Join The RageMenu Community.", [] {
            Misc_DiscordLinkFunction();
            });

        /* sub->AddRegularOption("Skip Cutscene", "", [] {
             Misc_SkipCutsceneFunction();
             });
             */

        });
}