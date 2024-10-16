// copyright Game Strix Studio

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 *AuraGameplayTags
 *
 *Singleton Containing Native GameplayTags
 *
 */

struct FAuraGameplayTags
{
 
public:

 static const FAuraGameplayTags& GetTags() { return GameplayTags; }

 static void InitializeNativeGameplayTags();
protected:

private:

 static FAuraGameplayTags GameplayTags;
};
