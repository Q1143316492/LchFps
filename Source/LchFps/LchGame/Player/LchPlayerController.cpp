#include "LchPlayerController.h"

ALchPlayerController::ALchPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALchPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ALchPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALchPlayerController::PostProcessInput(const float DeltaTime, const bool bGamePaused)
{
	Super::PostProcessInput(DeltaTime, bGamePaused);
}