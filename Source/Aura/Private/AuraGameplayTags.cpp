// copyright Game Strix Studio

#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"
FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	/**
	 * Primary Attributes GameplayTags
	 */
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"),
		FString("increase physical damage"));

	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Primary.Intelligence"),
	FString("increase magical damage"));

	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Primary.Resilience"),
	FString("increase armor & armor penetration"));

	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Primary.Vigor"),
	FString("increase health"));
	/**
	 * Secondary Attributes GameplayTags
	 */
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Armor"),
		FString("Reduces Damage taken, increases Block Chance"));

	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.ArmorPenetration"),
	FString("ignores Percentage of enemy armor, increase critical hit chance"));

	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.BlockChance"),
	FString("Reduces Damage taken, increases Block Chance"));

	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.CriticalHitChance"),
	FString("Chance to cut incoming in half"));

	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.CriticalHitDamage"),
	FString("bonus damage added when a critical hit is scored"));

	GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.CriticalHitResistance"),
	FString("Reduces critical hit chance of attacking enemies"));

	GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.HealthRegeneration"),
	FString("Amount of health regenerated every 1 second"));

	GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.ManaRegeneration"),
	FString("Amount of Mana regenerated every 1 second"));

	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.MaxHealth"),
	FString("Max amount of obtainable health"));

	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.MaxMana"),
	FString("Max amount of obtainable mana"));
	
	// InputAction Tag
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.LMB"),
	FString("Input Tag For Left Mouse Button"));

	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.RMB"),
	FString("Input Tag For Right Mouse Button"));

	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.1"),
	FString("Input Tag For Key 1"));

	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.2"),
	FString("Input Tag For Key 2"));
	
	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.3"),
	FString("Input Tag For Key 3"));
	
	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.4"),
	FString("Input Tag For Key 4"));

	GameplayTags.InputTag_Passive_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.Passive.1"),
	FString("Input Tag Passive Ability 1"));
	
	GameplayTags.InputTag_Passive_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.Passive.2"),
	FString("Input Tag Passive Ability 2"));
	
	GameplayTags.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Damage"),
	FString("Damage"));

	/**
	 * Damage types
	 */
	
	GameplayTags.Damage_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Damage.Fire"),
	FString("Fire Damage Type"));

	GameplayTags.Damage_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Damage.Lightning"),
	FString("Lightning Damage Type"));

	GameplayTags.Damage_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Damage.Arcane"),
	FString("Arcane Damage Type"));

	GameplayTags.Damage_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Damage.Physical"),
	FString("Physical Damage Type"));
	
	/*
	 * Resistances
	 */
 
	GameplayTags.Attributes_Resistance_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Resistance.Arcane"),
	FString("Resistance to Arcane Damage"));

	GameplayTags.Attributes_Resistance_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Resistance.Lightning"),
	FString("Resistance to Lightning Damage"));

	GameplayTags.Attributes_Resistance_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Resistance.Physical"),
	FString("Resistance to Physical Damage"));

	GameplayTags.Attributes_Resistance_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Resistance.Fire"),
	FString("Resistance to Fire Damage"));

	/*
	 * Debuffs
	 */
 
	GameplayTags.Debuff_Burn = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Debuff.Burn"),
	FString("Debuff for Burn Damage"));

	GameplayTags.Debuff_stun = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Debuff.Stun"),
	FString("Debuff for Stun Damage"));

	GameplayTags.Debuff_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Debuff.Arcane"),
	FString("Debuff for Arcane Damage"));

	GameplayTags.Debuff_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Debuff.Physical"),
	FString("Debuff for Physical Damage"));

	GameplayTags.Debuff_Chance = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Debuff.Chance"),
	FString("Debuff Chance"));

	GameplayTags.Debuff_Duration = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Debuff.Duration"),
	FString("Debuff Duration"));

	GameplayTags.Debuff_Frequency = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Debuff.Frequency"),
	FString("Debuff Frequency"));

	GameplayTags.Debuff_Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Debuff.Damage"),
	FString("Debuff Damage"));
	
	/**
	 * Meta Attributes
	 */

	GameplayTags.Attributes_Meta_IncomingXP = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Meta.IncomingXP"),
		FString("IncomingXP  Meta Attribute"));
	
	/*Effects*/

	GameplayTags.DamageTypesToResistance.Add(GameplayTags.Damage_Arcane, GameplayTags.Attributes_Resistance_Arcane);
	GameplayTags.DamageTypesToResistance.Add(GameplayTags.Damage_Fire, GameplayTags.Attributes_Resistance_Fire);
	GameplayTags.DamageTypesToResistance.Add(GameplayTags.Damage_Lightning, GameplayTags.Attributes_Resistance_Lightning);
	GameplayTags.DamageTypesToResistance.Add(GameplayTags.Damage_Physical, GameplayTags.Attributes_Resistance_Physical);

	/**
	 * Map of damage types to debuffs
	 */
	GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Debuff_Arcane, GameplayTags.Debuff_Arcane);
	GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Debuff_stun, GameplayTags.Debuff_stun);
	GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Debuff_Burn, GameplayTags.Debuff_Burn);
	GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Debuff_Physical, GameplayTags.Debuff_Physical);
	
	GameplayTags.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(      
	FName("Effects.HitReact"),
	FString("Tag Granted When Hit Reacting"));

	/**
	 * Abilities
	 */
	GameplayTags.Abilities_None = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.None"),
	FString("No Ability - nullptr for Ability Tag"));

	GameplayTags.Abilities_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.Attack"),
	FString("Ability Attack Tag"));
	
	GameplayTags.Abilities_Summon = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.Summon"),
	FString("Summon Ability Tag"));

	GameplayTags.Abilities_Fire_FireBolt = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.Fire.FireBolt"),
	FString("FireBolt Ability Tag"));

	GameplayTags.Abilities_Lightning_Electrocute = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.Lightning.Electrocute"),
	FString("Electrocute Ability Tag"));

	GameplayTags.Abilities_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.HitReact"),
	FString("Hit React Ability"));

	GameplayTags.Abilities_Status_Eligible = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.Status.Eligible"),
	FString("Eligible status"));

	
	GameplayTags.Abilities_Status_Equipped = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.Status.Equipped"),
	FString("Equipped status"));

	GameplayTags.Abilities_Status_Locked = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.Status.Locked"),
	FString("Locked status"));
	
	GameplayTags.Abilities_Status_Unlocked = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.Status.UnLocked"),
	FString("Unlocked status"));

	GameplayTags.Abilities_Type_Offensive = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.Type.Offensive"),
	FString("Offensive Ability Tag"));
	
	GameplayTags.Abilities_Type_Passive = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.Type.Passive"),
	FString("Passive Ability Tag"));

	GameplayTags.Abilities_Type_None = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.Type.None"),
	FString("None Ability Tag"));
	
	/**
	 * Cool Down
	 */
	
	GameplayTags.Cooldown_Fire_FireBolt = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Cooldown.Fire.FireBolt"),
	FString("FireBolt Cooldown Tag"));

	/**
	 * Combat Sockets
	 */

	GameplayTags.CombatSocket_Weapon = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("CombatSocket.Weapon"),
	FString("Weapon"));

	GameplayTags.CombatSocket_RightHand = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("CombatSocket.RightHand"),
	FString("Right Hand"));

	GameplayTags.CombatSocket_LeftHand = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("CombatSocket.LeftHand"),
	FString("Left Hand"));

	GameplayTags.CombatSocket_Tail = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("CombatSocket.Tail"),
	FString("Tail"));
	
	/**
	 * Montage Tags
	 */

	GameplayTags.Montage_Attack_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Montage.Attack.1"),
	FString("Attack 1"));
	
	GameplayTags.Montage_Attack_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Montage.Attack.2"),
	FString("Attack 2"));
	
	GameplayTags.Montage_Attack_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Montage.Attack.3"),
	FString("Attack 3"));
	
	GameplayTags.Montage_Attack_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Montage.Attack.4"),
	FString("Attack 4"));
	
}
