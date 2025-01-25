#include "animals_functions.h"
#include "../../../Menu/Base/Submenus/Main/Spawner/animals.h" 
#include "../../Saving/States/Spawner/animals_default_states.h" 
#include <vector> 
#include <variant>
#include <string>
#include <tuple>
#include <optional>
#include <memory>

struct SpawnedPed {
    Ped ped;
    bool isInvincible;
    std::string customName;
};

std::vector<SpawnedPed> AnimalsspawnedPeds;

void Animals_InvincibilityFunction() {

}

void Animals_AliveFunction() {

}

void Animals_DeleteAllFunction() {
    for (const SpawnedPed& spawnedPed : AnimalsspawnedPeds) {
        if (ENTITY::DOES_ENTITY_EXIST((Entity)spawnedPed.ped)) {
            ENTITY::DELETE_ENTITY((Entity*)&spawnedPed.ped);
        }
    }
    AnimalsspawnedPeds.clear();
}

void Animals_DeleteLastFunction() {
    if (!AnimalsspawnedPeds.empty()) {
        SpawnedPed lastSpawnedPed = AnimalsspawnedPeds.back();
        if (ENTITY::DOES_ENTITY_EXIST((Entity)lastSpawnedPed.ped)) {
            ENTITY::DELETE_ENTITY((Entity*)&lastSpawnedPed.ped);
        }
        AnimalsspawnedPeds.pop_back();
    }
}

void Animals_variationFunction() {

}

Ped AnimalsspawnPed(const std::variant<std::string, Hash>& pedModelInput, float minDistance, float maxDistance, float offsetZ, int outfitNum, bool alive, bool invincible, const std::string& customName = "") {
    constexpr float PI = 3.14159265358979323846f;
    float randomDistance = minDistance + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxDistance - minDistance));
    Vector3 playerPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true, false);
    float randomAngle = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * PI;
    float spawnX = randomDistance * cos(randomAngle);
    float spawnY = randomDistance * sin(randomAngle);
    float finalX = playerPos.x + spawnX;
    float finalY = playerPos.y + spawnY;
    float finalZ = playerPos.z + offsetZ;

    Hash pedModel;
    std::string resolvedName;

    if (std::holds_alternative<std::string>(pedModelInput)) {
        resolvedName = std::get<std::string>(pedModelInput);
        pedModel = MISC::GET_HASH_KEY(resolvedName.c_str());
    }
    else {
        pedModel = std::get<Hash>(pedModelInput);
        resolvedName = customName.empty() ? "CustomModel" : customName;
    }

    STREAMING::REQUEST_MODEL(pedModel, true);
    while (!STREAMING::HAS_MODEL_LOADED(pedModel)) WAIT(0);

    Ped pedSpawn = PED::CREATE_PED(pedModel, finalX, finalY, finalZ, 0, 1, 1, 1, 1);
    float playerHeading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
    ENTITY::SET_ENTITY_HEADING(pedSpawn, playerHeading);

    PED::SET_PED_RANDOM_COMPONENT_VARIATION(pedSpawn, 1);

    ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(pedSpawn, 1);
    ENTITY::FREEZE_ENTITY_POSITION(pedSpawn, 0);
    STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(pedModel);

    if (!alive) {
        ENTITY::SET_ENTITY_HEALTH(pedSpawn, 0, 0);
    }
    else {
        ENTITY::SET_ENTITY_HEALTH(pedSpawn, 200, 0);
    }

    if (invincible && alive) {
        ENTITY::SET_ENTITY_INVINCIBLE(pedSpawn, true);
    }
    else {
        ENTITY::SET_ENTITY_INVINCIBLE(pedSpawn, false);
    }

    AnimalsspawnedPeds.push_back({ pedSpawn, invincible, resolvedName });
    return pedSpawn;
}

void AnimalsUpdatePedInvincibility(Ped ped, bool invincible) {
    if (ENTITY::DOES_ENTITY_EXIST((Entity)ped)) {
        ENTITY::SET_ENTITY_INVINCIBLE((Entity)ped, invincible);
    }
}

void AnimalToggleInvincibility(bool invincible) {
    for (SpawnedPed& spawnedPed : AnimalsspawnedPeds) {
        AnimalsUpdatePedInvincibility(spawnedPed.ped, invincible);
        spawnedPed.isInvincible = invincible;
    }
}

