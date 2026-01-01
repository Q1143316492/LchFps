#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ModularGameMode.h"
#include "LchGameMode.generated.h"

UCLASS()
class LCHFPS_API ALchGameMode : public AModularGameModeBase
{
    GENERATED_BODY()

public:
    ALchGameMode();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
};