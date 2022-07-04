// Copyright Epic Games, Inc. All Rights Reserved.

#include "MinesweeperGameMode.h"
#include "GameHUD.h"
#include "GamePlayerController.h"

AMinesweeperGameMode::AMinesweeperGameMode()
{
	PlayerControllerClass = AGamePlayerController::StaticClass();
	HUDClass = AGameHUD::StaticClass();
}

