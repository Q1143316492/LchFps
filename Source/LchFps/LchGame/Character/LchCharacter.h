#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ModularCharacter.h"
#include "LchCharacter.generated.h"

UCLASS(config=Game)
class LCHFPS_API ALchCharacter : public AModularCharacter
{
    GENERATED_BODY()

public:
    ALchCharacter();
protected:
    virtual void BeginPlay() override;
public:
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = "Lch|Character")
    static void ToggleGameFeaturePluginByName(const FString& PluginName, bool bEnable);

    UFUNCTION(BlueprintCallable, Category = "Lch|Character")
    static void TestGameFeaturePlugin(const FString& PluginName);
};