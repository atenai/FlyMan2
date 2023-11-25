// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FlyMan2Camera.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_FlyMan2PlayerCharacter.h"
#include "Kismet/KismetSystemLibrary.h" 

//�R���X�g���N�^
ACPP_FlyMan2Camera::ACPP_FlyMan2Camera() :Super()
{
	PrimaryActorTick.bCanEverTick = true;//�����Tick�֐����g�p�ł���悤�ɂ���ꕶ

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("CameraConstruct"));
	//UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(this, "CameraConstruct", true, true, FColor::Orange, 5.0f);
}

//�X�^�[�g�֐�
void ACPP_FlyMan2Camera::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("CameraBeginPlay"));
}

//�A�b�v�f�[�g�֐�
void ACPP_FlyMan2Camera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("CameraTick"));

	//�L���X�g���ăv���C���[�L�����N�^�[���擾����
	player = Cast<ACPP_FlyMan2PlayerCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ACPP_FlyMan2PlayerCharacter::StaticClass()));
	cameraPos = player->GetPos();
	cameraPos.X = cameraPos.X - 900;

	//���̃I�u�W�F�N�g�̍��W���Z�b�g����
	SetActorLocation(cameraPos);
}