// Fill out your copyright notice in the Description page of Project Settings.


#include "WebSocketGameInstance.h"
#include "WebSocketsModule.h"

//DECLARE_LOG_CATEGORY_EXTERN(LogTemp, Log, All);
void UWebSocketGameInstance::Init()
{
	Super::Init();
	if (!FModuleManager::Get().IsModuleLoaded("WebSocket"))
	{
		FModuleManager::Get().LoadModule("WebSockets");
	}

	WebSocket = FWebSocketsModule::Get().CreateWebSocket("wss://hometask.eg1236.com/game1/","wss");

	WebSocket->OnMessage().AddLambda([this](const FString& Message) {
		if (Message.Find(TEXT("map:")) == 0) {
			OnMapMessage(Message);
		}
	});
	
	WebSocket->Connect();
}

void UWebSocketGameInstance::OnMapMessage(FString Msg) {
	TArray<FString> Map;
	int32 Idx = Msg.Find(TEXT("\n"));
	Msg = Msg.Right(Msg.Len() - (Idx + 1));
	Msg.ParseIntoArray(Map, TEXT("\n"), false);
	SizeX_ = Map[0].Len();
	SizeY_ = Map.Num() - 1;
	NewGameCall.Broadcast(Map);
}

void UWebSocketGameInstance::Shutdown()
{
	if (WebSocket->IsConnected()) {
		WebSocket->Close();
	}
	Super::Shutdown();
}
