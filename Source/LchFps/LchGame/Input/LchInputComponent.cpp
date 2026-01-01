#include "LchInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "LchInputConfig.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(LchInputComponent)

ULchInputComponent::ULchInputComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void ULchInputComponent::AddInputMappings(const ULchInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const
{
	check(InputConfig);
	check(InputSubsystem);

	// 注册 InputConfig 中配置的 MappingContext
	for (const auto& Entry : InputConfig->DefaultMappingContexts)
	{
		if (Entry.MappingContext.IsNull())
		{
			continue;
		}

		UInputMappingContext* Ctx = Entry.MappingContext.LoadSynchronous();
		if (Ctx)
		{
			InputSubsystem->AddMappingContext(Ctx, Entry.Priority);
		}
	}
}

void ULchInputComponent::RemoveInputMappings(const ULchInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const
{
	check(InputConfig);
	check(InputSubsystem);

	// 移除 InputConfig 中配置的 MappingContext
	for (const auto& Entry : InputConfig->DefaultMappingContexts)
	{
		// 如果已加载，直接移除；否则尝试加载再移除（安全处理）
		UInputMappingContext* Ctx = Entry.MappingContext.Get();
		if (!Ctx)
		{
			Ctx = Entry.MappingContext.LoadSynchronous();
		}

		if (Ctx)
		{
			InputSubsystem->RemoveMappingContext(Ctx);
		}
	}
}

void ULchInputComponent::RemoveBinds(TArray<uint32>& BindHandles)
{
	for (uint32 Handle : BindHandles)
	{
		RemoveBindingByHandle(Handle);
	}
	BindHandles.Reset();
}