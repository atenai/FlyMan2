// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_TestMyCameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_TestMyGameManagerActor.generated.h"

UCLASS()
class FLYMAN2_API ACPP_TestMyGameManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_TestMyGameManagerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TObjectPtr<class ACPP_TestMyCameraActor> gameCameraActor;

};
