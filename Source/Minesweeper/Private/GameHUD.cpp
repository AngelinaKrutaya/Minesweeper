// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"
#include "GameWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "WebSocketGameInstance.h"

#define WHITE_SQUARE 0x25A1
void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine && GEngine->GameViewport) {
		UWebSocketGameInstance* GameInstance = Cast<UWebSocketGameInstance>(GetGameInstance());
		if (GameInstance) {
			if (GameInstance->WebSocket->IsConnected()) {
				SizeX_ = GameInstance->SizeX_;
				SizeY_ = GameInstance->SizeY_;
			}
		}
		GameInstance->NewGameCall.AddUObject(this, &AGameHUD::OnNewData);
		GameWidgetClass = SNew(GameWidget).OwningHUD(this).SizeX(SizeX_).SizeY(SizeY_);
		GameWidgetClass->ClickedOnButton.AddUObject(this, &AGameHUD::OnClickButton);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(WidgetContainer, SWeakWidget).PossiblyNullContent(GameWidgetClass.ToSharedRef()));
	}
}

void AGameHUD::OnClickButton(int x, int y)
{
	UWebSocketGameInstance* GameInstance = Cast<UWebSocketGameInstance>(GetGameInstance());
	if (GameInstance) {
		if (GameInstance->WebSocket->IsConnected()) {
			GameInstance->WebSocket->Send("open " + FString::FromInt(y) + " " + FString::FromInt(x));
			GameInstance->WebSocket->Send("map");
		}
	}
}

void AGameHUD::OnNewData(const TArray<FString>& data)
{
	for (int i = 0; i < SizeY_; ++i) {
		for (int j = 0; j < SizeX_; ++j) {
			if (data[i][j] != WHITE_SQUARE) {
				FString text;
				(*GameWidgetClass).SetTextButton(i, j, text.AppendChar(data[i][j]));
			}
		}
	}
}




