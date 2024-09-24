// copyright Game Strix Studio


#include "Character/AuraCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
// character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f,0.f);
	GetCharacterMovement()->bConstrainToPlane = true; // to hold in 2d plain 
	GetCharacterMovement()->bSnapToPlaneAtStart = true; // same as above restricts movement in z axis

	
	bUseControllerRotationPitch = false;                      
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

}

