// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FlyMan2PlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Engine.h"
#include "CPP_FlyMan2PlayerCharacter.h"

void ACPP_FlyMan2PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);

	//左マウスボタンが押されたらバインドした関数を呼ぶように登録
	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Player_Fire", EKeys::LeftMouseButton));//ここでアンリアルエンジンに操作方法を登録
	InputComponent->BindAction("Player_Fire", IE_Pressed, this, &ACPP_FlyMan2PlayerController::Fire);//ここで登録した操作方法に関数をバインド
}

void ACPP_FlyMan2PlayerController::Fire()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Fire1"));
	ACPP_FlyMan2PlayerCharacter* PossessedPawn = Cast<ACPP_FlyMan2PlayerCharacter>(GetPawn());
	if (PossessedPawn != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Fire2"));
		PossessedPawn->Shot();
	}
}