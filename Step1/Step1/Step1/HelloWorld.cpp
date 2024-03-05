
#include <aced.h>
#include <rxregsvc.h>

void helloWorld();

void initApp()
{
	acedRegCmds->addCommand((const ACHAR*)"HELLOWORLD_COMMANDS",
		(const ACHAR*)"Hello",
		(const ACHAR*)"Bonjour",
		ACRX_CMD_TRANSPARENT,
		helloWorld);
}

void unloadApp()
{
	acedRegCmds->removeGroup((const ACHAR*)"HELLOWORLD_COMMANDS");
}

void helloWorld()
{
	acutPrintf((const ACHAR*)"\nHello World");
}