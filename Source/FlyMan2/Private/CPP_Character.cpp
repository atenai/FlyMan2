// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Character.h"

ACPP_Character::ACPP_Character()
{

	PrimaryActorTick.bCanEverTick = true;

}

void ACPP_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

