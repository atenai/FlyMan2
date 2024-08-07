#include "CPP_FlyMan2PlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Engine.h"
#include "CPP_FlyMan2PlayerCharacter.h"

void ACPP_FlyMan2PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);

	//ESCキーが押されたらバインドした関数を呼ぶように登録
	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Quit", EKeys::Escape));//ここでアンリアルエンジンにスクリプトから操作方法を登録//すでに登録してあるなら必要ない
	InputComponent->BindAction("Quit", IE_Pressed, this, &ACPP_FlyMan2PlayerController::QuitGame);//ここで登録した操作方法に関数をバインド

	//左マウスボタンが押されたらバインドした関数を呼ぶように登録
	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Fire", EKeys::LeftMouseButton));//ここでアンリアルエンジンにスクリプトから操作方法を登録//すでに登録してあるなら必要ない
	InputComponent->BindAction("Fire", IE_Pressed, this, &ACPP_FlyMan2PlayerController::Fire);//ここで登録した操作方法に関数をバインド
}

void ACPP_FlyMan2PlayerController::QuitGame()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("QuitGame1"));

	// ゲームを終了する
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}

void ACPP_FlyMan2PlayerController::Fire()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Fire1"));
	ACPP_FlyMan2PlayerCharacter* FlyMan2PlayerCharacter = Cast<ACPP_FlyMan2PlayerCharacter>(GetPawn());//プレイヤーキャラクターを取得
	if (FlyMan2PlayerCharacter != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Fire2"));
		FlyMan2PlayerCharacter->Shot();
	}
}