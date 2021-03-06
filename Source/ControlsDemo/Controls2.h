// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "Controls2.generated.h"

UCLASS()
class CONTROLSDEMO_API AControls2 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AControls2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	APlayerController* playerController = nullptr;

private:
	void MoveForward(float AxisValue);

	void MoveBackwards(float AxisValue);

	void MoveRight(float AxisValue);

	void MoveLeft(float AxisValue);

	void Rotate(float AxisValue);

	

};
