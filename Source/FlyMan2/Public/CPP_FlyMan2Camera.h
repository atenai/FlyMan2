// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "CPP_FlyMan2Camera.generated.h"


UCLASS()
class FLYMAN2_API ACPP_FlyMan2Camera : public ACameraActor
{
	GENERATED_BODY()
public:
	ACPP_FlyMan2Camera();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	TObjectPtr<class ACPP_FlyMan2PlayerCharacter> player;

	FVector cameraPos;
};
