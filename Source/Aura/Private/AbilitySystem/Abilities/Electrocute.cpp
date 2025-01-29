// copyright Game Strix Studio


#include "AbilitySystem/Abilities/Electrocute.h"

FString UElectrocute::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>ELECTROCUTE</>\n\n"
			
			// Level
			"<Small>Level: </><Level>%d</>\n"

			//ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			//Descriptions	
			"<Default>Emits a Beam of Lightning, "
			"Connecting With Target, repeatedly causing: </>"

			//Damage
			"<Damage>%d</><Default> Lightning Damage"
			 
			"with a chance to Stun</>"),
			
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
			"<Title>ELECTROCUTE</>\n\n"
			
			// Level
			"<Small>Level: </><Level>%d</>\n"

			//ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			//Additional num of Shock Targets
			"<Default>Emits a Beam of Lightning, "
			"Propagates to %d Additional Targets nearby, causing: </>"

			//Damage
			"<Damage>%d</><Default> Lightning damage"
			 
			"with a chance to Stun</>"),
			
			//Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, MaxNumShockTargets - 1),
			ScaledDamage
			);
	}
	
}

FString UElectrocute::GetNextLevelDescription(int32 Level)
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
			
			//Additional num of Shock Targets
			"<Default>Emits a Beam of Lightning, "
			"Propagates to %d Additional Targets nearby, causing: </>"

			//Damage
			"<Damage>%d</><Default> Lightning damage"
			 
			"with a chance to Stun</>"),
			
			//Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, MaxNumShockTargets - 1),
			ScaledDamage
			);
}
