// copyright Game Strix Studio


#include "AbilitySystem/Abilities/ArcaneShards.h"

FString UArcaneShards::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>ARCANE SHARDS</>\n\n"
			
			// Level
			"<Small>Level: </><Level>%d</>\n"

			//ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			//Descriptions	
			"<Default>Summon a Shard of Arcane Energy, "
			"Causing radial Arcane damage of: </>"

			//Damage
			"<Damage>%d</><Default> At Shards Origins </>"
			),
			
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
			"<Title>ARCANE SHARDS</>\n\n"
			
			// Level
			"<Small>Level: </><Level>%d</>\n"

			//ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			//Additional num of Shock Targets
			"<Default>Summons %d Shards of Arcane Energy, causing Radial Arcane damage of </>"

			//Damage
			"<Damage>%d</><Default> At Shards Origins </>"),
			
			//Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, MaxNumShards),
			ScaledDamage
			);
	}
}

FString UArcaneShards::GetNextLevelDescription(int32 Level)
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
			"<Default>Summons %d Shards of Arcane Energy, causing Radial Arcane damage of </>"

			//Damage
			"<Damage>%d</><Default> At Shards Origins </>"),
			
			//Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, MaxNumShards),
			ScaledDamage
			);
}
