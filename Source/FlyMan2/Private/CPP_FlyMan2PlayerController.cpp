#include "CPP_FlyMan2PlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Engine.h"
#include "CPP_FlyMan2PlayerCharacter.h"

void ACPP_FlyMan2PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);

	//ESC�L�[�������ꂽ��o�C���h�����֐����ĂԂ悤�ɓo�^
	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Quit", EKeys::Escape));//�����ŃA�����A���G���W���ɃX�N���v�g���瑀����@��o�^//���łɓo�^���Ă���Ȃ�K�v�Ȃ�
	InputComponent->BindAction("Quit", IE_Pressed, this, &ACPP_FlyMan2PlayerController::QuitGame);//�����œo�^����������@�Ɋ֐����o�C���h

	//���}�E�X�{�^���������ꂽ��o�C���h�����֐����ĂԂ悤�ɓo�^
	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Fire", EKeys::LeftMouseButton));//�����ŃA�����A���G���W���ɃX�N���v�g���瑀����@��o�^//���łɓo�^���Ă���Ȃ�K�v�Ȃ�
	InputComponent->BindAction("Fire", IE_Pressed, this, &ACPP_FlyMan2PlayerController::Fire);//�����œo�^����������@�Ɋ֐����o�C���h
}

void ACPP_FlyMan2PlayerController::QuitGame()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("QuitGame1"));

	// �Q�[�����I������
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}

void ACPP_FlyMan2PlayerController::Fire()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Fire1"));
	ACPP_FlyMan2PlayerCharacter* FlyMan2PlayerCharacter = Cast<ACPP_FlyMan2PlayerCharacter>(GetPawn());//�v���C���[�L�����N�^�[���擾
	if (FlyMan2PlayerCharacter != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Fire2"));
		FlyMan2PlayerCharacter->Shot();
	}
}