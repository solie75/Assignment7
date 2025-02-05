// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DronePawn.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UStaticMeshComponent;
class UCapsuleComponent;
class USkeletalMeshComponent;

UCLASS()
class ASSIGNMENT7_API ADronePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADronePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Mesh")
	UCapsuleComponent* CapsuleComp;

	//UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Mesh")
	//UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "SkeletalMesh")
	USkeletalMeshComponent* SkeletalMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;

	UFUNCTION()
	void MoveRight(const FInputActionValue& _value);

	UFUNCTION()
	void MoveForward(const FInputActionValue& _value);

	UFUNCTION()
	void MoveUp(const FInputActionValue& _value);

	UFUNCTION()
	void MoveRightRelease();
	UFUNCTION()
	void MoveForwardRelease();
	UFUNCTION()
	void MoveUpRelease();

	UFUNCTION()
	void Look(const FInputActionValue& _value);


	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Input_Setting")
	float MovingSpeed;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Input_Setting")
	float TurnSpeed;

	bool bMoveForward;
	bool bMoveRight;
};
