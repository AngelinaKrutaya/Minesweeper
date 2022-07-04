// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameModeBase.h"
#include "MenuPlayerController.h"
#include "MenuHUD.h"

AMenuGameModeBase::AMenuGameModeBase() {
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}