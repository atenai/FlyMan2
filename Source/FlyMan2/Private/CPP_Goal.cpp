#include "CPP_Goal.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"

/// <summary>
/// コンストラクタ
/// </summary>
ACPP_Goal::ACPP_Goal()
{
	//これはTick関数を使用できるようにする一文
	PrimaryActorTick.bCanEverTick = true;

	//タグの設定
	Tags.AddUnique(TEXT("Goal"));

	//当たり判定1
	//BoxComponentを追加し、BoxComponentをRootComponentにAttachする
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	Collider->SetupAttachment(RootComponent);

	//当たり判定1
	//Boxのサイズを設定する
	Collider->SetBoxExtent(FVector(32.0f, 32.0f, 32.0f));

	//当たり判定1
	//Boxの位置を調整する
	Collider->SetRelativeLocation(FVector(0.0f, 0.0f, 00.0f), false);

	//当たり判定1
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Goal::OnBoxBeginOverlap);
}

/// <summary>
/// スタート関数
/// </summary>
void ACPP_Goal::BeginPlay()
{
	Super::BeginPlay();	
}

/// <summary>
/// アップデート関数
/// </summary>
void ACPP_Goal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/// <summary>
/// 当たり判定１
/// </summary>
void ACPP_Goal::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag(TEXT("Player")))
		{
			//ここに衝突したときの処理を書く
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("GoalOnBoxBeginOverlap"));
		
			//遷移するLevelをLoadする
			UGameplayStatics::OpenLevelBySoftObjectPtr(this, LoadLevel);
		}
	}
}