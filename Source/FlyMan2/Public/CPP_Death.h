#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"//当たり判定1
#include "CPP_Death.generated.h"

/// <summary>
/// デスクラス
/// </summary>
UCLASS()
class FLYMAN2_API ACPP_Death : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPP_Death();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	//当たり判定1
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent> Collider;

	//当たり判定1
	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//遷移するLevelのSoft参照
	UPROPERTY(BlueprintReadWrite, EditAnywhere , Category ="Default")
	TSoftObjectPtr<UWorld> LoadLevel;
};
