//#include "Application.h"
//#include "Engine.h"
//#include "../GUGUENGINE/Engine.h"

#include "../GUGUENGINE/Engine.h"

int main(void)
{
	Engine* GUGUengine = new Engine();

	GUGUengine->Init();
	GUGUengine->GameLoop();

	delete GUGUengine;
	return 0;
}
