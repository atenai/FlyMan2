// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TestMyGameManagerActor.h"

// Sets default values
ACPP_TestMyGameManagerActor::ACPP_TestMyGameManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
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

// Called every frame
void ACPP_TestMyGameManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

