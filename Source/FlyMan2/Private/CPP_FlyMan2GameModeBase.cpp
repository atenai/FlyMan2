#include "CPP_FlyMan2GameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "CPP_FlyMan2PlayerController.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
ACPP_FlyMan2GameModeBase::ACPP_FlyMan2GameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//�u���[�v�����g�̃L�����N�^�[���擾
	//static ConstructorHelpers::FClassFinder<APawn> playerClass(TEXT("/Game/FlyMan2/Character/BP_FlyMan2_Character1.BP_FlyMan2_Character1_C"));
	static ConstructorHelpers::FClassFinder<APawn> playerClass(TEXT("/Game/FlyMan2/Character/BP_Boy01.BP_Boy01_C"));

	//�擾�ɐ��������璆�g�����s����
	if (playerClass.Succeeded())
	{
		//�L�����N�^�[���Q�[�����[�h�̃f�t�H���g�|�[���N���X�ɐݒ�
		DefaultPawnClass = playerClass.Class;
	}

	//�Q�[�����[�h�̃R���g���[���[��ݒ�
	PlayerControllerClass = ACPP_FlyMan2PlayerController::StaticClass();
}
