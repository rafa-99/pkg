#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int checkIfFileExists(char *path)
{
	return access(path, F_OK);
}

int detectOsType()
{
	int exists = ERROR;
	for ( int i = 0; i < ENUMSIZE && exists == ERROR; i++ )
	{
		switch (i)
		{
			case apt:
				if ( checkIfFileExists("/usr/bin/apt" ) == 0 )
				{
					exists = i;
				}
				break;

			case dnf:
				if ( checkIfFileExists("/usr/bin/dnf" ) == 0 )
				{
					exists = i;
				}
				break;

			case emerge:
				if ( checkIfFileExists("/usr/bin/emerge" ) == 0 )
				{
					exists = i;
				}
				break;

			case pacman:
				if ( checkIfFileExists("/usr/bin/pacman" ) == 0 )
				{
					exists = i;
				}
				break;

			case xbps:
				if ( checkIfFileExists("/usr/bin/xbps-install" ) == 0 )
				{
					exists = i;
				}
				break;

			case zypper:
				if ( checkIfFileExists("/usr/bin/zypper" ) == 0 )
				{
					exists = i;
				}
				break;

			default:
				puts("Unrecognized Package Manager" );
		}
	}
	return exists;
}

char* stringedArgument(int argc, char** argv)
{
	int numberOfTotalPackages = argc - 2;
	char* arg = (char *) calloc(((numberOfTotalPackages * 80) + numberOfTotalPackages), sizeof(char));

	for( int i = 2; i < argc; i++ )
	{
		strcat(arg, argv[i]);
		strcat(arg, " ");
	}
	return arg;
}

void commandProcessor(char* packages, char* initCommand)
{
	char* command = (char *) calloc(strlen(packages) + 80, sizeof(char));
	strcpy(command, initCommand);
	strcat(command, packages);
	system(command);
	free(command);
}
