// Fill out your copyright notice in the Description page of Project Settings.


#include "DronePawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "DroneController.h"

// Sets default values
ADronePawn::ADronePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = CapsuleComp;

	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMeshComp->SetupAttachment(CapsuleComp);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(CapsuleComp);
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false;

	MovingSpeed = 3.0f;
	TurnSpeed = 1.f;

	bMoveForward = false;
	bMoveRight = false;
}

// Called when the game starts or when spawned
void ADronePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADronePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator Rotator = SkeletalMeshComp->GetComponentRotation();
	/*if (!bMoveRight)
	{
		if (Rotator.Roll != 0)
		{
			if (Rotator.Roll - DeltaTime * 100.f > 0)
			{
				SkeletalMeshComp->AddLocalRotation(FRotator(0, 0, -DeltaTime * 100.f));
			}
			else if (Rotator.Roll + DeltaTime * 100.f < 0)
			{
				SkeletalMeshComp->AddLocalRotation(FRotator(0, 0, DeltaTime * 100.f));
			}
			else
			{
				Rotator.Roll = 0;
				SkeletalMeshComp->SetRelativeRotation(Rotator);
			}
		}
	}
	if (!bMoveForward)
	{
		if (Rotator.Pitch != 0)
		{
			if (Rotator.Pitch - DeltaTime * 100.f > 0)
			{
				SkeletalMeshComp->AddLocalRotation(FRotator(-DeltaTime * 100.f, 0, 0));
			}
			else if (Rotator.Pitch + DeltaTime * 100.f < 0)
			{
				SkeletalMeshComp->AddLocalRotation(FRotator(DeltaTime * 100.f, 0, 0));
			}
			else
			{
				Rotator.Pitch = 0;
				SkeletalMeshComp->SetRelativeRotation(Rotator);
			}
		}
	}*/
}

// Called to bind functionality to input
void ADronePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (ADroneController* DroneController = Cast<ADroneController>(GetController()))
		{
			if (DroneController->MoveRightAction)
			{
				EnhancedInput->BindAction(
					DroneController->MoveRightAction,
					ETriggerEvent::Triggered,
					this,
					&ADronePawn::MoveRight
				);

				EnhancedInput->BindAction(
					DroneController->MoveRightAction,
					ETriggerEvent::Completed,
					this,
					&ADronePawn::MoveRightRelease
				);
			}

			if (DroneController->MoveForwardAction)
			{
				EnhancedInput->BindAction(
					DroneController->MoveForwardAction,
					ETriggerEvent::Triggered,
					this,
					&ADronePawn::MoveForward
				);

				EnhancedInput->BindAction(
					DroneController->MoveForwardAction,
					ETriggerEvent::Completed,
					this,
					&ADronePawn::MoveForwardRelease
				);
			}

			if (DroneController->MoveUpAction)
			{
				EnhancedInput->BindAction(
					DroneController->MoveUpAction,
					ETriggerEvent::Triggered,
					this,
					&ADronePawn::MoveUp
				);

				EnhancedInput->BindAction(
					DroneController->MoveUpAction,
					ETriggerEvent::Completed,
					this,
					&ADronePawn::MoveUpRelease
				);
			}

			if (DroneController->LookAction)
			{
				EnhancedInput->BindAction(
					DroneController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&ADronePawn::Look
				);
			}
		}
	}
}

void ADronePawn::MoveRight(const FInputActionValue& _value)
{
	if (!Controller) return;

	const FVector MoveInput = _value.Get<FVector>();

	//FRotator CurRotator = GetActorRotation();
	FRotator CurRotator = SkeletalMeshComp->GetComponentRotation();

	if (MoveInput.Y != 0)
	{
		if (FMath::Abs(CurRotator.Pitch + (MoveInput.Y * TurnSpeed)) < 45)
		{
			SkeletalMeshComp->AddLocalRotation(FRotator(0, 0, MoveInput.Y * TurnSpeed));
			AddActorLocalRotation(FRotator(0, 0, MoveInput.Y * TurnSpeed));
		}
	}

	bMoveRight = true;
	//AddActorLocalOffset(MoveInput * MovingSpeed, true);

	UE_LOG(LogTemp, Warning, TEXT("MoveRight"));
}

void ADronePawn::MoveForward(const FInputActionValue& _value)
{
	if (!Controller) return;

	const FVector MoveInput = _value.Get<FVector>();
	FRotator CurRotator = SkeletalMeshComp->GetComponentRotation();

	if (MoveInput.Y != 0)
	{
		if (FMath::Abs(CurRotator.Pitch + MoveInput.Y * TurnSpeed) < 25)
		{
			SkeletalMeshComp->AddLocalRotation(FRotator(MoveInput.Y * TurnSpeed, 0, 0));
		}
	}

	bMoveForward = true;
	AddActorLocalOffset(MoveInput * MovingSpeed, true);
	UE_LOG(LogTemp, Warning, TEXT("MoveForward"));
}

void ADronePawn::MoveUp(const FInputActionValue& _value)
{
	if (!Controller) return;

	const FVector MoveInput = _value.Get<FVector>();

	AddActorLocalOffset(MoveInput * MovingSpeed, true);
	UE_LOG(LogTemp, Warning, TEXT("MoveUp"));
}

void ADronePawn::MoveRightRelease()
{
	bMoveRight = false;
}

void ADronePawn::MoveForwardRelease()
{
	bMoveForward = false;
}

void ADronePawn::MoveUpRelease()
{
}

void ADronePawn::Look(const FInputActionValue& _value)
{
	FVector2D LookInput = _value.Get<FVector2D>();
	AddControllerYawInput(LookInput.X);
	AddControllerPitchInput(LookInput.Y);
}


