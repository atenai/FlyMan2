// Fill out your copyright notice in the Description page of Project Settings.


#include "LogText.h"

// Sets default values
ALogText::ALogText()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// ゲーム開始時に実行される
void ALogText::BeginPlay()
{
	Super::BeginPlay();
	//ログを出力する
	UE_LOG(LogTemp, Warning, TEXT("Hello World"));
}

// Called every frame
void ALogText::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

