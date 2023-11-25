// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FlyMan2GameModeBase.h"
#include "UObject/ConstructorHelpers.h"

ACPP_FlyMan2GameModeBase::ACPP_FlyMan2GameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//ブループリントのキャラクターを取得
	static ConstructorHelpers::FClassFinder<APawn> playerClass(TEXT("/Game/FlyMan2/Character/FlyMan2_Character.FlyMan2_Character_C"));

	//取得に成功したら中身を実行する
	if (playerClass.Succeeded())
	{
		//キャラクターをゲームモードのデフォルトポーンクラスに設定
		DefaultPawnClass = playerClass.Class;
	}
}
