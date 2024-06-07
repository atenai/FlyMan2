#include "CPP_Goal.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
ACPP_Goal::ACPP_Goal()
{
	//�����Tick�֐����g�p�ł���悤�ɂ���ꕶ
	PrimaryActorTick.bCanEverTick = true;

	//�^�O�̐ݒ�
	Tags.AddUnique(TEXT("Goal"));

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
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Goal::OnBoxBeginOverlap);
}

/// <summary>
/// �X�^�[�g�֐�
/// </summary>
void ACPP_Goal::BeginPlay()
{
	Super::BeginPlay();	
}

/// <summary>
/// �A�b�v�f�[�g�֐�
/// </summary>
void ACPP_Goal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/// <summary>
/// �����蔻��P
/// </summary>
void ACPP_Goal::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag(TEXT("Player")))
		{
			//�����ɏՓ˂����Ƃ��̏���������
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("GoalOnBoxBeginOverlap"));
		
			//�J�ڂ���Level��Load����
			UGameplayStatics::OpenLevelBySoftObjectPtr(this, LoadLevel);
		}
	}
}