#include "LchGameState.h"

ALchGameState::ALchGameState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALchGameState::BeginPlay()
{
	Super::BeginPlay();
}

void ALchGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}