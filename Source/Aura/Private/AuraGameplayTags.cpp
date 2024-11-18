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

	/*Effects*/

	GameplayTags.DamageTypesToResistance.Add(GameplayTags.Damage_Arcane, GameplayTags.Attributes_Resistance_Arcane);
	GameplayTags.DamageTypesToResistance.Add(GameplayTags.Damage_Fire, GameplayTags.Attributes_Resistance_Fire);
	GameplayTags.DamageTypesToResistance.Add(GameplayTags.Damage_Lightning, GameplayTags.Attributes_Resistance_Lightning);
	GameplayTags.DamageTypesToResistance.Add(GameplayTags.Damage_Physical, GameplayTags.Attributes_Resistance_Physical);
	
	
	GameplayTags.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Effects.HitReact"),
	FString("Tag Granted When Hit Reacting"));

	/**
	 * Abilities
	 */

	GameplayTags.Abilities_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Abilities.Attack"),
	FString("Ability Attack Tag"));
}
