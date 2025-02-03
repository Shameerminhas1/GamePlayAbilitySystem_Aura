// copyright Game Strix Studio

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/ViewModel/MVVM_LoadScreen.h"
#include "LoadScreenHUD.generated.h"

class ULoadScreenWidget;
/**
 * 
 */
UCLASS()
class AURA_API ALoadScreenHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> LoadScreenWidgetClass;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ULoadScreenWidget> LoadScreenWidget;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMVVM_LoadScreen> LoadScreenViewModelClass;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UMVVM_LoadScreen> LoadScreenViewModel;

protected:

	virtual void BeginPlay() override;
	
};
