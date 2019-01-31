// Fill out your copyright notice in the Description page of Project Settings.

#include "Controls1.h"

// Sets default values
AControls1::AControls1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AControls1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControls1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AControls1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AControls1::MoveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &AControls1::Strafe);
	PlayerInputComponent->BindAxis("Rotate", this, &AControls1::Rotate);

}

void AControls1::MoveForward(float AxisValue)
{
	FVector Fwd = GetActorForwardVector();

	AddMovementInput(Fwd, AxisValue);

}

void AControls1::Rotate(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void AControls1::Strafe(float AxisValue)
{
	FVector Right = GetActorRightVector();

	AddMovementInput(Right, AxisValue);
}

