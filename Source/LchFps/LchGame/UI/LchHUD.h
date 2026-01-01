#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LchHUD.generated.h"


UCLASS()
class LCHFPS_API ALchHUD : public AHUD
{
    GENERATED_BODY()

public:
    ALchHUD();
protected:
    virtual void BeginPlay() override;
public:
    virtual void Tick(float DeltaTime) override;
};
