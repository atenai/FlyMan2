#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPP_FlyMan2PlayerController.generated.h"

/// <summary>
/// プレイヤーコントローラークラス
/// </summary>
UCLASS()
class FLYMAN2_API ACPP_FlyMan2PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void SetupInputComponent() override;

	void QuitGame();
	void Fire();
};
