// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FlyMan2PlayerCharacter.h"
#include "Engine.h"

ACPP_FlyMan2PlayerCharacter::ACPP_FlyMan2PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;//これはTick関数を使用できるようにする一文

	Tags.AddUnique(TEXT("Player"));//タグの設定

	//当たり判定1
	//BoxComponentを追加し、BoxComponentをRootComponentにAttachする
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	Collider->SetupAttachment(RootComponent);

	//当たり判定1
	//Boxのサイズを設定する
	Collider->SetBoxExtent(FVector(50.0f, 50.0f, 90.0f));

	//当たり判定1
	//Boxの位置を調整する
	Collider->SetRelativeLocation(FVector(0.0f, 0.0f, 00.0f), false);

	//当たり判定1
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ACPP_FlyMan2PlayerCharacter::OnBoxBeginOverlap);

	//当たり判定2
	this->OnActorBeginOverlap.AddDynamic(this, &ACPP_FlyMan2PlayerCharacter::OnBeginOverlap);
}

void ACPP_FlyMan2PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_FlyMan2PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_FlyMan2PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FVector ACPP_FlyMan2PlayerCharacter::GetPos()
{
	return GetActorLocation();
}

void ACPP_FlyMan2PlayerCharacter::Shot()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Fire3"));
}

//当たり判定1
void ACPP_FlyMan2PlayerCharacter::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//ここに衝突したときの処理を書く
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("PlayerOnBoxBeginOverlap"));
}

//当たり判定2
void ACPP_FlyMan2PlayerCharacter::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	//ここに衝突したときの処理を書く
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("PlayerOnBeginOverlap"));

	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag(TEXT("Goal")))
		{
			//ここに衝突したときの処理を書く
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("PlayerOnBeginOverlap_Goal"));
		}
	}

	if (OtherActor != nullptr)
	{
		if (OtherActor->ActorHasTag(TEXT("Death")))
		{
			//ここに衝突したときの処理を書く
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("PlayerOnBeginOverlap_Death"));
		}
	}
}