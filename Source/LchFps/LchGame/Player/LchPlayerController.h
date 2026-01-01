#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ModularPlayerController.h"
#include "LchPlayerController.generated.h"


UCLASS()
class LCHFPS_API ALchPlayerController : public AModularPlayerController
{
    GENERATED_BODY()
public:

    ALchPlayerController();
protected:
    virtual void BeginPlay() override;

public: 
    virtual void Tick(float DeltaTime) override;

    virtual void PostProcessInput(const float DeltaTime, const bool bGamePaused) override;
};