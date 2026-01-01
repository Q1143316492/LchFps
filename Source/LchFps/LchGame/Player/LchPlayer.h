#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputActionValue.h"
#include "../Character/LchCharacter.h"
#include "LchPlayer.generated.h"

class ULchInputConfig;

/**
 * ALchPlayer
 *
 * 玩家角色类，实现了 Lyra 风格的输入处理。
 */
UCLASS(config=Game)
class LCHFPS_API ALchPlayer : public ALchCharacter
{
	GENERATED_BODY()

public:
	ALchPlayer();

protected:
	virtual void BeginPlay() override;

	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	//~=============================================================================
	// Input Config
	//~=============================================================================

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lch|Input")
	TObjectPtr<const ULchInputConfig> InputConfig;

	const ULchInputConfig* GetInputConfig() const;

	TArray<uint32> InputBindHandles;

	//~=============================================================================
	// Native Input Handlers
	//~=============================================================================

	void Input_Move(const FInputActionValue& InputActionValue);

	void Input_LookMouse(const FInputActionValue& InputActionValue);

	void Input_LookStick(const FInputActionValue& InputActionValue);

	void Input_Crouch(const FInputActionValue& InputActionValue);

	//~=============================================================================
	// Ability Input Handlers
	//~=============================================================================

	void Input_AbilityInputTagPressed(FGameplayTag InputTag);

	void Input_AbilityInputTagReleased(FGameplayTag InputTag);
};