using Hash = std::uint32_t;

struct AnimalModelInfo {
    std::variant<std::string, Hash> modelIdentifier;
    std::string pedName;
    std::string customName;
    int outfitCount;

    AnimalModelInfo(const std::variant<std::string, Hash>& model,
        const std::string& ped,
        const std::string& custom,
        int outfits)
        : modelIdentifier(model), pedName(ped), customName(custom), outfitCount(outfits) {
    }

    AnimalModelInfo(Hash model,
        const std::string& ped,
        const std::string& custom,
        int outfits)
        : modelIdentifier(model), pedName(ped), customName(custom), outfitCount(outfits) {
    }

    AnimalModelInfo(const std::string& model,
        const std::string& ped,
        const std::string& custom,
        int outfits)
        : modelIdentifier(model), pedName(ped), customName(custom), outfitCount(outfits) {
    }

    AnimalModelInfo(Hash model,
        const std::string& ped,
        int outfits)
        : modelIdentifier(model), pedName(ped), customName(""), outfitCount(outfits) {
    }

    AnimalModelInfo(const std::string& model,
        const std::string& ped,
        int outfits)
        : modelIdentifier(model), pedName(ped), customName(""), outfitCount(outfits) {
    }
};

// I Use `reserve()` Here To Pre Allocate Memory For The Vector To Avoid Multiple Reallocations 
// As New Items Are Added. It Helps Improve Performance By Ensuring The Vector Doesn't Need To 
// Resize Itself Every Time A New Element Is Pushed Back.  
// It’s Okay To Reserve More Space Than The Actual Number Of Elements. It's Not Harmful As Long As The User Has Enough, 
// But I Avoid Reserving Too Much To Prevent Wasting Memory. The Vector Will Still Only Use As Much Space As Needed 
// Based On The Actual Elements Added.
// A Much Better Method Then What I Had Before.

static std::unique_ptr<std::vector<AnimalModelInfo>> AnimalsList = nullptr;

