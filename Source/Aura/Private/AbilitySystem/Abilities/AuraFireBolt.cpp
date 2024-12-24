// copyright Game Strix Studio


#include"AbilitySystem/Abilities/AuraFireBolt.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>FIRE BOLT</>\n\n"
			
			// Level
			"<Small>Level: </><Level>%d</>\n"

			//ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			//Descriptions	
			"<Default>Launches a Bolt of Fire, "
			"Exploding on impact and dealing: </>"

			//Damage
			"<Damage>%d</><Default> Fire damage"
			 
			"with a chance to burn</>"),
			
			//Values
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage
			);
	}
	else
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>FIRE BOLT</>\n\n"
			
			// Level
			"<Small>Level: </><Level>%d</>\n"

			//ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			//Num of firebolts
			"<Default>Launches %d Bolts of Fire, "
			"Exploding on impact and dealing: </>"

			//Damage
			"<Damage>%d</><Default> Fire damage"
			 
			"with a chance to burn</>"),
			
			//Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, NumProjectiles),
			ScaledDamage
			);
	}
	
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
			//Title
			"<Title>NEXT LEVEL: </>\n\n"
			
			// Level
			"<Small>Level: </><Level>%d</>\n"

			//ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			//Num of firebolts
			"<Default>Launches %d Bolts of Fire, "
			"Exploding on impact and dealing: </>"

			//Damage
			"<Damage>%d</><Default> Fire damage"
			 
			"with a chance to burn</>"),
			
			//Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, NumProjectiles),
			ScaledDamage
			);
}
