// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Death.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPP_Death::ACPP_Death()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Tags.AddUnique(TEXT("Death"));//�^�O�̐ݒ�

	//�����蔻��1
	//BoxComponent��ǉ����ABoxComponent��RootComponent��Attach����
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	Collider->SetupAttachment(RootComponent);

	//�����蔻��1
	//Box�̃T�C�Y��ݒ肷��
	Collider->SetBoxExtent(FVector(32.0f, 32.0f, 32.0f));

	//�����蔻��1
	//Box�̈ʒu�𒲐�����
	Collider->SetRelativeLocation(FVector(0.0f, 0.0f, 00.0f), false);

	//�����蔻��1
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Death::OnBoxBeginOverlap);
}

// Called when the game starts or when spawned
void ACPP_Death::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Death::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//�����蔻��1
void ACPP_Death::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag(TEXT("Player")))
		{
			//�����ɏՓ˂����Ƃ��̏���������
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DeathOnBoxBeginOverlap"));

			//�J�ڂ���Level��Load����
			UGameplayStatics::OpenLevelBySoftObjectPtr(this, LoadLevel);
		}
	}
}