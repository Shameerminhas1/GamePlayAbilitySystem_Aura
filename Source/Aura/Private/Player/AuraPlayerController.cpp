// copyright Game Strix Studio


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);
	  
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext,0);
	}
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	 FInputModeGameAndUI InputModeData;

	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,false,CursorHit);
	if(!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	/**
	 * line trace from cursor - there are several cenarios
	 *
	 *   A. if LastActor && ThisActor is nnull
	 *		- Do Nothing
	 *	 B. if LastActor is null& & ThisActor is valid
	 *		- Highlight ThisActor
	 *	 C. if LastActor is valid && ThisActor is null       
	 *		- Unhighlight LastActor
	 *	 D. both Actors are valid and ThisActor != LastActor
	 *		- Unhighlight LastActor & Highlight ThisActor
	 *   E. Both Actors are valid and are same
	 *		- Do Nothing
	 */

	if (LastActor == nullptr)              
	{
		if (ThisActor != nullptr)       
		{
		  	ThisActor->HighlightActor();
			//B case last is null and this is valid
		}
		else          
		{
			//Case A - Both are null - Do Nothing
		}
	}
	else
	{
		//Case c. last is valid and this is null
		if (ThisActor == nullptr)
		{
			LastActor->UnHighlightActor();
		}
		else  // Both Actors are Valid
		{
			//Case D - both valid but not same
			if (LastActor != ThisActor)
			{
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else // - both are same and valid
			{
				//Case E Do Nothing
			}
		}
	}
	     
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{

	// Retrieves the 2D input (X and Y axis, typically for movement).
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	// Gets the current rotation of the player controller (camera direction).
	// The YawRotation is constructed using only the yaw (horizontal rotation), ignoring pitch and roll.
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f,Rotation.Yaw,0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);


	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection,InputAxisVector.X);
	}
}


