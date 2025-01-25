#include "humans_males_functions.h"
#include "../../../Menu/Base/Submenus/Main/Spawner/humans_females.h"
#include "../../Saving/States/Spawner/humans_females_default_states.h"
#include <vector> 
#include <variant>
#include <string>
#include <tuple>
#include <optional>

struct SpawnedPed {
    Ped ped;
    bool isInvincible;
    std::string customName;
};

std::vector<SpawnedPed> FemalesspawnedPeds;

void HumanFemales_InvincibilityFunction() {

}

void HumanFemales_AliveFunction() {

}

void HumanFemales_DeleteAllFunction() {
	for (const SpawnedPed& spawnedPed : FemalesspawnedPeds) {
		if (ENTITY::DOES_ENTITY_EXIST((Entity)spawnedPed.ped)) {
			ENTITY::DELETE_ENTITY((Entity*)&spawnedPed.ped);
		}
	}
	FemalesspawnedPeds.clear();
}

void HumanFemales_DeleteLastFunction() {
	if (!FemalesspawnedPeds.empty()) {
		SpawnedPed lastSpawnedPed = FemalesspawnedPeds.back();
		if (ENTITY::DOES_ENTITY_EXIST((Entity)lastSpawnedPed.ped)) {
			ENTITY::DELETE_ENTITY((Entity*)&lastSpawnedPed.ped);
		}
		FemalesspawnedPeds.pop_back();
	}
}

void HumanFemales_variationFunction() {

}

Ped FemalesspawnPed(const std::variant<std::string, Hash>& pedModelInput, float minDistance, float maxDistance, float offsetZ, int outfitNum, bool alive, bool invincible, const std::string& customName = "") {
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

    FemalesspawnedPeds.push_back({ pedSpawn, invincible, resolvedName });
    return pedSpawn;
}

void FemalesUpdatePedInvincibility(Ped ped, bool invincible) {
    if (ENTITY::DOES_ENTITY_EXIST((Entity)ped)) {
        ENTITY::SET_ENTITY_INVINCIBLE((Entity)ped, invincible);
    }
}

void FemaleToggleInvincibility(bool invincible) {
    for (SpawnedPed& spawnedPed : FemalesspawnedPeds) {
        FemalesUpdatePedInvincibility(spawnedPed.ped, invincible);
        spawnedPed.isInvincible = invincible;
    }
}

using Hash = std::uint32_t;

struct FemaleModelInfo {
	std::variant<std::string, Hash> modelIdentifier;
	std::string pedName;
	std::string customName;
	int outfitCount;

	FemaleModelInfo(const std::variant<std::string, Hash>& model,
		const std::string& ped,
		const std::string& custom,
		int outfits)
		: modelIdentifier(model), pedName(ped), customName(custom), outfitCount(outfits) {
	}

	FemaleModelInfo(Hash model,
		const std::string& ped,
		const std::string& custom,
		int outfits)
		: modelIdentifier(model), pedName(ped), customName(custom), outfitCount(outfits) {
	}

	FemaleModelInfo(const std::string& model,
		const std::string& ped,
		const std::string& custom,
		int outfits)
		: modelIdentifier(model), pedName(ped), customName(custom), outfitCount(outfits) {
	}

	FemaleModelInfo(Hash model,
		const std::string& ped,
		int outfits)
		: modelIdentifier(model), pedName(ped), customName(""), outfitCount(outfits) {
	}

