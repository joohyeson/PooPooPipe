#include "Application.h"


int main(void)
{
	Application application;
	
	while (application.IsGameRunning())
	{
		application.gameLoop();	
	}

	return 0;
}