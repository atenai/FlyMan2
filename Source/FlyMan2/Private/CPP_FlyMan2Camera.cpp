// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FlyMan2Camera.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_FlyMan2PlayerCharacter.h"
#include "Kismet/KismetSystemLibrary.h" 

//コンストラクタ
ACPP_FlyMan2Camera::ACPP_FlyMan2Camera() :Super()
{
	PrimaryActorTick.bCanEverTick = true;//これはTick関数を使用できるようにする一文

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("CameraConstruct"));
	//UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(this, "CameraConstruct", true, true, FColor::Orange, 5.0f);
}

//スタート関数
void ACPP_FlyMan2Camera::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("CameraBeginPlay"));
}

//アップデート関数
void ACPP_FlyMan2Camera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("CameraTick"));

	//キャストしてプレイヤーキャラクターを取得する
	player = Cast<ACPP_FlyMan2PlayerCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ACPP_FlyMan2PlayerCharacter::StaticClass()));
	cameraPos = player->GetPos();
	cameraPos.X = cameraPos.X - 900;

	//このオブジェクトの座標をセットする
	SetActorLocation(cameraPos);
}