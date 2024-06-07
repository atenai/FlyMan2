#include "CPP_FlyMan2Camera.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_FlyMan2PlayerCharacter.h"
#include "Kismet/KismetSystemLibrary.h" 

/// <summary>
/// コンストラクタ
/// </summary>
ACPP_FlyMan2Camera::ACPP_FlyMan2Camera() :Super()
{
	//これはTick関数を使用できるようにする一文
	PrimaryActorTick.bCanEverTick = true;
}

/// <summary>
/// スタート関数
/// </summary>
void ACPP_FlyMan2Camera::BeginPlay()
{
	Super::BeginPlay();

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("CameraBeginPlay"));
	//UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(this, "CameraBeginPlay", true, true, FColor::Orange, 5.0f);
}

/// <summary>
/// アップデート関数
/// </summary>
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