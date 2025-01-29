#include "settings_functions.h"
#include "../../../Menu/Base/Submenus/Main/Settings/settings.h" 
#include "../../Saving//States/Settings/settings_default_states.h"
#include "../../../UI/Drawing.h"

// Player

#include "../../../Menu/Base/Submenus/Main/Player/player.h"
#include "../../../Menu/Base/Submenus/Main/Player/no_clip.h"
#include "../../../Menu/Base/Submenus/Main/Player/mount.h"
#include "../../../Menu/Base/Submenus/Main/Player/vehicle.h"
#include "../../../Menu/Base/Submenus/Main/Player/modifiers.h"

// Recovery

#include "../../../Menu/Base/Submenus/Main/Recovery/recovery.h"
#include "../../../Menu/Base/Submenus/Main/Recovery/money.h"
#include "../../../Menu/Base/Submenus/Main/Recovery/add.h"

// Weapons

#include "../../../Menu/Base/Submenus/Main/Weapons/weapons.h"

// Teleport

#include "../../../Menu/Base/Submenus/Main/Teleport/teleport.h"

// Spawner

#include "../../../Menu/Base/Submenus/Main/Spawner/spawner.h"
#include "../../../Menu/Base/Submenus/Main/Spawner/peds.h"
#include "../../../Menu/Base/Submenus/Main/Spawner/humans.h"
#include "../../../Menu/Base/Submenus/Main/Spawner/humans_males.h"
#include "../../../Menu/Base/Submenus/Main/Spawner/humans_females.h"
#include "../../../Menu/Base/Submenus/Main/Spawner/animals.h"

// World

#include "../../../Menu/Base/Submenus/Main/World/world.h"
#include "../../../Menu/Base/Submenus/Main/World/time.h"
#include "../../../Menu/Base/Submenus/Main/World/weather.h"

// Misc

#include "../../../Menu/Base/Submenus/Main/Misc/misc.h"
#include "../../../Menu/Base/Submenus/Main/Misc/free_camera.h"
#include "../../../Menu/Base/Submenus/Main/Misc/disables.h"
#include "../../../Menu/Base/Submenus/Main/Misc/wav_player.h"
#include "../../../Menu/Base/Submenus/Main/Misc/links.h"

// Settings

#include "../../../Menu/Base/Submenus/Main/Settings/saving.h"
#include "../../../Menu/Base/Submenus/Main/Settings/logging.h"

void Settings_UnloadMenuFunction() {
   
}

void Settings_LeftPositionFunction() {
    Drawing::uiBackground::PositionX = settings_left_position_bool ? 25.0f : 1850.0f;
}

#define COLOR_MAIN_BODY 11,11,11,210

void SettingsFullAlphaFunction() {
    if (settings_full_alpha_bool) {
        Drawing::DrawSprite("generic_textures", "inkroller_1a",
            BACKGROUND_POSITION_X, BACKGROUND_POSITION_Y,
            BACKGROUND_WIDTH, BACKGROUND_HEIGHT,
            0, COLOR_MAIN_BODY, false);
    }
    else {
        Drawing::DrawSprite("generic_textures", "inkroller_1a",
            BACKGROUND_POSITION_X, BACKGROUND_POSITION_Y,
            BACKGROUND_WIDTH, BACKGROUND_HEIGHT,
            0, COLOR_MAIN_BODY, false);
    }
}

void Settings_ShowScrollerFunction() {

}

void Settings_ShowSubmenuIndicatorsFunction() {

}

void Settings_ShowCheckBoxesFunction() {

}

void  Settings_ShowXForFalseValuesFunction() {

}

void Settings_ShowToolTipsFunction() {

}

void Settings_ShowOptionCouterFunction() {

}

void Settings_ShowEmptyOptionsFunction() {

}

void Settings_ShowTitleFunction() {

}

void Settings_ShowHeaderFunction() {

}

void Settings_ShowSubHeaderFunction() {

}

void Settings_ShowBreadCrumbsFunction() {

    // Player

    g_PlayerSubmenu->Init();
    g_NoclipSubmenu->Init();
    g_MountSubmenu->Init();
    g_VehicleSubmenu->Init();
    g_ModifiersSubmenu->Init();

    // Recovery
 
    g_RecoverySubmenu->Init();
    g_MoneySubmenu->Init();
    g_AddSubmenu->Init();

    // Weapons

    g_WeaponsSubmenu->Init();

    // Teleport

    g_TeleportSubmenu->Init();

    // Spawner

    g_SpawnerSubmenu->Init();
    g_PedsSubmenu->Init();
    g_HumansSubmenu->Init();
    g_HumansMalesSubmenu->Init();
    g_HumansFemalesSubmenu->Init();
    g_AnimalsSubmenu->Init();

    // World

    g_WorldSubmenu->Init();
    g_TimeSubmenu->Init();
    g_WeatherSubmenu->Init();

    // Misc

    g_MiscSubmenu->Init();
    g_FreecameraSubmenu->Init();
    g_DisablesSubmenu->Init();
    g_Wav_PlayerSubmenu->Init();
    g_LinksSubmenu->Init();

    // Settings

    g_SettingsSubmenu->Init();
    g_SavingSubmenu->Init();
    g_LoggingSubmenu->Init();
}

void Settings_ShowVersionFunction() {

}

void Settings_ShowOutlinersFunction() {

}

void Settings_ShowFooterFunction() {

}