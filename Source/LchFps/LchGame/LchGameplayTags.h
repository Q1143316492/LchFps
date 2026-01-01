#pragma once

#include "NativeGameplayTags.h"

namespace LchGameplayTags
{
	// ========================================
	// Input Tags - Native Actions
	// ========================================
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look_Mouse);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look_Stick);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Crouch);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_AutoRun);

	// ========================================
	// Input Tags - Ability Actions
	// ========================================
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Jump);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Dash);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_PrimaryFire);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_SecondaryFire);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Reload);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Interact);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Melee);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Grenade);

	// Weapon Slots
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Weapon_Slot1);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Weapon_Slot2);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Weapon_Slot3);

	// Abilities
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Ability_1);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Ability_2);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Ability_3);
	LCHFPS_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Ability_Ultimate);
}
