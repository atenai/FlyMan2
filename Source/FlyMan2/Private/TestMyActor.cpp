// Fill out your copyright notice in the Description page of Project Settings.

#include "TestMyActor.h"
#include "Kismet/KismetSystemLibrary.h" //追加

//コンストラクタ
ATestMyActor::ATestMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

//スタート関数
void ATestMyActor::BeginPlay()
{
	Super::BeginPlay();

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(this, "Test20230427", true, true, FColor::Orange, 30.0f);
}

//アップデート関数
void ATestMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

