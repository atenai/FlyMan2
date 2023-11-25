// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FlyMan2GameModeBase.h"
#include "UObject/ConstructorHelpers.h"

ACPP_FlyMan2GameModeBase::ACPP_FlyMan2GameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//�u���[�v�����g�̃L�����N�^�[���擾
	static ConstructorHelpers::FClassFinder<APawn> playerClass(TEXT("/Game/FlyMan2/Character/FlyMan2_Character.FlyMan2_Character_C"));

	//�擾�ɐ��������璆�g�����s����
	if (playerClass.Succeeded())
	{
		//�L�����N�^�[���Q�[�����[�h�̃f�t�H���g�|�[���N���X�ɐݒ�
		DefaultPawnClass = playerClass.Class;
	}
}
