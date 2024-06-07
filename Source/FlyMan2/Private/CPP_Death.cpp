#include "CPP_Death.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
ACPP_Death::ACPP_Death()
{
	//�����Tick�֐����g�p�ł���悤�ɂ���ꕶ
	PrimaryActorTick.bCanEverTick = true;

	//�^�O�̐ݒ�
	Tags.AddUnique(TEXT("Death"));

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

/// <summary>
/// �X�^�[�g�֐�
/// </summary>
void ACPP_Death::BeginPlay()
{
	Super::BeginPlay();
}

/// <summary>
/// �A�b�v�f�[�g�֐�
/// </summary>
void ACPP_Death::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/// <summary>
/// �����蔻��P
/// </summary>
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