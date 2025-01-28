// copyright Game Strix Studio


#include "AbilitySystem/ExecCalc/ExecCalc_Damage.h"

#include "AbilitySystemComponent.h"
#include "AuraAbilityTypes.h"
#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "Interaction/CombatInterface.h"
#include "Kismet/GameplayStatics.h"

struct AuraDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armor)
	DECLARE_ATTRIBUTE_CAPTUREDEF(BlockChance)
	DECLARE_ATTRIBUTE_CAPTUREDEF(ArmorPenetration)
	DECLARE_ATTRIBUTE_CAPTUREDEF(CriticalHitChance)
	DECLARE_ATTRIBUTE_CAPTUREDEF(CriticalHitResistance)
	DECLARE_ATTRIBUTE_CAPTUREDEF(CriticalHitDamage)

	DECLARE_ATTRIBUTE_CAPTUREDEF(FireResistance)
	DECLARE_ATTRIBUTE_CAPTUREDEF(LightningResistance)
	DECLARE_ATTRIBUTE_CAPTUREDEF(ArcaneResistance)
	DECLARE_ATTRIBUTE_CAPTUREDEF(PhysicalResistance)

		AuraDamageStatics()
    	{
    		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraAttributeSet,Armor,Target,false);
			DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraAttributeSet,BlockChance,Target,false);
			DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraAttributeSet,ArmorPenetration,Source,false);
			DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraAttributeSet,CriticalHitChance,Source,false);
			DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraAttributeSet,CriticalHitResistance,Target,false);
			DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraAttributeSet,CriticalHitDamage,Source,false);

			DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraAttributeSet,FireResistance,Target,false);
			DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraAttributeSet,LightningResistance,Target,false);
			DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraAttributeSet,ArcaneResistance,Target,false);
			DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraAttributeSet,PhysicalResistance,Target,false);

			const FAuraGameplayTags& Tags = FAuraGameplayTags::Get();
			
			
    	}
};

static const AuraDamageStatics& DamageStatics()
{
	static AuraDamageStatics DStatics;
	return DStatics;
	
}

UExecCalc_Damage::UExecCalc_Damage()
{
	RelevantAttributesToCapture.Add(DamageStatics().ArmorDef);
	RelevantAttributesToCapture.Add(DamageStatics().BlockChanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().ArmorPenetrationDef);
	RelevantAttributesToCapture.Add(DamageStatics().CriticalHitChanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().CriticalHitResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().CriticalHitDamageDef);

	RelevantAttributesToCapture.Add(DamageStatics().FireResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().LightningResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().ArcaneResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatics().PhysicalResistanceDef);
}


void UExecCalc_Damage::DetermineDebuff(const FGameplayEffectCustomExecutionParameters& ExecutionParams, const FGameplayEffectSpec& Spec, FAggregatorEvaluateParameters EvaluateParameters, const TMap<FGameplayTag, FGameplayEffectAttributeCaptureDefinition>& InTagsToDefs) const
{
	const FAuraGameplayTags GameplayTags = FAuraGameplayTags::Get();
	for (TTuple<FGameplayTag, FGameplayTag> Pair: GameplayTags.DamageTypesToDebuffs)
	{
		const FGameplayTag& DamageType = Pair.Key;
		const FGameplayTag& DebuffType = Pair.Value;
		const float TypeDamage = Spec.GetSetByCallerMagnitude(DamageType,false,-1.f);
		if (TypeDamage > -.5f) // .5 padding for floating point (im)precision
		{
			// Determine if there was a successful Debuff
			const float SourceDebuffChance = Spec.GetSetByCallerMagnitude(GameplayTags.Debuff_Chance,false,-1.f);

			float TargetDebuffResistance = 0.f;
			const FGameplayTag& ResistanceTag = GameplayTags.DamageTypesToResistance[DamageType];
			ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(InTagsToDefs[ResistanceTag],EvaluateParameters,TargetDebuffResistance);
			TargetDebuffResistance = FMath::Max<float>(TargetDebuffResistance,0.f);
			const float EffectiveDebuffChance = SourceDebuffChance * ( 100 - TargetDebuffResistance ) / 100.f;
			const bool bDebuff = FMath::RandRange (1,100) < EffectiveDebuffChance;
			if (bDebuff)
			{
				FGameplayEffectContextHandle ContextHandle = Spec.GetContext();
				UAuraAbilitySystemLibrary::SetIsSuccessfulDebuff(ContextHandle,true);
				UAuraAbilitySystemLibrary::SetDamageType(ContextHandle, DamageType);

				const float Debuff_Damage = Spec.GetSetByCallerMagnitude(GameplayTags.Debuff_Damage,false,-1.f);
				const float Debuff_Duration = Spec.GetSetByCallerMagnitude(GameplayTags.Debuff_Duration,false,-1.f);
				const float Debuff_Frequency = Spec.GetSetByCallerMagnitude(GameplayTags.Debuff_Frequency,false,-1.f);

				UAuraAbilitySystemLibrary::SetDebuffDamage(ContextHandle,Debuff_Damage);
				UAuraAbilitySystemLibrary::SetDebuffDuration(ContextHandle,Debuff_Duration);
				UAuraAbilitySystemLibrary::SetDebuffFrequency(ContextHandle,Debuff_Frequency);
			}
		}
	}
}

