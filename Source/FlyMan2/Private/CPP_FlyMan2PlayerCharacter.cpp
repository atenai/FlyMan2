// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FlyMan2PlayerCharacter.h"
#include "Engine.h"

ACPP_FlyMan2PlayerCharacter::ACPP_FlyMan2PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;//これはTick関数を使用できるようにする一文

	Tags.AddUnique(TEXT("Player"));//タグの設定

	//当たり判定
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

//当たり判定
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