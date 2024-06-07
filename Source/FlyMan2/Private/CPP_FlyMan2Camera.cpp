#include "CPP_FlyMan2Camera.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_FlyMan2PlayerCharacter.h"
#include "Kismet/KismetSystemLibrary.h" 

/// <summary>
/// �R���X�g���N�^
/// </summary>
ACPP_FlyMan2Camera::ACPP_FlyMan2Camera() :Super()
{
	//�����Tick�֐����g�p�ł���悤�ɂ���ꕶ
	PrimaryActorTick.bCanEverTick = true;
}

/// <summary>
/// �X�^�[�g�֐�
/// </summary>
void ACPP_FlyMan2Camera::BeginPlay()
{
	Super::BeginPlay();

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("CameraBeginPlay"));
	//UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(this, "CameraBeginPlay", true, true, FColor::Orange, 5.0f);
}

/// <summary>
/// �A�b�v�f�[�g�֐�
/// </summary>
void ACPP_FlyMan2Camera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("CameraTick"));

	//�L���X�g���ăv���C���[�L�����N�^�[���擾����
	player = Cast<ACPP_FlyMan2PlayerCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ACPP_FlyMan2PlayerCharacter::StaticClass()));
	cameraPos = player->GetPos();
	cameraPos.X = cameraPos.X - 900;

	//���̃I�u�W�F�N�g�̍��W���Z�b�g����
	SetActorLocation(cameraPos);
}