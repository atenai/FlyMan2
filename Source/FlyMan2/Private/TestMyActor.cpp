// Fill out your copyright notice in the Description page of Project Settings.

#include "TestMyActor.h"



ATestMyActor::ATestMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
}


void ATestMyActor::BeginPlay()
{
	Super::BeginPlay();

	// PrintStringノードと同じ処理

}


void ATestMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

