// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Death.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPP_Death::ACPP_Death()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Tags.AddUnique(TEXT("Death"));//タグの設定

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
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Death::OnBoxBeginOverlap);
}

// Called when the game starts or when spawned
void ACPP_Death::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Death::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//当たり判定1
void ACPP_Death::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag(TEXT("Player")))
		{
			//ここに衝突したときの処理を書く
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DeathOnBoxBeginOverlap"));

			//遷移するLevelをLoadする
			UGameplayStatics::OpenLevelBySoftObjectPtr(this, LoadLevel);
		}
	}
}