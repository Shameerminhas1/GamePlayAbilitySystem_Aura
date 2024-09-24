// copyright Game Strix Studio

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IEnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//pure virtual functions rendering this class abstract, now this class does not need definition.
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
	
};