void InitializeAnimalsList() {
    if (AnimalsList == nullptr) {
        AnimalsList = std::make_unique<std::vector<AnimalModelInfo>>();
        AnimalsList->reserve(100);

        (1); AnimalsList->emplace_back(0x8F361781, "a_c_alligator_01", "", 4);
        (2); AnimalsList->emplace_back(0xA0B33A7B, "a_c_alligator_02", "", 1);
        (3); AnimalsList->emplace_back(0xB2C4DE9E, "a_c_alligator_03", "", 3);
        (4); AnimalsList->emplace_back(0x94DA69A0, "a_c_armadillo_01", "", 1);
        (5); AnimalsList->emplace_back(0xBA41697E, "a_c_badger_01", "", 3);
        (6); AnimalsList->emplace_back(0x28308168, "a_c_bat_01", "", 3);
        (7); AnimalsList->emplace_back(0x2B845466, "a_c_bearblack_01", "", 4);
        (8); AnimalsList->emplace_back(0xBCFD0E7F, "a_c_bear_01", "", 11);
        (9); AnimalsList->emplace_back(0x2D4B3F63, "a_c_beaver_01", "", 4);
        (10); AnimalsList->emplace_back(0xA27F49A3, "a_c_bighornram_01", "", 19);
        (11); AnimalsList->emplace_back(0x5E5A761C, "a_c_bluejay_01", "", 2);
        (12); AnimalsList->emplace_back(0xDE99DA6D, "a_c_boarlegendary_01", "", 1);
        (13); AnimalsList->emplace_back(0x78EBDA79, "a_c_boar_01", "", 4);
        (14); AnimalsList->emplace_back(0x8AF5C2A8, "a_c_buck_01", "", 6);
        (15); AnimalsList->emplace_back(0x5CC5E869, "a_c_buffalo_01", "", 16);
        (16); AnimalsList->emplace_back(0x15E9B494, "a_c_buffalo_tatanka_01", "", 1);
        (17); AnimalsList->emplace_back(0x0BAA25A3, "a_c_bull_01", "", 4);
        (18); AnimalsList->emplace_back(0x47E1D597, "a_c_californiacondor_01", "", 3);
        (19); AnimalsList->emplace_back(0x6A640A7B, "a_c_cardinal_01", "", 3);
        (20); AnimalsList->emplace_back(0x681E834B, "a_c_carolinaparakeet_01", "", 1);
        (21); AnimalsList->emplace_back(0x573201B8, "a_c_cat_01", "", 3);
        (22); AnimalsList->emplace_back(0xEE893817, "a_c_cedarwaxwing_01", "", 3);
        (23); AnimalsList->emplace_back(0x8506531D, "a_c_chicken_01", "", 3);
        (24); AnimalsList->emplace_back(0xA39125DC, "a_c_chipmunk_01", "", 1);
        (25); AnimalsList->emplace_back(0x846E8AF0, "a_c_cormorant_01", "", 2);
        (26); AnimalsList->emplace_back(0x056154F7, "a_c_cougar_01", "", 6);
        (27); AnimalsList->emplace_back(0xFCFA9E1E, "a_c_cow", "", 22);
        (28); AnimalsList->emplace_back(0x1CA6B883, "a_c_coyote_01", "", 7);
        (29); AnimalsList->emplace_back(0x868D0356, "a_c_crab_01", "", 3);
        (30); AnimalsList->emplace_back(0xDE608788, "a_c_cranewhooping_01", "", 2);
        (31); AnimalsList->emplace_back(0x96E9E689, "a_c_crawfish_01", "", 3);
        (32); AnimalsList->emplace_back(0x05DF8F2C, "a_c_crow_01", "", 1);
        (33); AnimalsList->emplace_back(0x423417A7, "a_c_deer_01", "", 6);
        (34); AnimalsList->emplace_back(0x40E01848, "a_c_dogamericanfoxhound_01", "", 5);
        (35); AnimalsList->emplace_back(0xAE6C236C, "a_c_dogaustraliansheperd_01", "", 3);
        (36); AnimalsList->emplace_back(0x2552B009, "a_c_dogbluetickcoonhound_01", "", 8);
        (37); AnimalsList->emplace_back(0xC25FE171, "a_c_dogcatahoulacur_01", "", 7);
        (38); AnimalsList->emplace_back(0xE8C446CB, "a_c_dogchesbayretriever_01", "", 3);
        (39); AnimalsList->emplace_back(0x40D2BCBC, "a_c_dogcollie_01", "", 3);
        (40); AnimalsList->emplace_back(0xC5C5D255, "a_c_doghobo_01", "", 1);
        (41); AnimalsList->emplace_back(0x801131EF, "a_c_doghound_01", "", 8);
        (42); AnimalsList->emplace_back(0x62F7C1B3, "a_c_doghusky_01", "", 3);
        (43); AnimalsList->emplace_back(0xAD779EB4, "a_c_doglab_01", "", 7);
        (44); AnimalsList->emplace_back(0xCA89FC80, "a_c_doglion_01", "", 2);
        (45); AnimalsList->emplace_back(0x40CAC0E7, "a_c_dogpoodle_01", "", 3);
        (46); AnimalsList->emplace_back(0x5EDF32B4, "a_c_dogrufus_01", "", 1);
        (47); AnimalsList->emplace_back(0x3B313FCE, "a_c_dogstreet_01", "", 3);
        (48); AnimalsList->emplace_back(0x387E129A, "re_lostdog_dogs_01", "", 4);
        (49); AnimalsList->emplace_back(0x69A37A7B, "a_c_donkey_01", "", 8);
        (50); AnimalsList->emplace_back(0xC42E08CB, "a_c_duck_01", "", 3);
        (51); AnimalsList->emplace_back(0x57027587, "a_c_eagle_01", "", 4);
        (52); AnimalsList->emplace_back(0x31952A0B, "a_c_egret_01", "", 3);
        (53); AnimalsList->emplace_back(0x87895317, "a_c_elk_01", "", 8);
        (54); AnimalsList->emplace_back(0x6F4C2A6C, "a_c_fishbluegil_01_ms", "", 2);
        (55); AnimalsList->emplace_back(0x81D4FAB9, "a_c_fishbluegil_01_sm", "", 2);
        (56); AnimalsList->emplace_back(0x29F1CB9D, "a_c_fishbullheadcat_01_ms", "", 2);
        (57); AnimalsList->emplace_back(0x5905A300, "a_c_fishbullheadcat_01_sm", "", 2);
        (58); AnimalsList->emplace_back(0xB97D1BFD, "a_c_fishchainpickerel_01_ms", "", 2);
        (59); AnimalsList->emplace_back(0x0FBEB3FF, "a_c_fishchainpickerel_01_sm", "", 2);
        (60); AnimalsList->emplace_back(0x5BAEE06E, "a_c_fishchannelcatfish_01_lg", "", 3);
        (61); AnimalsList->emplace_back(0x876CAA75, "a_c_fishchannelcatfish_01_xl", "", 2);
        (62); AnimalsList->emplace_back(0xEE111F34, "a_c_fishlakesturgeon_01_lg", "", 4);
        (63); AnimalsList->emplace_back(0x1BA2A2E8, "a_c_fishlargemouthbass_01_lg", "", 2);
        (64); AnimalsList->emplace_back(0x0750FD65, "a_c_fishlargemouthbass_01_ms", "", 2);
        (65); AnimalsList->emplace_back(0xD5931B3F, "a_c_fishlongnosegar_01_lg", "", 6);
        (66); AnimalsList->emplace_back(0xA3660A8D, "a_c_fishmuskie_01_lg", "", 5);
        (67); AnimalsList->emplace_back(0x298C8600, "a_c_fishnorthernpike_01_lg", "", 7);
        (68); AnimalsList->emplace_back(0xE50B98F0, "a_c_fishperch_01_ms", "", 2);
        (69); AnimalsList->emplace_back(0x2A1C1C20, "a_c_fishperch_01_sm", "", 1);
        (70); AnimalsList->emplace_back(0x080814B2, "a_c_fishrainbowtrout_01_lg", "", 2);
        (71); AnimalsList->emplace_back(0x1D373E24, "a_c_fishrainbowtrout_01_ms", "", 1);
        (72); AnimalsList->emplace_back(0xF1813D52, "a_c_fishredfinpickerel_01_ms", "", 2);
        (73); AnimalsList->emplace_back(0x1E9790B6, "a_c_fishredfinpickerel_01_sm", "", 2);
        (74); AnimalsList->emplace_back(0x89E3C580, "a_c_fishrockbass_01_ms", "", 2);
        (75); AnimalsList->emplace_back(0x00173415, "a_c_fishrockbass_01_sm", "", 4);
        (76); AnimalsList->emplace_back(0x206B229A, "a_c_fishsalmonsockeye_01_lg", "", 2);
        (77); AnimalsList->emplace_back(0x657C2DBF, "a_c_fishsalmonsockeye_01_ml", "", 1);
        (78); AnimalsList->emplace_back(0x027C67C1, "a_c_fishsalmonsockeye_01_ms", "", 2);
        (79); AnimalsList->emplace_back(0x8FACF62D, "a_c_fishsmallmouthbass_01_lg", "", 2);
        (80); AnimalsList->emplace_back(0x6EE63594, "a_c_fishsmallmouthbass_01_ms", "", 2);

    }
}

