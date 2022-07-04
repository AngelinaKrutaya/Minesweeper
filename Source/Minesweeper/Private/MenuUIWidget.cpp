// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuUIWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "WebSocketGameInstance.h"
#include "InputCoreTypes.h"
#include "SlateOptMacros.h"

void UMenuUIWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Buttons.Add(Grid1Button);
	Buttons.Add(Grid2Button);
	Buttons.Add(Grid3Button);
	StartButton->SetIsEnabled(false);
}


void UMenuUIWidget::NativeConstruct()
{
	Super::NativeConstruct();

	for (int32 i = 0; i < Buttons.Num(); ++i)
	{
		UButton* Button = Buttons[i];
		SButton* ButtonWidget = (SButton*)&(Button->TakeWidget().Get());
		ButtonWidget->SetOnClicked(FOnClicked::CreateLambda([this, i]()
			{
				Buttons[i]->SetIsEnabled(false);
				OnClicked(i);
				return FReply::Handled();
			}));
		
	}
}

void UMenuUIWidget::OnStartGame()
{
	const FName StartLevelName = "MinesweeperLevel";
	UGameplayStatics::OpenLevel(this, StartLevelName);
	
}

void UMenuUIWidget::OnClicked(int32 Size)
{
	UWebSocketGameInstance* GameInstance = Cast<UWebSocketGameInstance>(GetGameInstance());
	if (GameInstance) {
		if (GameInstance->WebSocket->IsConnected()) {
			GameInstance->WebSocket->Send("new " + FString::FromInt(Size+1));
			GameInstance->WebSocket->Send("map");
			StartButton->SetIsEnabled(true);
		}
	}
	if (StartButton) {
		StartButton->OnClicked.AddDynamic(this, &UMenuUIWidget::OnStartGame);
	}
}
