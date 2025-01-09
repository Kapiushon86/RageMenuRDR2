#include "player.h"
#include "no_clip.h"
#include "mount.h"
#include "vehicle.h"
#include "model.h"
#include "model_changer.h"
#include "effects.h"
#include "effects_screen.h"
#include "effects_particles.h"
#include "modifiers.h"
#include "../Misc/wav_player.h"
#include "../../../../../Utils/Saving/States/Player/player_default_states.h"
#include "../../../../../Utils/Functions/Player/player_functions.h"

CPlayerSubmenu::ePlayerSubmenuID Submenu_Player = CPlayerSubmenu::Submenu_Player;
CPlayerSubmenu* g_PlayerSubmenu = nullptr;

const int submenuPriority = 8;

void CPlayerSubmenu::Init() {
    g_NoclipSubmenu = new CNoclipSubmenu();
    g_NoclipSubmenu->Init();

    g_MountSubmenu = new CMountSubmenu();
    g_MountSubmenu->Init();

    g_VehicleSubmenu = new CVehicleSubmenu();
    g_VehicleSubmenu->Init();

    /*
    g_ModelSubmenu = new CModelSubmenu();
    g_ModelSubmenu->Init();
    */

    g_Model_ChangerSubmenu = new CModel_ChangerSubmenu();
    g_Model_ChangerSubmenu->Init();

    g_ModifiersSubmenu = new CModifiersSubmenu();
    g_ModifiersSubmenu->Init();
    
    /*
    g_EffectsSubmenu = new CEffectsSubmenu();
    g_EffectsSubmenu->Init();
    */

    g_Effects_ScreenSubmenu = new CEffects_ScreenSubmenu();
    g_Effects_ScreenSubmenu->Init();

    g_Effects_ParticlesSubmenu = new CEffects_ParticlesSubmenu();
    g_Effects_ParticlesSubmenu->Init();

    g_Menu->AddSubmenu("RageMenu", "Player", Submenu_player, submenuPriority, [](Submenu* sub) {
        sub->AddSubmenuOption("No Clip", "", Submenu_no_clip);
        sub->AddSubmenuOption("Mount", "", Submenu_mount);
        sub->AddSubmenuOption("Vehicle", "", Submenu_vehicle);
        // sub->AddSubmenuOption("Model", "", Submenu_model);
        sub->AddSubmenuOption("Modifiers", "", Submenu_modifiers);
        // sub->AddSubmenuOption("Effects", "", Submenu_effects);

        sub->AddEmptyOption("Settings");

        sub->AddBoolOption("Invincibility", "", &player_invincibility_bool, [] {
            Player_InvincibilityFunction();
            });

        sub->AddBoolOption("Invisibility", "", &player_invisibility_bool, [] {
            Player_InvisibilityFunction();
            });

        sub->AddBoolOption("Lawless", "", &player_lawless_bool, [] {
            Player_LawlessFunction();
            });

       /* sub->AddBoolOption("Auto Pay Bounty", "", &player_auto_pay_bounty_bool, [] {
            Player_AutoPayBountyFunction();
            });
            */

        sub->AddBoolOption("Super Jump", "", &player_super_jump_bool, [] {
            Player_SuperJumpFunction();
            });

        sub->AddBoolOption("Super Punch", "", &player_super_punch_bool, [] {
            Player_SuperPunchFunction();
            });

        sub->AddBoolOption("One Hit KO", "", &player_one_hit_ko_bool, [] {
            Player_OneHitKOFunction();
            });

        sub->AddBoolOption("Anti Melee", "", &player_anti_melee_bool, [] {
            Player_AntiMeleeFunction();
            });

        sub->AddBoolOption("Everyone Ignore", "", &player_everyone_ignore_bool, [] {
            Player_EveryoneIgnoreFunction();
            });

        sub->AddBoolOption("No Ragdoll", "", &player_no_ragdoll_bool, [] {
            Player_NoRagdollFunction();
            });

        /*sub->AddBoolOption("Climb Steep Slopes", "", &player_climb_steep_slopes_bool, [] {
            Player_ClimbSteepSlopesFunction();
            });
            */

        sub->AddBoolOption("Quick Skin", "", &player_quick_skin_bool, [] {
            Player_QuickSkinFunction();
            });

        sub->AddBoolOption("Always Show Cores", "", &player_always_show_cores_bool, [] {
            Player_AlwaysShowCoresFunction();
            });

        sub->AddBoolOption("Always Clean", "", &player_always_clean_bool, [] {
            Player_AlwaysCleanFunction();
            });

        sub->AddRegularOption("Clean", "", [] {
            Player_CleanFunction();
            });

       /* sub->AddRegularOption("Apply Dirt", "", [] {
            Player_ApplyDirtFunction();
            });
            */

        sub->AddRegularOption("Suicide", "", [] {
            Player_SuicideFunction();
            });

        });
}
