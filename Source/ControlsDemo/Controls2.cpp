// Fill out your copyright notice in the Description page of Project Settings.

#include "Controls2.h"
#include "Components/InputComponent.h"

// Sets default values
AControls2::AControls2()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AControls2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControls2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AControls2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AControls2::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AControls2::MoveRight);
	PlayerInputComponent->BindAxis("MoveDown", this, &AControls2::MoveBackwards);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AControls2::MoveLeft);
	PlayerInputComponent->BindAxis("RotateX", this, &AControls2::Rotate);
	PlayerInputComponent->BindAxis("RotateY", this, &AControls2::Rotate);

}

void AControls2::MoveForward(float AxisValue)
{
	FVector Fwd = GetActorForwardVector();

	AddMovementInput(Fwd, AxisValue);

}

void AControls2::MoveBackwards(float AxisValue)
{
	FVector Back = GetActorForwardVector();

	AddMovementInput(Back, -AxisValue);
}

void AControls2::MoveRight(float AxisValue)
{
	FVector Right = GetActorRightVector();

	AddMovementInput(Right, AxisValue);
}

void AControls2::MoveLeft(float AxisValue)
{
	FVector Left = -GetActorRightVector();

	AddMovementInput(Left, AxisValue);
}

void AControls2::Rotate(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}
