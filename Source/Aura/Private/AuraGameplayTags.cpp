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
	
	
}
