#include <stdlib.h>
#include "flags.h"

int main(int argc, char **argv)
{
	if ( argc > 1 )
	{
		char* arg = stringedArgument(argc, argv);
		flags(*(argv[1]), arg);
		free(arg);
	}
	else
	{
		flags('h', "");
	}

	return 0;
}
