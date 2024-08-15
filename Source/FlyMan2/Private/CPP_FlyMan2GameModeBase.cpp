#include "CPP_FlyMan2GameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "CPP_FlyMan2PlayerController.h"

/// <summary>
/// コンストラクタ
/// </summary>
ACPP_FlyMan2GameModeBase::ACPP_FlyMan2GameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//ブループリントのキャラクターを取得
	//static ConstructorHelpers::FClassFinder<APawn> playerClass(TEXT("/Game/FlyMan2/Character/BP_FlyMan2_Character1.BP_FlyMan2_Character1_C"));
	static ConstructorHelpers::FClassFinder<APawn> playerClass(TEXT("/Game/FlyMan2/Character/BP_Boy01.BP_Boy01_C"));

	//取得に成功したら中身を実行する
	if (playerClass.Succeeded())
	{
		//キャラクターをゲームモードのデフォルトポーンクラスに設定
		DefaultPawnClass = playerClass.Class;
	}

	//ゲームモードのコントローラーを設定
	PlayerControllerClass = ACPP_FlyMan2PlayerController::StaticClass();
}
