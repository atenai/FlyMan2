// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FlyMan2PlayerCharacter.h"
#include "Engine.h"

ACPP_FlyMan2PlayerCharacter::ACPP_FlyMan2PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;//�����Tick�֐����g�p�ł���悤�ɂ���ꕶ

	Tags.AddUnique(TEXT("Player"));//�^�O�̐ݒ�

	//�����蔻��1
	//BoxComponent��ǉ����ABoxComponent��RootComponent��Attach����
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	Collider->SetupAttachment(RootComponent);

	//�����蔻��1
	//Box�̃T�C�Y��ݒ肷��
	Collider->SetBoxExtent(FVector(50.0f, 50.0f, 90.0f));

	//�����蔻��1
	//Box�̈ʒu�𒲐�����
	Collider->SetRelativeLocation(FVector(0.0f, 0.0f, 00.0f), false);

	//�����蔻��1
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ACPP_FlyMan2PlayerCharacter::OnBoxBeginOverlap);

	//�����蔻��2
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

//�����蔻��1
void ACPP_FlyMan2PlayerCharacter::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//�����ɏՓ˂����Ƃ��̏���������
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("PlayerOnBoxBeginOverlap"));
}

//�����蔻��2
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