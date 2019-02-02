// Fill out your copyright notice in the Description page of Project Settings.

#include "Controls3.h"
#include "GameFramework/PlayerController.h"

// Sets default values
AControls3::AControls3()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AControls3::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayerController>(GetController());

	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = true;
	}
}

// Called every frame
void AControls3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AControls3::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AControls3::MoveUpward);
	PlayerInputComponent->BindAxis("MoveDown", this, &AControls3::MoveDownward);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AControls3::MoveLeft);
	PlayerInputComponent->BindAxis("MoveRight", this, &AControls3::MoveRight);

}

void AControls3::MoveUpward(float AxisValue)
{
	AddMovementInput(FVector(0.f, -50.f, 0.f), AxisValue);
}

void AControls3::MoveDownward(float AxisValue)
{
	AddMovementInput(FVector(0.f, 50.f, 0.f), AxisValue);
}

void AControls3::MoveLeft(float AxisValue)
{
	AddMovementInput(FVector(-50.f, 0.f, 0.f), AxisValue);
}

void AControls3::MoveRight(float AxisValue)
{
	AddMovementInput(FVector(50.f, 0.f, 0.f), AxisValue);
}


