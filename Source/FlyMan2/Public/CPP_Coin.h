// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Coin.generated.h"

UCLASS()
class FLYMAN2_API ACPP_Coin : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPP_Coin();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	//ìñÇΩÇËîªíË
	UPROPERTY(VisibleAnywhere)
	class USphereComponent* Sphere;

	//å©ÇΩñ⁄óp
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Mesh;

	//èdÇ»ÇËåüím
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SWeepResult);
};