	FemaleModelInfo(const std::string& model,
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

static std::unique_ptr<std::vector<FemaleModelInfo>> FemaleHumansList = nullptr;

void InitializeFemaleHumansList() {
	if (FemaleHumansList == nullptr) {
		FemaleHumansList = std::make_unique<std::vector<FemaleModelInfo>>();
		FemaleHumansList->reserve(64);

		(1); FemaleHumansList->emplace_back(0x53367A8A, "a_f_m_armcholeracorpse_01", "", 40);
		(2); FemaleHumansList->emplace_back(0x9854FB06, "a_f_m_armtownfolk_01", "", 34);
		(3); FemaleHumansList->emplace_back(0x2ECE27FA, "a_f_m_armtownfolk_02", "", 24);
		(4); FemaleHumansList->emplace_back(0x6A01E5AF, "a_f_m_asbtownfolk_01", "", 35);
		(5); FemaleHumansList->emplace_back(0x9EF80CC3, "a_f_m_bivfancytravellers_01", "", 40);
		(6); FemaleHumansList->emplace_back(0x68D9612B, "a_f_m_blwtownfolk_01", "", 40);
		(7); FemaleHumansList->emplace_back(0x5EAF4CD7, "a_f_m_blwtownfolk_02", "", 40);
		(8); FemaleHumansList->emplace_back(0x559F1795, "a_f_m_blwupperclass_01", "", 50);
		(9); FemaleHumansList->emplace_back(0x156B2B5B, "a_f_m_btchillbilly_01", "", 17);
		(10); FemaleHumansList->emplace_back(0x18FE1EB6, "a_f_m_btcobesewomen_01", "", 1);
		(11); FemaleHumansList->emplace_back(0xE6CA7A74, "a_f_m_bynfancytravellers_01", "", 30);
		(12); FemaleHumansList->emplace_back(0x41FCD560, "a_f_m_familytravelers_cool_01", "", 20);
		(13); FemaleHumansList->emplace_back(0x02FF9BBF, "a_f_m_familytravelers_warm_01", "", 20);
		(14); FemaleHumansList->emplace_back(0xDC9B1FAF, "a_f_m_gamhighsociety_01", "", 39);
		(15); FemaleHumansList->emplace_back(0xF4D38A44, "a_f_m_grifancytravellers_01", "", 40);
		(16); FemaleHumansList->emplace_back(0x7991217C, "a_f_m_guatownfolk_01", "", 25);
		(17); FemaleHumansList->emplace_back(0xC53BAC3B, "a_f_m_htlfancytravellers_01", "", 40);
		(18); FemaleHumansList->emplace_back(0xFC3C9932, "a_f_m_lagtownfolk_01", "", 12);
		(19); FemaleHumansList->emplace_back(0x98A1C808, "a_f_m_lowersdtownfolk_01", "", 42);
		(20); FemaleHumansList->emplace_back(0x88BB283B, "a_f_m_lowersdtownfolk_02", "", 40);
		(21); FemaleHumansList->emplace_back(0x777905B7, "a_f_m_lowersdtownfolk_03", "", 42);
		(22); FemaleHumansList->emplace_back(0xBF41104A, "a_f_m_lowertrainpassengers_01", "", 25);
		(23); FemaleHumansList->emplace_back(0x26F2C9A7, "a_f_m_middlesdtownfolk_01", "", 45);
		(24); FemaleHumansList->emplace_back(0x37556A6C, "a_f_m_middlesdtownfolk_02", "", 30);
		(25); FemaleHumansList->emplace_back(0xC29280E8, "a_f_m_middlesdtownfolk_03", "", 20);
		(26); FemaleHumansList->emplace_back(0xFBA4F677, "a_f_m_middletrainpassengers_01", "", 25);
		(27); FemaleHumansList->emplace_back(0xADABE58C, "a_f_m_nbxslums_01", "", 42);
		(28); FemaleHumansList->emplace_back(0xC20A03C0, "a_f_m_nbxupperclass_01", "", 45);
		(29); FemaleHumansList->emplace_back(0x0E5BDB04, "a_f_m_nbxwhore_01", "", 25);
		(30); FemaleHumansList->emplace_back(0x768C0686, "a_f_m_rhdprostitute_01", "", 35);
		(31); FemaleHumansList->emplace_back(0x2029479B, "a_f_m_rhdtownfolk_01", "", 23);
		(32); FemaleHumansList->emplace_back(0x7108E959, "a_f_m_rhdtownfolk_02", "", 22);
		(33); FemaleHumansList->emplace_back(0x7EC886E0, "a_f_m_rhdupperclass_01", "", 50);
		(34); FemaleHumansList->emplace_back(0xADA8C252, "a_f_m_rkrfancytravellers_01", "", 40);
		(35); FemaleHumansList->emplace_back(0xC53D076D, "a_f_m_roughtravellers_01", "", 30);
		(36); FemaleHumansList->emplace_back(0x697CE9F6, "a_f_m_sclfancytravellers_01", "", 21);
		(37); FemaleHumansList->emplace_back(0xF9EABA1F, "a_f_m_sdchinatown_01", "", 20);
		(38); FemaleHumansList->emplace_back(0x6C844384, "a_f_m_sdfancywhore_01", "", 20);
		(39); FemaleHumansList->emplace_back(0x8DC3DD27, "a_f_m_sdobesewomen_01", "", 1);
		(40); FemaleHumansList->emplace_back(0x254A0D7B, "a_f_m_sdserversformal_01", "", 10);
		(41); FemaleHumansList->emplace_back(0x10B716A1, "a_f_m_sdslums_02", "", 42);
		(42); FemaleHumansList->emplace_back(0xF0CED965, "a_f_m_skpprisononline_01", "", 8);
		(43); FemaleHumansList->emplace_back(0xAD789542, "a_f_m_strtownfolk_01", "", 20);
		(44); FemaleHumansList->emplace_back(0x0C6E57DB, "a_f_m_tumtownfolk_01", "", 22);
		(45); FemaleHumansList->emplace_back(0xB545A97B, "a_f_m_tumtownfolk_02", "", 22);
		(46); FemaleHumansList->emplace_back(0xE533D2B4, "a_f_m_unicorpse_01", "", 49);
		(47); FemaleHumansList->emplace_back(0xC16B7BA8, "a_f_m_uppertrainpassengers_01", "", 25);
		(48); FemaleHumansList->emplace_back(0x8E301D96, "a_f_m_valprostitute_01", "", 23);
		(49); FemaleHumansList->emplace_back(0xF666E887, "a_f_m_valtownfolk_01", "", 20);
		(50); FemaleHumansList->emplace_back(0xB7A9EA0E, "a_f_m_vhtprostitute_01", "", 11);
		(51); FemaleHumansList->emplace_back(0x008F4AD5, "a_f_m_vhttownfolk_01", "", 25);
		(52); FemaleHumansList->emplace_back(0xF7E2135D, "a_f_m_waptownfolk_01", "", 25);
	}
}

void AddFemaleHumanSpawnOptions(Submenu* sub) {
	InitializeFemaleHumansList();

	for (const auto& person : *FemaleHumansList) {
		std::string displayName = !person.customName.empty() ? person.customName : person.pedName;

		sub->AddRegularOption(displayName.c_str(), "", [person]() {
			int outfitNum = 0;

			if (human_females_variation_bool && person.outfitCount > 0) {
				outfitNum = rand() % person.outfitCount;
			}

			bool isAlive = human_females_alive_bool;
			bool isInvincible = human_females_invincibility_bool;

			if (std::holds_alternative<std::string>(person.modelIdentifier)) {
				const std::string& modelName = std::get<std::string>(person.modelIdentifier);
				Ped spawnedPerson = FemalesspawnPed(modelName, 1.5f, 3.0f, 0.0f, outfitNum, isAlive, isInvincible);
				FemalesUpdatePedInvincibility(spawnedPerson, isInvincible);
			}
			else if (std::holds_alternative<Hash>(person.modelIdentifier)) {
				Hash modelHash = std::get<Hash>(person.modelIdentifier);
				Ped spawnedPerson = FemalesspawnPed(modelHash, 1.5f, 3.0f, 0.0f, outfitNum, isAlive, isInvincible, person.customName.empty() ? person.pedName : person.customName);
				FemalesUpdatePedInvincibility(spawnedPerson, isInvincible);
			}
			});
	}
}