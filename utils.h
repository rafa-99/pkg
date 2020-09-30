#include <stdio.h>

#define ERROR -1

enum os
{
	apt,
	dnf,
	emerge,
	pacman,
	xbps,
	ENUMSIZE
};

int checkIfFileExists(char *path);
int detectOsType();
char* stringedArgument(int argc, char** argv);
void commandProcessor(char* packages, char* initCommand);
