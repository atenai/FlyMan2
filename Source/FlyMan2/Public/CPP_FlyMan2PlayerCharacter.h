#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_FlyMan2PlayerCharacter.generated.h"

/// <summary>
/// プレイヤーキャラクタークラス
/// </summary>
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

	void Shot();

	//当たり判定
	UFUNCTION()
	void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
