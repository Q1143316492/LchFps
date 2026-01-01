#include "LchPlayer.h"
#include "../Input/LchInputComponent.h"
#include "../Input/LchInputConfig.h"
#include "../LchGameplayTags.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "Engine/LocalPlayer.h"

ALchPlayer::ALchPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALchPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void ALchPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALchPlayer::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// 在 SetupPlayerInputComponent 中处理输入绑定
}

void ALchPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 获取 LchInputComponent (应该在 Pawn 的 InputComponent 中设置为 ULchInputComponent)
	ULchInputComponent* LchIC = Cast<ULchInputComponent>(PlayerInputComponent);
	if (!LchIC)
	{
		return;
	}

	// 获取 InputConfig (应该从 PawnData 或其他地方获取，这里暂时需要手动配置)
	const ULchInputConfig* CurrentInputConfig = GetInputConfig();
	if (!CurrentInputConfig)
	{
		return;
	}

	// 注册 MappingContexts（仅对本地玩家生效）
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (PC->IsLocalController())
		{
			if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
			{
				if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
				{
					LchIC->AddInputMappings(CurrentInputConfig, InputSubsystem);
				}
			}
		}
	}

	// 绑定原生输入动作
	LchIC->BindNativeAction(CurrentInputConfig, LchGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move, /*bLogIfNotFound=*/ false);
	LchIC->BindNativeAction(CurrentInputConfig, LchGameplayTags::InputTag_Look_Mouse, ETriggerEvent::Triggered, this, &ThisClass::Input_LookMouse, /*bLogIfNotFound=*/ false);
	LchIC->BindNativeAction(CurrentInputConfig, LchGameplayTags::InputTag_Look_Stick, ETriggerEvent::Triggered, this, &ThisClass::Input_LookStick, /*bLogIfNotFound=*/ false);
	LchIC->BindNativeAction(CurrentInputConfig, LchGameplayTags::InputTag_Crouch, ETriggerEvent::Triggered, this, &ThisClass::Input_Crouch, /*bLogIfNotFound=*/ false);
	LchIC->BindNativeAction(CurrentInputConfig, LchGameplayTags::InputTag_Jump, ETriggerEvent::Started, this, &ACharacter::Jump, /*bLogIfNotFound=*/ false);

	// 绑定技能输入动作
	LchIC->BindAbilityActions(CurrentInputConfig, this, &ThisClass::Input_AbilityInputTagPressed, &ThisClass::Input_AbilityInputTagReleased, InputBindHandles);
}

const ULchInputConfig* ALchPlayer::GetInputConfig() const
{
	return InputConfig;
}

void ALchPlayer::Input_Move(const FInputActionValue& InputActionValue)
{
	FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	
	if (Controller != nullptr)                                                              
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ALchPlayer::Input_LookMouse(const FInputActionValue& InputActionValue)
{
	FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();
	
	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ALchPlayer::Input_LookStick(const FInputActionValue& InputActionValue)
{
	FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();
	
	if (Controller != nullptr)
	{
		// 手柄视角控制可能需要不同的灵敏度处理
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ALchPlayer::Input_Crouch(const FInputActionValue& InputActionValue)
{
	// 切换蹲下状态
	if (CanCrouch())
	{
		Crouch();
	}
	else
	{
		UnCrouch();
	}
}

void ALchPlayer::Input_AbilityInputTagPressed(FGameplayTag InputTag)
{
	// TODO: 发送给 AbilitySystemComponent
	// if (ULchAbilitySystemComponent* ASC = GetLchAbilitySystemComponent())
	// {
	//     ASC->AbilityInputTagPressed(InputTag);
	// }
}

void ALchPlayer::Input_AbilityInputTagReleased(FGameplayTag InputTag)
{
	// TODO: 发送给 AbilitySystemComponent
	// if (ULchAbilitySystemComponent* ASC = GetLchAbilitySystemComponent())
	// {
	//     ASC->AbilityInputTagReleased(InputTag);
	// }
}