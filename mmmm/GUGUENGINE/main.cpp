#include "Application.h"

int main(void)
{
	Application a;
	if(!a.ValidCheck())
	{
		return -1;
	}
	while (a.IsGameRunning())
	{
		a.Update();
	}
	a.End();

	return 0;
}
