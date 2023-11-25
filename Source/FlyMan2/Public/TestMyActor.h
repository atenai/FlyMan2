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
	
	ATestMyActor();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
};
