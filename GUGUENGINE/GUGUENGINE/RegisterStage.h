#ifndef REGISTER_STAGES_H 
#define REGISTER_STAGES_H 

#include "StateManager.h"
#include "StageTypes.h" 
//#include "StageBuilder.h" 
//#include "GamePlayStage.h" 
//#include "PauseStage.h" 
//#include "SplashStage.h" 


inline void RegisterStages(void) {
	StageManager::AddStage(ST_GamePlayStage, new StageTBuilder< GamePlayStage >());
	StageManager::AddStage(ST_PauseStage, new StageTBuilder< PauseStage >());
}
#endif //REGISTER_STAGES_H 

