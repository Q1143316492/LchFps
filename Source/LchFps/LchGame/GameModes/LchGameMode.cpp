#include "LchGameMode.h"

ALchGameMode::ALchGameMode()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ALchGameMode::BeginPlay()
{
    Super::BeginPlay();
}

void ALchGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
