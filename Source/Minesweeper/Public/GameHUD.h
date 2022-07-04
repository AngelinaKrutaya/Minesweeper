// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * 
 */

UCLASS()
class MINESWEEPER_API AGameHUD : public AHUD
{
	GENERATED_BODY()
protected:
	TSharedPtr<class GameWidget> GameWidgetClass;
	TSharedPtr<class SWidget> WidgetContainer;

	virtual void BeginPlay() override;
	void OnClickButton(int x, int y);
	void OnNewData(const TArray<FString>& data);
private:
	int32 SizeX_;
	int32 SizeY_;
};
