// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Modules/ModuleManager.h"
#include "IWebSocket.h"
#include "WebSocketGameInstance.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE_OneParam(FOnNewGameStart, const TArray<FString>& args)

UCLASS()
class MINESWEEPER_API UWebSocketGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	int32 SizeX_ = 0;
	int32 SizeY_ = 0;
	virtual void Init() override;
	virtual void Shutdown() override;
	TSharedPtr<IWebSocket> WebSocket;
	FOnNewGameStart NewGameCall;
private:
	void OnMapMessage(FString Message);
};
