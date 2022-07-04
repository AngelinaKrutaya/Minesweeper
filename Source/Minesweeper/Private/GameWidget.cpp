// Fill out your copyright notice in the Description page of Project Settings.


#include "GameWidget.h"
#define LOCTEXT_NAMESPACE "Game"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void GameWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;
	SizeX_ = InArgs._SizeX;
	SizeY_ = InArgs._SizeY;

	InitButton();

	ChildSlot
		[
			SNew(SBorder).BorderBackgroundColor(FSlateColor(FLinearColor::Black))
			[
				CreateVerticalBox().ToSharedRef()
			]
		];
}

FReply GameWidget::OnClick(int x, int y)
{
	ClickedOnButton.Broadcast(x, y);
	return FReply::Handled();
}

void GameWidget::InitButton() {
	for (int i = 0; i < SizeY_; ++i) {
		for (int j = 0; j < SizeX_; ++j) {
			Buttons_.Add(TArray<Buttons>());
		}
	}
}

void GameWidget::SetTextButton(int x, int y, FString& text)
{
	Buttons_[x][y].Button.Get()->SetEnabled(false);
	Buttons_[x][y].TextBlock.Get()->SetText(FText::FromString(text));

}

TSharedPtr<SButton> GameWidget::CreateButton(int x,int y)
{
	Buttons Btn;
	Btn.Button = SNew(SButton).OnClicked(this, &GameWidget::OnClick, x, y)
		.VAlign(EVerticalAlignment::VAlign_Fill)
		.HAlign(EHorizontalAlignment::HAlign_Fill);
	Btn.TextBlock = SNew(STextBlock).ColorAndOpacity(FSlateColor(FColor::Black))
		.Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 700 / SizeX_))
		.Justification(ETextJustify::Center);
	Buttons_[x].Add(Btn);
	Btn.Button->SetContent(Buttons_[x][y].TextBlock.ToSharedRef());
	return Buttons_[x][y].Button;
}

TSharedPtr<SHorizontalBox> GameWidget::CreateHorizontalBox(int x)
{
	TSharedPtr<SHorizontalBox> HorizontalBox = SNew(SHorizontalBox);
	for (int y = 0; y < SizeX_; ++y)
	{
		HorizontalBox->AddSlot()
			[
				CreateButton(x, y).ToSharedRef()
			];

	}
	return HorizontalBox;

}

TSharedPtr<SVerticalBox> GameWidget::CreateVerticalBox()
{
	TSharedPtr<SVerticalBox> VerticalBox = SNew(SVerticalBox);
	for (int i = 0; i < SizeY_; ++i)
	{

		VerticalBox->AddSlot()[
			CreateHorizontalBox(i).ToSharedRef()
		];

	}
	return VerticalBox;

}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION


