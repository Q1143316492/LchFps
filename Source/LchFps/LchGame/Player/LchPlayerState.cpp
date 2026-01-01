#include "LchPlayerState.h"

ALchPlayerState::ALchPlayerState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALchPlayerState::BeginPlay()
{
	Super::BeginPlay();
}

void ALchPlayerState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}