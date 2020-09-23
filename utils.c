#include "utils.h"
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
			case pacman:
				if ( checkIfFileExists("/usr/bin/pacman") == 0 )
				{
					exists = i;
				}
				break;

			case apt:
				if ( checkIfFileExists("/usr/bin/apt") == 0 )
				{
					exists = i;
				}
				break;

			case emerge:
				if ( checkIfFileExists("/usr/bin/emerge") == 0 )
				{
					exists = i;
				}
				break;

			case xbps:
				if ( checkIfFileExists("/usr/bin/xbps-install") == 0 )
				{
					exists = i;
				}
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
