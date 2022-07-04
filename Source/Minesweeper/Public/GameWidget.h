// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
struct Buttons {
	TSharedPtr<SButton> Button;
	TSharedPtr<STextBlock> TextBlock;
};

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnClickedButton, int, int)

class MINESWEEPER_API GameWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(GameWidget)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwningHUD)
	SLATE_ARGUMENT(int, SizeX)
	SLATE_ARGUMENT(int, SizeY)
	SLATE_END_ARGS()

	FOnClickedButton ClickedOnButton;
	FReply  OnClick(int x, int y);
	void Construct(const FArguments& InArgs);
	virtual bool SupportsKeyboardFocus() const override { return true; }
	void SetTextButton(int x, int y, FString& text);

private:
	int SizeX_;
	int SizeY_;
	TArray<TArray<Buttons>> Buttons_;
	TSharedPtr<SButton> CreateButton(int x, int y);
	TSharedPtr<SHorizontalBox> CreateHorizontalBox(int x);
	TSharedPtr<SVerticalBox> CreateVerticalBox();
	void InitButton();
};
