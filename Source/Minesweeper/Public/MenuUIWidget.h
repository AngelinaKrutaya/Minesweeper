// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuUIWidget.generated.h"
class UButton;
/**
 * 
 */
UCLASS()
class MINESWEEPER_API UMenuUIWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = MyWidget)
	FButtonStyle CellStyle;
protected:

	UPROPERTY(meta = (BindWidget))
	UButton* StartButton;

	UPROPERTY(meta = (BindWidget))
	UButton* Grid1Button;

	UPROPERTY(meta = (BindWidget))
	UButton* Grid2Button;

	UPROPERTY(meta = (BindWidget))
	UButton* Grid3Button;

	UPROPERTY(meta = (BindWidget))
	TArray<UButton*> Buttons;

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnStartGame();

	UFUNCTION()
	void OnClicked(int32 Size);
};
