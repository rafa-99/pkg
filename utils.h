#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERROR -1

enum os
{
	pacman,
	apt,
	emerge,
	xbps,
	ENUMSIZE
};

int checkIfFileExists(char *path);
int detectOsType();
char* stringedArgument(int argc, char** argv);
