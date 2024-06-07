#include "CPP_TestMyGameManagerActor.h"

ACPP_TestMyGameManagerActor::ACPP_TestMyGameManagerActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_TestMyGameManagerActor::BeginPlay()
{
	Super::BeginPlay();

	//ACPP_TestMyCameraActor* gameCameraActor = Cast<ACPP_TestMyCameraActor>(UGameplayStatics::GetActorOfClass(GetWorld(), ACPP_TestMyCameraActor::StaticClass()));//こっちでも大丈夫
	//GetWorld()で現在のレベルからACPP_TestMyCameraActor::StaticClass()でACPP_TestMyCameraActorクラスのインスタンスしたものをGetActorOfClassで探して取得しgameCameraActorに入れる
	gameCameraActor = Cast<ACPP_TestMyCameraActor>(UGameplayStatics::GetActorOfClass(GetWorld(), ACPP_TestMyCameraActor::StaticClass()));

	APlayerController* playerController = UGameplayStatics::GetPlayerController(this,0);
	//プレイヤーコントローラーをターゲットに持つSetViewTargetWithBlend関数を呼び出す
	playerController->SetViewTargetWithBlend(gameCameraActor);
}

void ACPP_TestMyGameManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

