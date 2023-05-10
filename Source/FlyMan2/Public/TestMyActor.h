// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestMyActor.generated.h"

UCLASS()
class FLYMAN2_API ATestMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	//�R���X�g���N�^
	ATestMyActor();

protected:
	//�X�^�[�g�֐�
	virtual void BeginPlay() override;

public:	
	//�A�b�v�f�[�g�֐�
	virtual void Tick(float DeltaTime) override;
};
