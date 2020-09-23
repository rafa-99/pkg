#include "utils.h"

/*
 **********************************************************
 * All in One Package Manager for easier "Distro Hopping" *
 **********************************************************
*/

int main(int argc, char **argv)
{
	char* arg = stringedArgument(argc, argv);
	free(arg);
	return 0;
}
