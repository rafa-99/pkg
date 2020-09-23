#include <stdlib.h>
#include <string.h>
#include "actions.h"

void actions(char action, char* packages)
{
	int os = detectOsType();
	switch (action)
	{
		case 'c':
			cleanPackages(os);
			break;

		case 'h':
			help();
			break;

		case 'i':
			installPackages(os, packages);
			break;

		case 'q':
			queryPackages(os);
			break;

		case 'r':
			removePackages(os, packages);
			break;

		case 's':
			searchPackages(os, packages);
			break;

		case 'u':
			updatePackages(os);
			break;

		default:
			puts("Command not found");
			help();
	}
}

void cleanPackages(int os)
{
	switch(os)
	{
		case pacman:
			system("pacman -Rns \"$(pacman -Qtdq)\" || pacman -Scc");
			break;

		case apt:
			system("apt autoremove --purge || apt clean");
			break;

		case emerge:
			system("emerge -caq");
			break;

		case xbps:
			system("xbps-remove -ROo");
	}
}

void help()
{
	printf("PKG Options:\n"
		"c - removes orphans and cleans the package cache\n"
		"h - display this message\n"
		"i - installs selected packages\n"
		"q - display installed packages\n"
		"r - remove a selected package\n"
		"s - look up for a package in the available repositories\n"
		"u - updates repos and packages\n\n");
}

void installPackages(int os, char *packages)
{
	if ( strlen(packages) > 0 )
	{
		char* command = (char *) calloc(strlen(packages) + 80, sizeof(char));
		switch(os)
		{
			case pacman:
				strcpy(command, "pacman -S ");
				strcat(command, packages);
				system(command);
				free(command);
				break;

			case apt:
				strcpy(command, "apt install ");
				strcat(command, packages);
				system(command);
				free(command);
				break;

			case emerge:
				strcpy(command, "emerge -aq ");
				strcat(command, packages);
				system(command);
				free(command);
				break;

			case xbps:
				strcpy(command, "xbps-install -S ");
				strcat(command, packages);
				system(command);
				free(command);
		}
	}
}

void queryPackages(int os)
{

}

void removePackages(int os, char *packages)
{

}

void searchPackages(int os, char *packages)
{

}

void updatePackages(int os)
{

}
