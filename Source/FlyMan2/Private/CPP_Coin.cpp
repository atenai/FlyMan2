#include "CPP_Coin.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CPP_FlyMan2PlayerCharacter.h"

/// <summary>
/// コンストラクタ
/// </summary>
ACPP_Coin::ACPP_Coin()
{
	//当たり判定の作成	
 	PrimaryActorTick.bCanEverTick = true;

	//Sphere作成
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	RootComponent = Sphere;

	Sphere->SetSphereRadius(50.0f);
	Sphere->SetCollisionProfileName(TEXT("Trigger"));

	//Mesh作成
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionProfileName(ECollisionEnabled::NoCollision);

	//オーバーラップ登録
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Coin::OnOverlapBegin);
}

/// <summary>
/// スタート関数
/// </summary>
void ACPP_Coin::BeginPlay()
{
	Super::BeginPlay();
}

/// <summary>
/// アップデート関数
/// </summary>
void ACPP_Coin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPP_Coin::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SWeepResult)
{
	if (CPP_FlyMan2PlayerCharacter* Player = Cast<CPP_FlyMan2PlayerCharacter>(OtherActor))
	{
		
	}
}

