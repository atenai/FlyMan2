// Fill out your copyright notice in the Description page of Project Settings.

#include "TestMyActor.h"
#include "Kismet/KismetSystemLibrary.h" //�ǉ�

// Sets default values
ATestMyActor::ATestMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestMyActor::BeginPlay()
{
	Super::BeginPlay();

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(this, "Test20230427", true, true, FColor::Orange, 30.0f);
}

// Called every frame
void ATestMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

