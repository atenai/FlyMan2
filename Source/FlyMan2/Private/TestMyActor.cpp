// Fill out your copyright notice in the Description page of Project Settings.

#include "TestMyActor.h"
#include "Kismet/KismetSystemLibrary.h" //�ǉ�

//�R���X�g���N�^
ATestMyActor::ATestMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

//�X�^�[�g�֐�
void ATestMyActor::BeginPlay()
{
	Super::BeginPlay();

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(this, "Test20230427", true, true, FColor::Orange, 30.0f);
}

//�A�b�v�f�[�g�֐�
void ATestMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

