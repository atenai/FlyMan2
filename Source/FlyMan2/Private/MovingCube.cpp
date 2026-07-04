// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingCube.h"

// Sets default values
AMovingCube::AMovingCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//ゲーム中常にY軸に移動し続ける
	//AddActorWorldOffsetとはワールド軸でアクタを動かすための処理です。
	//具体的にはワールド軸を基準に、アクタの現在位置に特定の数値を足してアクタを移動させる処理になります。
	AddActorWorldOffset(FVector(0, 100 * DeltaTime, 0));//FVectorとはX,Y,Zの3つの値をまとめて扱うための型（ベクトル）です。
}

