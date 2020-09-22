#include "actions.h"

void actions(char action)
{
	int os = detectOsType();
	switch (action)
	{
		case 'c':
			clean(os);
			break;

		case 'h':
			help();
			break;

		case 'i':
			installPackage(os);
			break;

		case 'q':
			queryPackage(os);
			break;

		case 'r':
			removePackage(os);
			break;

		case 's':
			searchPackage(os);
			break;

		case 'u':
			updatePackage(os);
			break;

		default:
			puts("Command not found");
			help();
	}
}
