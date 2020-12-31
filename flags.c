#include "flags.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
flags (char flag, char *packages)
{
	int os = detectOsType ();
	switch (flag)
	{
		case 'c':
			cleanPackages (os);
			break;

		case 'h':
			help ();
			break;

		case 'i':
			installPackages (os, packages);
			break;

		case 'q':
			queryPackages (os);
			break;

		case 'r':
			removePackages (os, packages);
			break;

		case 's':
			searchPackages (os, packages);
			break;

		case 'u':
			updatePackages (os);
			break;

		default:
			puts ("Command not found");
			help ();
	}
}

void
cleanPackages (int os)
{
	switch (os)
	{
		case dnf:
			system ("dnf clean all && dnf autoremove");
			break;

		case emerge:
			system ("emerge -caq");
			break;

		case pacman:
			system ("pacman -Qttdq | pacman -Rns - || pacman -Scc");
			break;

		case xbps:
			system ("xbps-remove -ROo");
			break;

		case zypper:
			system ("zypper cc -a");
			break;

		case apt:
			system ("apt autoremove --purge || apt clean");
	}
}

void
help ()
{
	printf ("PKG Options:\n"
			"c - removes orphans and cleans the package cache\n"
			"h - display this message\n"
			"i - installs selected packages\n"
			"q - display installed packages\n"
			"r - remove a selected package\n"
			"s - look up for a package in the available repositories\n"
			"u - updates repos and packages\n\n");
}

void
installPackages (int os, char *packages)
{
	if (strlen (packages) > 0)
	{
		switch (os)
		{
			case dnf:
				commandProcessor (packages, "dnf install ");
				break;

			case emerge:
				commandProcessor (packages, "emerge -aq ");
				break;

			case pacman:
				commandProcessor (packages, "pacman -S ");
				break;

			case xbps:
				commandProcessor (packages, "xbps-install -S ");
				break;

			case zypper:
				commandProcessor (packages, "zypper install ");
				break;

			case apt:
				commandProcessor (packages, "apt install ");
		}
	}
}

void
queryPackages (int os)
{
	switch (os)
	{
		case dnf:
			system ("dnf list --installed");
			break;

		case emerge:
			system ("cd /var/db/pkg/ && ls -d */* | sed 's:\\/$::'");
			break;

		case pacman:
			system ("pacman -Qs");
			break;

		case xbps:
			system ("xbps-query -l");
			break;

		case zypper:
			system ("zypper packages -i");
			break;

		case apt:
			system ("apt list --installed");
	}
}

void
removePackages (int os, char *packages)
{
	if (strlen (packages) > 0)
	{
		switch (os)
		{
			case dnf:
				commandProcessor (packages, "dnf remove ");
				break;

			case emerge:
				commandProcessor (packages, "emerge -caq ");
				break;

			case pacman:
				commandProcessor (packages, "pacman -Rnsc ");
				break;

			case xbps:
				commandProcessor (packages, "xbps-remove -ROo ");
				break;

			case zypper:
				commandProcessor (packages, "zypper remove -u ");
				break;

			case apt:
				commandProcessor (packages, "apt autoremove --purge ");
		}
	}
}

void
searchPackages (int os, char *packages)
{
	if (strlen (packages) > 0)
	{
		switch (os)
		{
			case dnf:
				commandProcessor (packages, "dnf search ");
				break;

			case emerge:
				commandProcessor (packages, "emerge -s ");
				break;

			case pacman:
				commandProcessor (packages, "pacman -Ss ");
				break;

			case xbps:
				commandProcessor (packages, "xbps-query -Rs ");
				break;

			case zypper:
				commandProcessor (packages, "zypper search ");
				break;

			case apt:
				commandProcessor (packages, "apt search ");
		}
	}
}

void
updatePackages (int os)
{
	switch (os)
	{
		case dnf:
			system ("dnf update");
			break;

		case emerge:
			system ("emerge-webrsync && emerge -uaqDU --keep-going --with-bdeps=y "
					"--newuse @world");
			break;

		case pacman:
			system ("pacman -Syyuu");
			break;

		case xbps:
			system ("xbps-install -Su");
			break;

		case zypper:
			system ("zypper update && zypper dist-upgrade");
			break;

		case apt:
			system ("apt update && apt upgrade -y");
	}
}
