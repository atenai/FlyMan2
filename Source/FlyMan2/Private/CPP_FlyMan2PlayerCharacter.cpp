// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FlyMan2PlayerCharacter.h"

ACPP_FlyMan2PlayerCharacter::ACPP_FlyMan2PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;//‚±‚ê‚ÍTickŠÖ”‚ğg—p‚Å‚«‚é‚æ‚¤‚É‚·‚éˆê•¶

}

void ACPP_FlyMan2PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_FlyMan2PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_FlyMan2PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FVector ACPP_FlyMan2PlayerCharacter::GetPos()
{
	return GetActorLocation();
}