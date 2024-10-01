// copyright Game Strix Studio

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;
class USphereComponent;

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();


protected:
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectsToTargets(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Applied Attributes")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectsClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Applied Attributes")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
	
private:

};
