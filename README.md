INTRODUCTION
------------

RageMenuRDR2 is a newly open-source project developed by Kapiushon and JJ. This Red Dead Redemption 2 mod menu is designed to seamlessly integrate with the game, featuring an in-game UI that mirrors the authentic RDR2 look and feel.

BUILT ON A SOLID FOUNDATION
---------------------------

RageMenu is built on the RDR2 Native Menu Base by Halen84, with numerous modifications and improvements that enhance both functionality and usability. https://github.com/Halen84/RDR2-Native-Menu-Base

FEATURES
--------

RageMenu is an all-purpose mod focused on quality of life and gameplay enhancements, making the game’s story and exploration even more enjoyable.

A full list of features can be found on our nexus page https://www.nexusmods.com/reddeadredemption2/mods/5244/?tab=description

OUR GOAL
--------

RageMenu was created to deliver a straightforward, uncluttered experience, offering essential features without overcomplicating the menu or UI with unnecessary additions. Whether you're seeking gameplay tweaks or a smoother modding experience, RageMenu is built with simplicity and usability in mind. 

OPEN SOURCE
-----------

As of January 9, 2025, RageMenu has been made open source (mostly). We welcome suggestions and code improvements for public builds, which can be submitted through our Discord in the development category or by dming me or jj.

If you believe something is not coded optimally or could be improved, we encourage you to inspire us with your ideas.

And RageMenu will still be receiving many updates, becoming open source will not change this.

FOLDER STRUCTURE
----------------

Ui/Options - Contains all option types

Ui/ - Contains all ui elements drawing, writing sprites, menu version, etc basically everything you see. Menuversion.h is where current version is defined, drawing.cpp handles most of the drawing but some other are done throughout ui and SubmenuIDs contains all the submenu ids which are needed when creating a new submenu.

Thirdparty/ - Contains all third party uses, as of now its only discord presence.

Menu/Base/Submenu/Main/ - Contains all the actual features not the function but the features itself and then functions are called under those features.

Utils/Config - All config related files, so all folders and files created here loading ini config stuff some logging etc.

Utils/Saving/States - Inside here you will find a bunch of submenu folders this is where the default states of each file is located for bool and vector features, .cpp is where default states are stored .h is where they are defined.

Utils/Functions - There will be many folder submenus here inside will also be many files in most, there will be an cpp file and an h file the functions cpp files contain all the function logic for all the features the h defines all the functions, additionally inside each of these submenu folders is another folder called UpdateFeaturesLoop. These are where features are stored that will run every frame this is called in script.cpp and put in every submenu folder to make easier and more organized.

You will also see many folders and files or just code that dosnt really have anything like blank features with no logic etc these are mostly place holders or planned features that are in development or planned development features and just have not been done yet.

Overall my setup and folder structure is well organized and neatly kept and you should have no probelm finding everything.

RIGHTS
------

This menu's source code is provided for transparency, learning purposes, and to assure users that it is safe and free of malicious content. However, strict rules still apply:

1. No Unauthorized Uploads  
   - You are strictly prohibited from uploading this mod or its source code to any website, repository, or platform without explicit written permission from the original authors.

2. No Unauthorized Modifications  
   - Modifying this source code and re-uploading it under a new name, branding, or as part of another project is strictly forbidden. This includes changes intended to disguise the original authorship.

3. Not a Base for Other Menus  
   - This source code is not intended to be used as a base for creating other mod menus. While it is derived from Halen84's RDR2 Native Menu Base, it has been heavily modified and adapted. If you require a menu base, please refer to Halen84's original base at https://github.com/Halen84/RDR2-Native-Menu-Base?tab=MIT-1-ov-file and follow its licensing terms.

4. No Redistribution or Repurposing  
   - Open source does not grant permission to steal, copy, or repurpose this code for your own projects. Any such use without explicit authorization will be treated as a violation of these rights.

5. Educational Use Only  
   - The source code is provided solely for educational purposes, to demonstrate how the menu works, and to give developers ideas or inspiration. It is not intended to be a template, sample, or starting point for other projects.

6. No Commercial Use  
   - This menu and its releases are free for everyone to use, but the source code is not. The source code and its derivatives may not be used for any commercial purposes, including selling, licensing, monetizing, or incorporating into any project intended for profit. Furthermore, the source code must not be repackaged or sold, whether as part of another menu, standalone product, or any other form. Any violation of this term is strictly prohibited.

7. Respect the Creators  
   - All credits and acknowledgments to the original authors and contributors must remain intact. Removing or altering these is strictly prohibited.

8. Ask for Clarification  
   - If you are unsure about any specific right or intended use, you must seek permission from the authors before proceeding. Ignorance of these terms will not be considered an excuse for violation.


By accessing or using this source code, you agree to adhere to these strict terms and conditions.

SO WHAT CAN I DO WITH THE SOURCE CODE?
-------------------------------------


The RageMenu source code is open for you to explore and analyze. Here's how you can engage with it:

Examine the Codebase

- Review the entire codebase, including its structure, features, and implementations. Some parts of the source code have been intentionally left out for security and developmental purposes, but everything essential to understanding the menu is included.

Provide Feedback

- If you identify areas that could be optimized or improved, share your suggestions with us. Your input is valuable and can help make the menu even better.

Suggest New Features or Enhancements

- Have ideas for features or functionality that could improve the menu? Propose them in our Discord's development category or via direct messages to the authors.
  
Improve Existing Features

- If you find opportunities to enhance the functionality or performance of existing features, submit your ideas or proposed changes.
  
Please note that while feedback and contributions are welcome, any modifications or use of the source code must adhere to the rules outlined in the RIGHTS section. Unauthorized redistribution, repurposing, or misuse of the source code is strictly prohibited.

![image](https://github.com/user-attachments/assets/59c83475-5fde-42ce-b0f2-0eb22adf35c1)

