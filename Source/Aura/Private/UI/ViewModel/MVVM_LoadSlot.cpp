// copyright Game Strix Studio


#include "UI/ViewModel/MVVM_LoadSlot.h"

void UMVVM_LoadSlot::InitializeSlot()
{
	//TODO: check slot status based on loaded data
	SetWidgetSwitcherIndex.Broadcast(1);
	//SetWidgetSwitcherIndex.Broadcast(2);
	
}