void AddAnimalsSpawnOptions(Submenu* sub) {
    InitializeAnimalsList();

    for (const auto& person : *AnimalsList) {
        std::string displayName = !person.customName.empty() ? person.customName : person.pedName;

        sub->AddRegularOption(displayName.c_str(), "", [person]() {
            int outfitNum = 0;

            if (animals_variation_bool && person.outfitCount > 0) {
                outfitNum = rand() % person.outfitCount;
            }

            bool isAlive = animals_alive_bool;
            bool isInvincible = animals_invincibility_bool;

            if (std::holds_alternative<std::string>(person.modelIdentifier)) {
                const std::string& modelName = std::get<std::string>(person.modelIdentifier);
                Ped spawnedPerson = AnimalsspawnPed(modelName, 1.5f, 3.0f, 0.0f, outfitNum, isAlive, isInvincible);
                AnimalsUpdatePedInvincibility(spawnedPerson, isInvincible);
            }
            else if (std::holds_alternative<Hash>(person.modelIdentifier)) {
                Hash modelHash = std::get<Hash>(person.modelIdentifier);
                Ped spawnedPerson = AnimalsspawnPed(modelHash, 1.5f, 3.0f, 0.0f, outfitNum, isAlive, isInvincible, person.customName.empty() ? person.pedName : person.customName);
                AnimalsUpdatePedInvincibility(spawnedPerson, isInvincible);
            }
            });
    }
}