#include "CPP_TestMyGameManagerActor.h"

ACPP_TestMyGameManagerActor::ACPP_TestMyGameManagerActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_TestMyGameManagerActor::BeginPlay()
{
	Super::BeginPlay();

	//ACPP_TestMyCameraActor* gameCameraActor = Cast<ACPP_TestMyCameraActor>(UGameplayStatics::GetActorOfClass(GetWorld(), ACPP_TestMyCameraActor::StaticClass()));//�������ł����v
	//GetWorld()�Ō��݂̃��x������ACPP_TestMyCameraActor::StaticClass()��ACPP_TestMyCameraActor�N���X�̃C���X�^���X�������̂�GetActorOfClass�ŒT���Ď擾��gameCameraActor�ɓ����
	gameCameraActor = Cast<ACPP_TestMyCameraActor>(UGameplayStatics::GetActorOfClass(GetWorld(), ACPP_TestMyCameraActor::StaticClass()));

	APlayerController* playerController = UGameplayStatics::GetPlayerController(this,0);
	//�v���C���[�R���g���[���[���^�[�Q�b�g�Ɏ���SetViewTargetWithBlend�֐����Ăяo��
	playerController->SetViewTargetWithBlend(gameCameraActor);
}

void ACPP_TestMyGameManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

