#include "utils.h"
#include <unistd.h>

int checkIfFileExists(char *path)
{
	return access(path, F_OK);
}

int detectOsType()
{
	int exists = ERROR;
	for ( int i = 0; i < ENUMSIZE || exists == ERROR; i++ )
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
