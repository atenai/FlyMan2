#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

UCLASS()
class ACoin : public AActor
{
	GENERATED_BODY()
	
public:	
	ACoin();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)//Unityのシリアライズフィールド
	float rotationSpeed = 10.0f;
};
