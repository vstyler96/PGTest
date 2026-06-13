// Copyright Epic Games, Inc. All Rights Reserved.

#include "PGTestGameMode.h"

APGTestGameMode::APGTestGameMode()
{
	// stub
}

void APGTestGameMode::CompleteMission(APawn* MyPawn)
{
	if (MyPawn == nullptr) return;
	
	MyPawn->DisableInput(nullptr);
	
	OnMissionComplete(MyPawn);
}