#include "humans_males_functions.h"
#include "../../../Menu/Base/Submenus/Main/Spawner/humans_males.h"
#include "../../Saving/States/Spawner/humans_males_default_states.h"
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

std::vector<SpawnedPed> MalesspawnedPeds;

void HumanMales_InvincibilityFunction() {

}

void HumanMales_AliveFunction() {

}

void HumanMales_DeleteAllFunction() {
    for (const SpawnedPed& spawnedPed : MalesspawnedPeds) {
        if (ENTITY::DOES_ENTITY_EXIST((Entity)spawnedPed.ped)) {
            ENTITY::DELETE_ENTITY((Entity*)&spawnedPed.ped);
        }
    }
    MalesspawnedPeds.clear();
}

void HumanMales_DeleteLastFunction() {
    if (!MalesspawnedPeds.empty()) {
        SpawnedPed lastSpawnedPed = MalesspawnedPeds.back();
        if (ENTITY::DOES_ENTITY_EXIST((Entity)lastSpawnedPed.ped)) {
            ENTITY::DELETE_ENTITY((Entity*)&lastSpawnedPed.ped);
        }
        MalesspawnedPeds.pop_back();
    }
}

void HumanMales_variationFunction() {

}

Ped MalesspawnPed(const std::variant<std::string, Hash>& pedModelInput, float minDistance, float maxDistance, float offsetZ, int outfitNum, bool alive, bool invincible, const std::string& customName = "") {
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

    MalesspawnedPeds.push_back({ pedSpawn, invincible, resolvedName });
    return pedSpawn;
}

void MalesUpdatePedInvincibility(Ped ped, bool invincible) {
    if (ENTITY::DOES_ENTITY_EXIST((Entity)ped)) {
        ENTITY::SET_ENTITY_INVINCIBLE((Entity)ped, invincible);
    }
}

void MaleToggleInvincibility(bool invincible) {
    for (SpawnedPed& spawnedPed : MalesspawnedPeds) {
        MalesUpdatePedInvincibility(spawnedPed.ped, invincible);
        spawnedPed.isInvincible = invincible;
    }
}

using Hash = std::uint32_t;

struct MaleModelInfo {
	std::variant<std::string, Hash> modelIdentifier;
	std::string pedName;
	std::string customName;
	int outfitCount;

	MaleModelInfo(const std::variant<std::string, Hash>& model,
		const std::string& ped,
		const std::string& custom,
		int outfits)
		: modelIdentifier(model), pedName(ped), customName(custom), outfitCount(outfits) {
	}

	MaleModelInfo(Hash model,
		const std::string& ped,
		const std::string& custom,
		int outfits)
		: modelIdentifier(model), pedName(ped), customName(custom), outfitCount(outfits) {
	}

	MaleModelInfo(const std::string& model,
		const std::string& ped,
		const std::string& custom,
		int outfits)
		: modelIdentifier(model), pedName(ped), customName(custom), outfitCount(outfits) {
	}

	MaleModelInfo(Hash model,
		const std::string& ped,
		int outfits)
		: modelIdentifier(model), pedName(ped), customName(""), outfitCount(outfits) {
	}

