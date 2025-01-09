#include "humans.h"
#include <vector>
#include <string>
#include <cmath>
#include "../../../../../Utils/Saving/States/Spawner/humans_default_states.h"
#include "../../../../../Utils/Functions/Spawner/humans_functions.h"

Ped spawnPed(Hash pedModel, float minDistance, float maxDistance, float offsetZ);

CHumansSubmenu::eHumansSubmenuID Submenu_Humans = CHumansSubmenu::Submenu_Humans;
CHumansSubmenu* g_HumansSubmenu = nullptr;

void CHumansSubmenu::Init() {
    const int submenuPriority = 8;

    g_Menu->AddSubmenu("RageMenu", "Humans", Submenu_humans, submenuPriority, [](Submenu* sub) {
        std::vector<std::pair<std::string, Hash>> peopleList = {
            {"cs_gavin", 0x4C5C60B2},
        };

        size_t middlePeopleIndex = peopleList.size() / 2;

        for (size_t j = 0; j < peopleList.size(); ++j) {
            sub->AddRegularOption(peopleList[j].first.c_str(), "", [person = peopleList[j]]() {
                Vector3 playerPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true, false);
                float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());

                Ped spawnedPerson = spawnPed(person.second, 3.0f, 6.0f, 0.0f);

                if (ENTITY::DOES_ENTITY_EXIST(spawnedPerson)) {
                    // Handle the successfully 
                }
                else {
                    // Handle failure 
                }
                });
        }
        });
}