#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "LchPlayerState.generated.h"


UCLASS()
class LCHFPS_API ALchPlayerState : public APlayerState
{
    GENERATED_BODY()

public:
    ALchPlayerState();
protected:
    virtual void BeginPlay() override;
public:
    virtual void Tick(float DeltaTime) override;
};