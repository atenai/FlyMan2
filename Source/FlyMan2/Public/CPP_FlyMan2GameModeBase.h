#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPP_FlyMan2GameModeBase.generated.h"

/// <summary>
/// ゲームモードクラス
/// </summary>
UCLASS()
class FLYMAN2_API ACPP_FlyMan2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACPP_FlyMan2GameModeBase(const FObjectInitializer& ObjectInitializer);	
};
