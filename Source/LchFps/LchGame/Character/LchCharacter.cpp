#include "LchCharacter.h"
#include "GameFeaturesSubsystem.h"
#include "GameFeatureData.h"
#include "GameFeaturePluginOperationResult.h"

ALchCharacter::ALchCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALchCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ALchCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALchCharacter::ToggleGameFeaturePluginByName(const FString& PluginName, bool bEnable)
{
	FString PluginURL;
	UGameFeaturesSubsystem::Get().GetPluginURLByName(PluginName, PluginURL);

	if (bEnable)
	{
		UGameFeaturesSubsystem::Get().LoadAndActivateGameFeaturePlugin(PluginURL, FGameFeaturePluginLoadComplete());
	}
	else
	{
		UGameFeaturesSubsystem::Get().UnloadGameFeaturePlugin(PluginURL);
	}
}

#pragma optimize("", off)

void ALchCharacter::TestGameFeaturePlugin(const FString& PluginName)
{
	FString PluginURL;
	UGameFeaturesSubsystem::Get().GetPluginURLByName(PluginName, PluginURL);
	const UGameFeatureData* GameFeatureData = UGameFeaturesSubsystem::Get().GetGameFeatureDataForActivePluginByURL(PluginURL);

	// test info
	float InstallPercent = 0.f;
	UGameFeaturesSubsystem::Get().GetGameFeaturePluginInstallPercent(PluginURL,InstallPercent);
	EGameFeaturePluginState State = UGameFeaturesSubsystem::Get().GetPluginState(PluginURL);
	bool bIsActive = UGameFeaturesSubsystem::Get().IsGameFeaturePluginActive(PluginURL);

	// change state
	UGameFeaturesSubsystem::Get().ChangeGameFeatureTargetState(PluginURL,EGameFeatureTargetState::Active,
		FGameFeaturePluginChangeStateComplete::CreateLambda([](const UE::GameFeatures::FResult& Result)
		{
			UE_LOG(LogTemp, Log, TEXT("ChangeGameFeatureTargetState Complete: %s"), *UE::GameFeatures::ToString(Result));
		})
	);

	// install and uninstall
	// ...

	auto BreakPoint = 0;
}

#pragma optimize("", on)