#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ModularGameState.h"
#include "LchGameState.generated.h"

UCLASS()
class LCHFPS_API ALchGameState : public AModularGameStateBase
{
    GENERATED_BODY()

public:

    ALchGameState();
protected:
    virtual void BeginPlay() override;
public:
    virtual void Tick(float DeltaTime) override;
};
