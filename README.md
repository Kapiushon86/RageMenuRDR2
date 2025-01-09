INTRODUCTION

RageMenuRDR2 is a newly open-source project developed by Kapiushon and JJ. This Red Dead Redemption 2 mod menu is designed to seamlessly integrate with the game, featuring an in-game UI that mirrors the authentic RDR2 look and feel.

BUILT ON A SOLID FOUNDATION

RageMenu is built on the RDR2 Native Menu Base by Halen84, with numerous modifications and improvements that enhance both functionality and usability. https://github.com/Halen84/RDR2-Native-Menu-Base

FEATURES

RageMenu is an all-purpose mod focused on quality of life and gameplay enhancements, making the game’s story and exploration even more enjoyable. It includes essential features such as:

God Mode,
Super Jump,
Lawless Mode,
Quick Skin,
No Clip
A complete list of features is available on our Nexus Mods page. https://www.nexusmods.com/reddeadredemption2/mods/5244/?tab=description

OUR GOAL

RageMenu was created to deliver a straightforward, uncluttered experience, offering essential features without overcomplicating the menu or UI with unnecessary additions. Whether you're seeking gameplay tweaks or a smoother modding experience, RageMenu is built with simplicity and usability in mind. 

OPEN SOURCE

As of January 9, 2025, RageMenu has been made open source. We welcome suggestions and code improvements for public builds, which can be submitted through our Discord.

If you believe something is not coded optimally or could be improved, we encourage you to inspire us with your ideas.

FOLDER STRUCTURE

Ui/Options - Contains all option types

Ui/ - Contains all ui elements drawing, writing sprites, menu version, etc basically everything you see. menu_version.h is where current version is defined, drawing.cpp handles most of the drawing but some other are done throughout ui and SubmenuIDs contains all the submenu ids which are needed when creating a new submenu.

Utils/Config - All config related files, so all folders and files created here loading ini config stuff some logging etc.

Utils/Saving/States - Inside here you will find a bunch of submenu folders this is where the default states of each file is located for bool and vector features, .cpp is where default states are stored .h is where they are defined.

Utils/Functions - There will be many folder submenus here inside will also be many files in most, there will be an cpp file and an h file the functions cpp files contain all the function logic for all the features the h defines all the functions, additionally inside each of these submenu folders is another folder called UpdateFeaturesLoop. These are where features are stored that will run every frame this is called in script.cpp and put in every submenu folder to make easier and more organized.

You will also see many folders and files or just code that dosnt really have anything like blank features with no logic etc these are mostly place holders or planned features that are in development or planned development features and just have not been done yet.
