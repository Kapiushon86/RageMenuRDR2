INTRODUCTION

RageMenuRDR2 is a newly open-source project developed by Kapiushon and JJ. This Red Dead Redemption 2 mod menu is designed to seamlessly integrate with the game, featuring an in-game UI that mirrors the authentic RDR2 look and feel.

BUILT ON A SOLID FOUNDATION

RageMenu is built on the RDR2 Native Menu Base by Halen84, with numerous modifications and improvements that enhance both functionality and usability. https://github.com/Halen84/RDR2-Native-Menu-Base

FEATURES

RageMenu is an all-purpose mod focused on quality of life and gameplay enhancements, making the game’s story and exploration even more enjoyable.

CURRENT FEATURES

[MAIN]
------

>>> Player
>>> Recovery
>>> Weapons
>>> World
>>> Misc
>>> Settings

[PLAYER]
--------

>>> No Clip
    - No Clip (Bool)
    - Use Yaw Rotation (Bool)
    - Freeze Entity (Bool)

>>> Mount
    - Preference (Vector)
    - Invincibility (Bool)
    - Invisibility (Bool)
    - Infinite Stamina (Bool)
    - Refill All Cores (Action)
    - Refill Health Core (Action)
    - Refill Stamina Core (Action)
    - Fearless (Bool)
    - No Ragdoll (Bool)
    - Always Show Cores (Bool)
    - Always Clean (Bool)
    - Clean (Action)
    - Clear Pelts (Action)
    - Suicide (Action)
    - Delete (Action)

>>> Vehicle
    - Invincibility (Bool)
    - Invisibility (Bool)
    - Disable Knock Off (Bool)
    - Always Clean (Bool)
    - Clean (Action)
    - Fix (Action)
    - Suicide (Action)
    - Delete (Action)

>>> Modifiers
    - Infinite Stamina (Bool)
    - Infinite Dead Eye (Bool)
    - Infinite Eagle Eye (Bool)
    - Refill All Cores (Action)
    - Refill Health Core (Action)
    - Refill Stamina Core (Action)
    - Refill Dead Eye Core (Action)
    -------------------------------

    - Invincibility (Bool)
    - Invisibility (Bool)
    - Lawless (Bool)
    - Super Jump (Bool)
    - Super Punch (Bool)
    - One Hit Ko (Bool)
    - Anti Melee (Bool)
    - Everyone Ignore (Bool)
    - No Ragdoll (Bool)
    - Quick Skin (Bool)
    - Always Show Cores (Bool)
    - Always Clean (Bool)
    - Clean (Action)
    - Suicide (Action)

[RECOVERY]
----------

>>> Money
    >>> Add
        - 10k Loop (Bool)
        - Add 10k (Action)

[WEAPONS]
---------

>>> Weapons
    - Lock All Weapons (Action)
    - Unlock All Weapons (Action)
    - Add All Weapons (Action)
    - Remove All Weapons (Action)
    - Add All Ammo (Action)
    - Infinite Ammo (Bool)
    - Infinite Clip (Bool)
    - One Shot Kill (Bool)
    - Auto Cock (Bool)
    - No Spread (Bool)
    - Always Clean (Bool)
    - Clean (Action)

[WORLD]
-------

>>> Time
    - Freeze Time (Bool)
    - Loop Time (Bool)
    - Sync With System (Bool)
    - Random Time (Action)
    - 15 different preset time options (Action)

>>> Weather
    - Freeze Weather (Bool)
    - Loop Weather (Bool)
    - Ground Snow (Bool)
    - Random Weather (Action)
    - 22 different preset weather options (Action)

[MISC]
------

>>> Free Camera
    - Free Camera (Bool)
    - Use Yaw Rotation (Bool)
    - Freeze Entity (Bool)
    - Entity Invisibility (Bool)

>>> Wav Player
    - Stop (Action)
    - Input Any ".Wav" file (Action)

>>> Disables
    - Disable Help Text (Bool)
    - Disable Location Info (Bool)
    - Disable Radar When Menu Is Open (Bool)
    - Disable Horse Whistle On Gamepad (Bool)
    -----------------------------------------

    - Seasonal Greetings (Bool)
    - Real Alt F4 (Bool)
    - Alt F4 (Action)
    - Discord Presence (Bool)
    - Reveal Map (Action)
    - Unreveal Map (Action)
    - Discord Link (Action)

[SETTINGS]
----------

>>> Saving
    - Auto Save (Bool)
    - Manual Save (Action)

OUR GOAL

RageMenu was created to deliver a straightforward, uncluttered experience, offering essential features without overcomplicating the menu or UI with unnecessary additions. Whether you're seeking gameplay tweaks or a smoother modding experience, RageMenu is built with simplicity and usability in mind. 

OPEN SOURCE

As of January 9, 2025, RageMenu has been made open source (mostly). We welcome suggestions and code improvements for public builds, which can be submitted through our Discord.

If you believe something is not coded optimally or could be improved, we encourage you to inspire us with your ideas.

FOLDER STRUCTURE

Ui/Options - Contains all option types

Ui/ - Contains all ui elements drawing, writing sprites, menu version, etc basically everything you see. menu_version.h is where current version is defined, drawing.cpp handles most of the drawing but some other are done throughout ui and SubmenuIDs contains all the submenu ids which are needed when creating a new submenu.

Thirdparty/ - Contains all third party uses, as of now its only discord presence.

Menu/Base/Submenu/Main/ - Contains all the actual features not the function but the features itself and then functions are called under those features.

Utils/Config - All config related files, so all folders and files created here loading ini config stuff some logging etc.

Utils/Saving/States - Inside here you will find a bunch of submenu folders this is where the default states of each file is located for bool and vector features, .cpp is where default states are stored .h is where they are defined.

Utils/Functions - There will be many folder submenus here inside will also be many files in most, there will be an cpp file and an h file the functions cpp files contain all the function logic for all the features the h defines all the functions, additionally inside each of these submenu folders is another folder called UpdateFeaturesLoop. These are where features are stored that will run every frame this is called in script.cpp and put in every submenu folder to make easier and more organized.

You will also see many folders and files or just code that dosnt really have anything like blank features with no logic etc these are mostly place holders or planned features that are in development or planned development features and just have not been done yet.

Overall my setup and folder structure is well organized and neatly kept and you should have no probelm finding everything.

![image](https://github.com/user-attachments/assets/59c83475-5fde-42ce-b0f2-0eb22adf35c1)

