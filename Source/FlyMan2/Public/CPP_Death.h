#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"//�����蔻��1
#include "CPP_Death.generated.h"

/// <summary>
/// �f�X�N���X
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

	//�����蔻��1
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent> Collider;

	//�����蔻��1
	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//�J�ڂ���Level��Soft�Q��
	UPROPERTY(BlueprintReadWrite, EditAnywhere , Category ="Default")
	TSoftObjectPtr<UWorld> LoadLevel;
};
