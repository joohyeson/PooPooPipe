#include "Application.h"


int main(int /*argc*/, char* /*args*/[])
{
	Application application;

	if (!application.ValidCheck())
		return -1;
	while (application.IsGameRunning())
		application.Update();

	return 0;
}