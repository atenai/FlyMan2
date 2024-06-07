#include "CPP_FlyMan2PlayerCharacter.h"
#include "Engine.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
ACPP_FlyMan2PlayerCharacter::ACPP_FlyMan2PlayerCharacter()
{
	//�����Tick�֐����g�p�ł���悤�ɂ���ꕶ
	PrimaryActorTick.bCanEverTick = true;

	//�^�O�̐ݒ�
	Tags.AddUnique(TEXT("Player"));

	//�����蔻��
	this->OnActorBeginOverlap.AddDynamic(this, &ACPP_FlyMan2PlayerCharacter::OnBeginOverlap);
}

/// <summary>
/// �X�^�[�g�֐�
/// </summary>
void ACPP_FlyMan2PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

/// <summary>
/// �A�b�v�f�[�g�֐�
/// </summary>
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

/// <summary>
/// �����蔻��
/// </summary>
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