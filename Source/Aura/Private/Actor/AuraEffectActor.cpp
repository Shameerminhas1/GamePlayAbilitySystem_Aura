// copyright Game Strix Studio

#include "Actor/AuraEffectActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Components/SphereComponent.h"

AAuraEffectActor::AAuraEffectActor()
{
 	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}
                                                                                                                 
void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();

	
}

void AAuraEffectActor::ApplyEffectsToTargets(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	
	if(TargetASC == nullptr) return;
	check(TargetASC);
	
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass,1.,EffectContextHandle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}
