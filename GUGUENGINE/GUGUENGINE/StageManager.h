class Stage;
struct GameData;
class StageBuilder;

#include "StageTypes.h"


//! Singleton to control quitting, restarting and switching stages.
class StageManager
{
public:
	friend class Applicatiion;

	static void AddStage(StageTypes type, StageBuilder* builder);
	static void RemoveStage(StageTypes type);
	static void ClearStages(void);
	static void SetStartStage(StageTypes startStage);
	static bool IsQuitting(void);
	static bool IsRestarting(void);
	static GameData& GetGameData(void);
	static void SetNextStage(StageTypes nextStage);
	static void PauseAndSetNextStage(StageTypes nextStage);
	static void Resume(void);
	static void Quit(void);
	static void Restart(void);
	
private:
	static void Init(const GameData* gameData, int gameDataSize, int framesPerSecond);
	static void Update(void);
	static void Shutdown(void);
	static void InitStage(void);
	static void ChangeStage(void);

};
