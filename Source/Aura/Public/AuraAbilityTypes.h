#pragma once

#include "GameplayEffectTypes.h"
#include "AuraAbilityTypes.generated.h"

USTRUCT(BlueprintType)
struct FAuraGameplayEffectContext : public  FGameplayEffectContext
{
	GENERATED_BODY()

public:

	bool IsCriticalHit() {return bIsCriticalHit;}
	bool IsBlockedHit() {return bIsBlockedHit;}

	void SetIsCriticalHit(bool bInIsCriticalHit = bInIsCriticalHit);
	void SetIsBlockedHit(bool bInIsBlockedHit = bInIsBlockedHit);
	
	/** Returns the actual struct used for serialization, subclasses must override this! */
	virtual UScriptStruct* GetScriptStruct() const
	{
		return FGameplayEffectContext::StaticStruct();
	}

	/** Custom serialization, subclasses must override this */
	virtual bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess);
	
protected:

	bool bIsCriticalHit = false;
	bool bIsBlockedHit = false;
};