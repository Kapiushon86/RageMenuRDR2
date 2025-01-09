#pragma once

enum eSubmenuID : int
{
    Submenu_Invalid = -1,
    Submenu_main,

    // Player
    Submenu_player,
    Submenu_no_clip,
    Submenu_mount,
    Submenu_vehicle,
    Submenu_modifiers,
    Submenu_model,
    Submenu_model_changer,
    Submenu_effects,
    Submenu_effects_screen,
    Submenu_effects_particles,
    

    // Network
    Submenu_network,
    Submenu_players,

    // Recovery
    Submenu_recovery,
    Submenu_money,
    Submenu_add,
    Submenu_remove,

    // Weapons
    Submenu_weapons,

    // Teleport
    Submenu_teleport,

    // Spawner
    Submenu_spawner,
    Submenu_peds,
    Submenu_humans,
    Submenu_horses,
    Submenu_animals,
    Submenu_legendary_animals,
    Submenu_vehicles,

    // World
    Submenu_world,
    Submenu_time,
    Submenu_weather,

    // Misc
    Submenu_misc,
    Submenu_free_camera,
    Submenu_wav_player,
    Submenu_disables,
    Submenu_bypasses,

    // Settings
    Submenu_settings,
    Submenu_saving,
    Submenu_logging,

    // Credits
    Submenu_credits,
    Submenu_core,
    Submenu_ragemenu,
    Submenu_developers,
    Submenu_userinterface,

    // Other

    // Example
    Submenu_example,
    Submenu_examplesub
};
