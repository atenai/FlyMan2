// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FlyMan2PlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Engine.h"
#include "CPP_FlyMan2PlayerCharacter.h"

void ACPP_FlyMan2PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);

	//���}�E�X�{�^���������ꂽ��o�C���h�����֐����ĂԂ悤�ɓo�^
	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Player_Fire", EKeys::LeftMouseButton));//�����ŃA�����A���G���W���ɑ�����@��o�^
	InputComponent->BindAction("Player_Fire", IE_Pressed, this, &ACPP_FlyMan2PlayerController::Fire);//�����œo�^����������@�Ɋ֐����o�C���h
}

void ACPP_FlyMan2PlayerController::Fire()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Fire1"));
	ACPP_FlyMan2PlayerCharacter* PossessedPawn = Cast<ACPP_FlyMan2PlayerCharacter>(GetPawn());
	if (PossessedPawn != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Fire2"));
		PossessedPawn->Shot();
	}
}