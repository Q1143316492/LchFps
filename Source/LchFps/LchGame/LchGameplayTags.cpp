#include "LchGameplayTags.h"

namespace LchGameplayTags
{
	// ========================================
	// Input Tags - Native Actions
	// ========================================
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Move, "InputTag.Move", "Move input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Look_Mouse, "InputTag.Look.Mouse", "Look (mouse) input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Look_Stick, "InputTag.Look.Stick", "Look (gamepad stick) input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Crouch, "InputTag.Crouch", "Crouch input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_AutoRun, "InputTag.AutoRun", "Auto-run input.");

	// ========================================
	// Input Tags - Ability Actions
	// ========================================
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Jump, "InputTag.Jump", "Jump input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Dash, "InputTag.Dash", "Dash input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_PrimaryFire, "InputTag.PrimaryFire", "Primary fire input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_SecondaryFire, "InputTag.SecondaryFire", "Secondary fire / ADS input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Reload, "InputTag.Reload", "Reload weapon input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Interact, "InputTag.Interact", "Interact input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Melee, "InputTag.Melee", "Melee attack input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Grenade, "InputTag.Grenade", "Throw grenade input.");

	// Weapon Slots
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Weapon_Slot1, "InputTag.Weapon.Slot1", "Select weapon slot 1.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Weapon_Slot2, "InputTag.Weapon.Slot2", "Select weapon slot 2.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Weapon_Slot3, "InputTag.Weapon.Slot3", "Select weapon slot 3.");

	// Abilities
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Ability_1, "InputTag.Ability.1", "Ability 1 input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Ability_2, "InputTag.Ability.2", "Ability 2 input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Ability_3, "InputTag.Ability.3", "Ability 3 input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Ability_Ultimate, "InputTag.Ability.Ultimate", "Ultimate ability input.");
}
