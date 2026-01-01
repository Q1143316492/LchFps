#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "LchInputConfig.h"

#include "LchInputComponent.generated.h"

class UEnhancedInputLocalPlayerSubsystem;
class UInputAction;
class UInputMappingContext;
class ULchInputConfig;

/**
 * ULchInputComponent
 *
 * 扩展 EnhancedInputComponent 的输入组件，支持基于 GameplayTag 的输入绑定。
 * 遵循 Lyra 的输入设计模式。
 */
UCLASS(Config = Input)
class LCHFPS_API ULchInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	ULchInputComponent(const FObjectInitializer& ObjectInitializer);

	void AddInputMappings(const ULchInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const;
	void RemoveInputMappings(const ULchInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const;

	/**
	 * 移除通过 BindHandles 追踪的绑定
	 */
	void RemoveBinds(TArray<uint32>& BindHandles);

	/**
	 * 绑定原生输入操作 (移动、视角等)
	 * 通过 GameplayTag 查找对应的 InputAction 并绑定到指定的触发事件
	 */
	template<class UserClass, typename FuncType>
	void BindNativeAction(const ULchInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func, bool bLogIfNotFound);

	/**
	 * 绑定技能输入操作
	 * 自动遍历所有 AbilityInputActions 并绑定按下和释放事件
	 * 回调函数会接收对应的 InputTag 作为参数
	 */
	template<class UserClass, typename PressedFuncType, typename ReleasedFuncType>
	void BindAbilityActions(const ULchInputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, TArray<uint32>& BindHandles);
};

// ========================================
// Template Implementations
// ========================================

template<class UserClass, typename FuncType>
void ULchInputComponent::BindNativeAction(const ULchInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func, bool bLogIfNotFound)
{
	check(InputConfig);
	if (const UInputAction* IA = InputConfig->FindNativeInputActionForTag(InputTag, bLogIfNotFound))
	{
		BindAction(IA, TriggerEvent, Object, Func);
	}
}

template<class UserClass, typename PressedFuncType, typename ReleasedFuncType>
void ULchInputComponent::BindAbilityActions(const ULchInputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, TArray<uint32>& BindHandles)
{
	check(InputConfig);

	for (const FLchInputAction& Action : InputConfig->AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag.IsValid())
		{
			if (PressedFunc)
			{
				BindHandles.Add(BindAction(Action.InputAction, ETriggerEvent::Triggered, Object, PressedFunc, Action.InputTag).GetHandle());
			}

			if (ReleasedFunc)
			{
				BindHandles.Add(BindAction(Action.InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, Action.InputTag).GetHandle());
			}
		}
	}
}