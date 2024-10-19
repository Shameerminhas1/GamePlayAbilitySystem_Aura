// copyright Game Strix Studio


#include "Data/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindInputAbilityActionForTag(const FGameplayTag& InputTag,
	bool bLogNotfound) const
{
	for (const FAuraInputAction Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return  Action.InputAction;
		}
	}
	if (bLogNotfound)
	{
		UE_LOG(LogTemp,Error,TEXT("Can,y find AbilityInputActionTag for inputTag : [%s] on Input Config [%s]"),*InputTag.ToString(),*GetNameSafe(this));
	}
	      return nullptr;
}
