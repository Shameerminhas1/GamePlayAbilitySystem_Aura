// copyright Game Strix Studio


#include "AbilitySystem/Abilities/AuraFireBlast.h"

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
