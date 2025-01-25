#ifndef MOUNT_FUNCTIONS_H
#define MOUNT_FUNCTIONS_H

#include <vector>
#include <string>

enum AttributeCore {
    ATTRIBUTE_CORE_HEALTH = 0,
    ATTRIBUTE_CORE_STAMINA = 1,
    ATTRIBUTE_CORE_DEADEYE = 2
};

void Mount_DismountFunction();
void Mount_InvincibilityFunction();
void Mount_InvisibilityFunction();
void Mount_LevitateFunction();
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