	MaleModelInfo(const std::string& model,
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

static std::unique_ptr<std::vector<MaleModelInfo>> MaleHumansList = nullptr;

void InitializeMaleHumansList() {
    if (MaleHumansList == nullptr) {
        MaleHumansList = std::make_unique<std::vector<MaleModelInfo>>();
        MaleHumansList->reserve(64); 

        (1); MaleHumansList->emplace_back(0xD076C393, "a_m_m_armcholeracorpse_01", "", 38);
        (2); MaleHumansList->emplace_back(0xB5771CFC, "a_m_m_armdeputyresident_01", "", 56);
        (3); MaleHumansList->emplace_back(0xCF7E73BE, "a_m_m_armtownfolk_01", "", 49);
        (4); MaleHumansList->emplace_back(0xC137D731, "a_m_m_armtownfolk_02", "", 60);
        (5); MaleHumansList->emplace_back(0x37DAA98A, "a_m_m_asbboatcrew_01", "", 30);
        (6); MaleHumansList->emplace_back(0x9C00E2A0, "a_m_m_asbdeputyresident_01", "", 21);
        (7); MaleHumansList->emplace_back(0x68A1DDE7, "a_m_m_asbminer_01", "", 61);
        (8); MaleHumansList->emplace_back(0x3E500944, "a_m_m_asbminer_02", "", 42);
        (9); MaleHumansList->emplace_back(0x50ABADFB, "a_m_m_asbminer_03", "", 81);
        (10); MaleHumansList->emplace_back(0x19E7406F, "a_m_m_asbminer_04", "", 69);
        (11); MaleHumansList->emplace_back(0x0B54641C, "a_m_m_asbtownfolk_01", "", 86);
        (12); MaleHumansList->emplace_back(0xA5E02A13, "a_m_m_asbtownfolk_01_laborer", "", 70);
        (13); MaleHumansList->emplace_back(0x613A4B8E, "a_m_m_bivfancydrivers_01", "", 10);
        (14); MaleHumansList->emplace_back(0x0D8C9D0B, "a_m_m_bivfancytravellers_01", "", 21);
        (15); MaleHumansList->emplace_back(0x4ADABFBA, "a_m_m_bivroughtravellers_01", "", 41);
        (16); MaleHumansList->emplace_back(0x9384F640, "a_m_m_bivworker_01", "", 29);
        (17); MaleHumansList->emplace_back(0x5B91D27E, "a_m_m_blwforeman_01", "", 35);
        (18); MaleHumansList->emplace_back(0xC509B26F, "a_m_m_blwlaborer_01", "", 35);
        (19); MaleHumansList->emplace_back(0xDBC6DFE9, "a_m_m_blwlaborer_02", "", 45);
        (20); MaleHumansList->emplace_back(0x41907533, "a_m_m_blwobesemen_01", "", 3);
        (21); MaleHumansList->emplace_back(0xD10CE853, "a_m_m_blwtownfolk_01", "", 77);
        (22); MaleHumansList->emplace_back(0x3CF00F0B, "a_m_m_blwupperclass_01", "", 85);
        (23); MaleHumansList->emplace_back(0xE232B9EF, "a_m_m_btchillbilly_01", "", 42);
        (24); MaleHumansList->emplace_back(0x002A0F51, "a_m_m_btcobesemen_01", "", 1);
        (25); MaleHumansList->emplace_back(0x70B728D7, "a_m_m_bynfancydrivers_01", "", 10);
        (26); MaleHumansList->emplace_back(0xECBDF082, "a_m_m_bynfancytravellers_01", "", 20);
        (27); MaleHumansList->emplace_back(0x7D65D747, "a_m_m_bynroughtravellers_01", "", 40);
        (28); MaleHumansList->emplace_back(0x3B777AC0, "a_m_m_bynsurvivalist_01", "", 15);
        (29); MaleHumansList->emplace_back(0xC7458219, "a_m_m_cardgameplayers_01", "", 84);
        (30); MaleHumansList->emplace_back(0x5A3ABACE, "a_m_m_chelonian_01", "", 24);
        (31); MaleHumansList->emplace_back(0xDB5C4A62, "a_m_m_deliverytravelers_cool_01", "", 20);
        (32); MaleHumansList->emplace_back(0xA56A4C3D, "a_m_m_deliverytravelers_warm_01", "", 20);
        (33); MaleHumansList->emplace_back(0xD4B37D8A, "a_m_m_dominoesplayers_01", "", 18);
        (34); MaleHumansList->emplace_back(0xE5CED83E, "a_m_m_emrfarmhand_01", "", 20);
        (35); MaleHumansList->emplace_back(0x570B9957, "a_m_m_familytravelers_cool_01", "", 20);
        (36); MaleHumansList->emplace_back(0xEF53FC1C, "a_m_m_familytravelers_warm_01", "", 20);
        (37); MaleHumansList->emplace_back(0x584626EE, "a_m_m_farmtravelers_cool_01", "", 20);
        (38); MaleHumansList->emplace_back(0x2F9417F1, "a_m_m_farmtravelers_warm_01", "", 20);
        (39); MaleHumansList->emplace_back(0x18E143CA, "a_m_m_fivefingerfilletplayers_01", "", 12);
        (40); MaleHumansList->emplace_back(0x0DB7B411, "a_m_m_foreman", "", 10);
        (41); MaleHumansList->emplace_back(0x8DABAE42, "a_m_m_gamhighsociety_01", "", 40);
        (42); MaleHumansList->emplace_back(0x542A035C, "a_m_m_grifancydrivers_01", "", 10);
        (43); MaleHumansList->emplace_back(0x761D319E, "a_m_m_grifancytravellers_01", "", 20);
        (44); MaleHumansList->emplace_back(0x97273585, "a_m_m_griroughtravellers_01", "", 40);
        (45); MaleHumansList->emplace_back(0x9DDE71E1, "a_m_m_grisurvivalist_01", "", 15);
        (46); MaleHumansList->emplace_back(0x0D4DB92F, "a_m_m_guatownfolk_01", "", 27);
        (47); MaleHumansList->emplace_back(0xEEF71080, "a_m_m_htlfancydrivers_01", "", 10);
        (48); MaleHumansList->emplace_back(0xB05F73A6, "a_m_m_htlfancytravellers_01", "", 20);
        (49); MaleHumansList->emplace_back(0xA9DCFB5A, "a_m_m_htlroughtravellers_01", "", 40);
        (50); MaleHumansList->emplace_back(0xB3410109, "a_m_m_htlsurvivalist_01", "", 15);
        (51); MaleHumansList->emplace_back(0x5729EC23, "a_m_m_huntertravelers_cool_01", "", 20);
        (52); MaleHumansList->emplace_back(0xD898CFD4, "a_m_m_huntertravelers_warm_01", "", 21);
    }
}

 void AddMaleHumanSpawnOptions(Submenu* sub) {
	 InitializeMaleHumansList();

	 for (const auto& person : *MaleHumansList) {
		 std::string displayName = !person.customName.empty() ? person.customName : person.pedName;

		 sub->AddRegularOption(displayName.c_str(), "", [person]() {
			 int outfitNum = 0;

			 if (human_males_variation_bool && person.outfitCount > 0) {
				 outfitNum = rand() % person.outfitCount;
			 }

			 bool isAlive = human_males_alive_bool;
			 bool isInvincible = human_males_invincibility_bool;

			 if (std::holds_alternative<std::string>(person.modelIdentifier)) {
				 const std::string& modelName = std::get<std::string>(person.modelIdentifier);
				 Ped spawnedPerson = MalesspawnPed(modelName, 1.5f, 3.0f, 0.0f, outfitNum, isAlive, isInvincible);
				 MalesUpdatePedInvincibility(spawnedPerson, isInvincible);
			 }
			 else if (std::holds_alternative<Hash>(person.modelIdentifier)) {
				 Hash modelHash = std::get<Hash>(person.modelIdentifier);
				 Ped spawnedPerson = MalesspawnPed(modelHash, 1.5f, 3.0f, 0.0f, outfitNum, isAlive, isInvincible, person.customName.empty() ? person.pedName : person.customName);
				 MalesUpdatePedInvincibility(spawnedPerson, isInvincible);
			 }
			 });
	 }
 }