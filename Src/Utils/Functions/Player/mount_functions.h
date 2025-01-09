#ifndef MOUNT_FUNCTIONS_H
#define MOUNT_FUNCTIONS_H

#include <vector>
#include <string>

enum MountTarget {
    MOUNT_CURRENT,
    MOUNT_OWNED
};

enum AttributeCore {
    ATTRIBUTE_CORE_HEALTH = 0,
    ATTRIBUTE_CORE_STAMINA = 1,
    ATTRIBUTE_CORE_DEADEYE = 2
};

extern MountTarget mount_target_preference; 

MountTarget StringToMountTargetEnum(const std::string& preference);

void Mount_PreferenceFunction(MountTarget preference);
void Mount_InvincibilityFunction();
void Mount_InvisibilityFunction();
void Mount_InfiniteStaminaFunction();
void Mount_RefillAllCoresFunction();
void Mount_RefillHealthCoreFunction();
void Mount_RefillStaminaCoreFunction();
void Mount_NoRagdollFunction();
void Mount_FearlessFunction();
void Mount_FireHoovesFunction();
void Mount_TeleportMountWhistleFunction();
void Mount_MaxBondingFunction();
void Mount_AlwaysShowCoresFunction();
void Mount_AlwaysCleanFunction();
void Mount_CleanFunction();
void Mount_ClearPeltsFunction();
void Mount_FixFunction();
void Mount_SuicideFunction();
void Mount_DeleteFunction();

#endif
