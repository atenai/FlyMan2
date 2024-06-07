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
	ACPP_TestMyGameManagerActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	TObjectPtr<class ACPP_TestMyCameraActor> gameCameraActor;
};
