#include <stdlib.h>
#include "actions.h"

/*
 **********************************************************
 * All in One Package Manager for easier "Distro Hopping" *
 **********************************************************
*/

int main(int argc, char **argv)
{
	char* arg = stringedArgument(argc, argv);
	actions(*(argv[1]), arg);
	free(arg);
	return 0;
}
