#include "Coin.h"

/// <summary>
/// コンストラクタ
/// </summary>
ACoin::ACoin()
{
	PrimaryActorTick.bCanEverTick = true;
}

/// <summary>
/// スタート関数
/// </summary>
void ACoin::BeginPlay()
{
	Super::BeginPlay();
}

/// <summary>
/// アップデート関数
/// </summary>
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//このアクターを回転させる（Y軸に1を足す）
	AddActorLocalRotation(FRotator(0.0f, rotationSpeed, 0.0f));
}

