#include "StageManager.h"

namespace
{
	//! Struct to help save pause info
	/*struct PauseInfo
	{
		PauseInfo(M5Stage* p, M5StageTypes t) :
			pStage(p), type(t) {}
		M5Stage* pStage;
		M5StageTypes type;
	};*/

	//"Private" class data
	//static M5Factory<StageTypes, StageBuilder, Stage>
	//	s_stageFactory; /*!< Factory for creating Stages based off of the */
	//std::stack<PauseInfo>        s_pauseStack;
	static Stage* s_pStage;       /*!< Pointer to base class stage */
	//static Timer               s_timer;        /*!< Timer used to keep track of frame time.*/

	static GameData* s_pGameData;    /*!< Pointer to user defined shared data from main*/
	static StageTypes          s_currStage;    /*! Enum to know what stage to load from factory*/
	static StageTypes          s_nextStage;    /*! Enum to know what stage to load next*/
	static bool                  s_isChanging;   /*!< TRUE is we are changing states, false otherwise*/
	static bool                  s_isQuitting;   /*!< TRUE if we are quitting, FALSE otherwise*/
	static bool                  s_isRestarting; /*!< TRUE if we are restarting, FALSE otherwise*/
	static bool                  s_isPausing;
	static bool                  s_isResuming;


}

void StageManager::ChangeStage()
{
	/*if(s_isPausing)
	{
		s_isPausing = false;
	}
	else if(s_isPausing)
	{
		s_pStage-
	}
	*/
}