void UExecCalc_Damage::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
                                              FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{

	TMap<FGameplayTag, FGameplayEffectAttributeCaptureDefinition> TagsToCaptureDefs;
	const FAuraGameplayTags& Tags = FAuraGameplayTags::Get();
	
	TagsToCaptureDefs.Add(Tags.Attributes_Secondary_Armor,DamageStatics().ArmorDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Secondary_BlockChance,DamageStatics().BlockChanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Secondary_ArmorPenetration,DamageStatics().ArmorPenetrationDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Secondary_CriticalHitChance,DamageStatics().CriticalHitChanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Secondary_CriticalHitResistance,DamageStatics().CriticalHitResistanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Secondary_CriticalHitDamage,DamageStatics().CriticalHitDamageDef);
			
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Fire,DamageStatics().FireResistanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Lightning,DamageStatics().LightningResistanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Arcane,DamageStatics().ArcaneResistanceDef);
	TagsToCaptureDefs.Add(Tags.Attributes_Resistance_Physical,DamageStatics().PhysicalResistanceDef);
	const UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();
	const UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();

	AActor* SourceAvatar = SourceASC ? SourceASC->GetAvatarActor() : nullptr;
	AActor* TargetAvatar = TargetASC ? TargetASC->GetAvatarActor() : nullptr;

	int32 SourcePlayerLevel = 1;
	if (SourceAvatar->Implements<UCombatInterface>())
	{
		SourcePlayerLevel = ICombatInterface::Execute_GetPlayerLevel(SourceAvatar);
	}

	int32 TargetPlayerLevel = 1;
	if (TargetAvatar->Implements<UCombatInterface>())
	{
		TargetPlayerLevel = ICombatInterface::Execute_GetPlayerLevel(TargetAvatar);
	}
	
 	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	FGameplayEffectContextHandle EffectContextHandle = Spec.GetEffectContext();
	
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = SourceTags;
	EvaluateParameters.TargetTags = TargetTags;

	//	Debuffs
	DetermineDebuff(ExecutionParams, Spec, EvaluateParameters, TagsToCaptureDefs);
	
	// Get Damage Set by Caller Magnitude
	 float Damage = 0.f;
	for (const TTuple<FGameplayTag, FGameplayTag>& Pair : FAuraGameplayTags::Get().DamageTypesToResistance)
	{
		const FGameplayTag DamageTypeTag = Pair.Key;
		const FGameplayTag ResistanceTag = Pair.Value;

		checkf(TagsToCaptureDefs.Contains(ResistanceTag),TEXT("TagsToCaptureDef Doesn't contain Tags: [%s] in ExecCalc_Damage"), *ResistanceTag.ToString());
		const FGameplayEffectAttributeCaptureDefinition CaptureDef = TagsToCaptureDefs[ResistanceTag];
		
		float DamageTypeValue = Spec.GetSetByCallerMagnitude(Pair.Key,false);
		if (DamageTypeValue <= 0.f)
		{
			continue;
		}
		
		float Resistance = 0.f;
		ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(CaptureDef,EvaluateParameters,Resistance);
		Resistance = FMath::Clamp(Resistance,0.f,100.f);

		DamageTypeValue *= (100.f - Resistance) / 100.f;

		if (UAuraAbilitySystemLibrary::IsRadialDamage(EffectContextHandle))
		{
			// 1. override TakeDamage in AuraCharacterBase. *
			// 2. create delegate OnDamageDelegate, broadcast damage received in TakeDamage * 
			// 3. Bind lambda to OnDamageDelegate on the Victim here.
			// 4. Call UGameplayStatics :: ApplyRadialDamageWithFalloff to cause damage (this will result in TakeDamage being called
			//		on the Victim, which will then broadcast OnDamageDelegate)
			// 5. In Lambda, set DamageTypeValue to the damage received from the broadcast
			if (ICombatInterface* CombatInterface = Cast<ICombatInterface>(TargetAvatar))
			{
				CombatInterface->GetOnDamageSignature().AddLambda([&](float DamageAmount)
				{
					DamageTypeValue	= DamageAmount;
				});
			}
			UGameplayStatics::ApplyRadialDamageWithFalloff(
				TargetAvatar,
				DamageTypeValue,
				0.f,
				UAuraAbilitySystemLibrary::GetRadialDamageOrigin(EffectContextHandle),
				UAuraAbilitySystemLibrary::GetRadialDamageInnerRadius(EffectContextHandle),
				UAuraAbilitySystemLibrary::GetRadialDamageOuterRadius(EffectContextHandle),
				1.f,
				UDamageType::StaticClass(),
				TArray<AActor*>(),
				SourceAvatar,
				nullptr
				);
		}
		
		Damage += DamageTypeValue;
	}
	
	//Capture block chance on target & /determine if there was successful block
	float TargetBlockChance = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().BlockChanceDef,EvaluateParameters,TargetBlockChance);
	TargetBlockChance = FMath::Max<float>(TargetBlockChance,0.f);
	
	const bool bBlocked = FMath::RandRange(1,100) < TargetBlockChance;

	
	UAuraAbilitySystemLibrary::SetIsBlockedHit(EffectContextHandle,bBlocked);
	
	//(if block halves the damage)
	Damage = bBlocked ? Damage / 2.f : Damage;

	float TargetArmor = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ArmorDef,EvaluateParameters,TargetArmor);
	TargetArmor = FMath::Max<float>(TargetArmor,0.f);
	
	// Capture Armor Penetration

	float SourceArmorPenetration = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ArmorPenetrationDef,EvaluateParameters,SourceArmorPenetration);
	SourceArmorPenetration = FMath::Max<float>(SourceArmorPenetration,0.f);

	const UCharacterClassInfo* CharacterClassInfo = UAuraAbilitySystemLibrary::GetCharacterClassInfo(SourceAvatar);
	const FRealCurve* ArmorPenetrationCurve = CharacterClassInfo->DamageCalculationCoefficient->FindCurve(FName("ArmorPenetration"),FString());
	//Armor Penetration ignores a percentage of the target damage
	const float ArmorPenetrationCoefficient = ArmorPenetrationCurve->Eval(SourcePlayerLevel);
	const float EffectiveArmor = TargetArmor * (100 - SourceArmorPenetration * ArmorPenetrationCoefficient) / 100.f;
	//Armor Ignores a Percentage of Incoming Damage
	const FRealCurve* EffectiveArmorCurve = CharacterClassInfo->DamageCalculationCoefficient->FindCurve(FName("EffectiveArmor"),FString());
	const float EffectiveArmorCoefficient = EffectiveArmorCurve->Eval(TargetPlayerLevel);
	Damage *= (100 - EffectiveArmor * EffectiveArmorCoefficient) / 100.f;

	//capturing criticalHits

	float SourceCriticalHitDamage = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().CriticalHitDamageDef,EvaluateParameters,SourceCriticalHitDamage);
	SourceCriticalHitDamage = FMath::Max<float>(SourceCriticalHitDamage,0.f);

	float TargetCriticalHitResistance = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().CriticalHitResistanceDef,EvaluateParameters,TargetCriticalHitResistance);
	TargetCriticalHitResistance = FMath::Max<float>(TargetCriticalHitResistance,0.f);

	float SourceCriticalHitChance = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().CriticalHitChanceDef,EvaluateParameters,SourceCriticalHitChance);
	SourceCriticalHitChance = FMath::Max<float>(SourceCriticalHitChance,0.f);

	const FRealCurve* CriticalHitResistanceCurve = CharacterClassInfo->DamageCalculationCoefficient->FindCurve(FName("CriticalHitResistance"),FString());
	const float CriticalHitResistanceCoefficient = CriticalHitResistanceCurve->Eval(TargetPlayerLevel);

	//CriticalHitResistance Reduces critical HitChance by some percent
	const float EffectiveCriticalHitChance = SourceCriticalHitChance - TargetCriticalHitResistance * CriticalHitResistanceCoefficient;
	const bool bCriticalHit = FMath::RandRange(1,100) < EffectiveCriticalHitChance;
	//Double Damage plus a bonus if Critical
	Damage = bCriticalHit ? 2.f * Damage + SourceCriticalHitDamage : Damage;
	UAuraAbilitySystemLibrary::SetIsCriticalHit(EffectContextHandle,bCriticalHit);
	  
	const FGameplayModifierEvaluatedData EvaluatedData(UAuraAttributeSet::GetIncomingDamageAttribute(),EGameplayModOp::Additive,Damage);                
	OutExecutionOutput.AddOutputModifier(EvaluatedData);
}
