// copyright Game Strix Studio


#include "AbilitySystem/Abilities/AuraFireBlast.h"

#include "AbilitySystem/AuraAbilitySystemLibrary.h"

FString UAuraFireBlast::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
		return FString::Printf(TEXT(
			//Title
			"<Title>FIRE BLAST</>\n\n"
			
			// Level
			"<Small>Level: </><Level>%d</>\n"

			//ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			//Cooldown  
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			//Descriptions	
			"<Default>Launches %d</>"
			"<Default>fireballs in all directions, each coming back and</>"
			"<Default> exploding on returning, causing</>"
			
			//Damage
			"<Damage>%d</><Default>Radial fire damage"
			 
			"with a chance to burn</>"),
			
			//Values
			Level,
			ManaCost,
			Cooldown,
			NumFireballs,
			ScaledDamage
			);
}

FString UAuraFireBlast::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
		//Title
		"<Title>NEXT LEVEL</>\n\n"
			
		// Level
		"<Small>Level: </><Level>%d</>\n"

		//ManaCost
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		//Cooldown  
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
		//Descriptions	
		"<Default>Launches %d</>"
		"<Default>fireballs in all directions, each coming back and</>"
		"<Default> exploding on returning, causing</>"
			
		//Damage
		"<Damage>%d</><Default>Radial fire damage"
			 
		"with a chance to burn</>"),
			
		//Values
		Level,
		ManaCost,
		Cooldown,
		NumFireballs,
		ScaledDamage
		);
}

TArray<AAuraFireBall*> UAuraFireBlast::SpawnFireBalls()
{
	TArray<AAuraFireBall*> Fireballs;
	const FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const FVector Location = GetAvatarActorFromActorInfo()->GetActorLocation();
	TArray<FRotator> Rotators = UAuraAbilitySystemLibrary::EvenlySpacedRotators(Forward, FVector::UpVector,360.f,NumFireballs);

	for (const FRotator& Rotator : Rotators)
	{
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(Location);
		SpawnTransform.SetRotation(Rotator.Quaternion());
		AAuraFireBall* FireBall = GetWorld()->SpawnActorDeferred<AAuraFireBall>(
			FireBallClass,
			SpawnTransform,
			GetOwningActorFromActorInfo(),
			CurrentActorInfo->PlayerController->GetPawn(),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn
			);
		FireBall->DamageEffectParams = MakeDamageEffectParamsFromClassDefault();
		FireBall->ReturnToActor = GetAvatarActorFromActorInfo();
		FireBall->SetOwner(GetAvatarActorFromActorInfo()); 

		FireBall->ExplosionDamageParams = MakeDamageEffectParamsFromClassDefault();
		FireBall->SetOwner(GetAvatarActorFromActorInfo()); 
		
		Fireballs.Add(FireBall);
		FireBall->FinishSpawning(SpawnTransform);
	}
	return Fireballs;
}
