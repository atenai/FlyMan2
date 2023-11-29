// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FlyMan2PlayerCharacter.h"
#include "Engine.h"

ACPP_FlyMan2PlayerCharacter::ACPP_FlyMan2PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;//�����Tick�֐����g�p�ł���悤�ɂ���ꕶ

	Tags.AddUnique(TEXT("Player"));//�^�O�̐ݒ�

	//�����蔻��
	this->OnActorBeginOverlap.AddDynamic(this, &ACPP_FlyMan2PlayerCharacter::OnBeginOverlap);
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

void ACPP_FlyMan2PlayerCharacter::Shot()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Fire3"));
}

//�����蔻��
void ACPP_FlyMan2PlayerCharacter::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	//�����ɏՓ˂����Ƃ��̏���������
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("PlayerOnBeginOverlap"));

	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag(TEXT("Goal")))
		{
			//�����ɏՓ˂����Ƃ��̏���������
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("PlayerOnBeginOverlap_Goal"));
		}
	}

	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag(TEXT("Death")))
		{
			//�����ɏՓ˂����Ƃ��̏���������
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("PlayerOnBeginOverlap_Death"));
		}
	}
}