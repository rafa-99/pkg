#include <stdio.h>

#define ERROR -1

enum os
{
	apt,	/* Debian */
	dnf,	/* Fedora */
	emerge,	/* Gentoo */
	pacman,	/* Arch */
	xbps,	/* Void */
	zypper,	/* OpenSUSE */
	ENUMSIZE
};

int checkIfFileExists(char *path);
int detectOsType();
char* stringedArgument(int argc, char** argv);
void commandProcessor(char* packages, char* initCommand);
