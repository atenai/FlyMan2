// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_FlyMan2PlayerCharacter.generated.h"

UCLASS()
class FLYMAN2_API ACPP_FlyMan2PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACPP_FlyMan2PlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FVector GetPos();
};
