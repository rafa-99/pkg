#include <stdio.h>

#define ERROR -1

enum os
{
	dnf,    /* Fedora */
	emerge, /* Gentoo */
	pacman, /* Arch */
	xbps,   /* Void */
	zypper, /* OpenSUSE */
	apt,    /* Debian */
	ENUMSIZE
};

int checkIfFileExists (char *path);
int detectOsType ();
char *stringedArgument (int argc, char **argv);
void commandProcessor (char *packages, char *initCommand);
