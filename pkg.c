#include <stdlib.h>
#include "actions.h"

/*
 **********************************************************
 * All in One Package Manager for easier "Distro Hopping" *
 **********************************************************
 */

int main(int argc, char **argv)
{
	if ( argc > 1 )
	{
		char* arg = stringedArgument(argc, argv);
		actions(*(argv[1]), arg);
		free(arg);
	}
	else
	{
		actions('h', "");
	}

	return 0;
}
