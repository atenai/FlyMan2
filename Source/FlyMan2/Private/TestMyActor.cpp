// Fill out your copyright notice in the Description page of Project Settings.

#include "TestMyActor.h"



ATestMyActor::ATestMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
}


void ATestMyActor::BeginPlay()
{
	Super::BeginPlay();

	// PrintString�m�[�h�Ɠ�������

}


void ATestMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

