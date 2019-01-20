#include <unistd.h>
#include <stdlib.h>
#include "alloc.h"

void	exit_message(t_ram *ram, int exit_code, char *message)
{
	if (NULL != message)
		fprintf(stderr, "%s\n", message);
	if (NULL != ram)
		destroy_ram(ram);
	exit(exit_code);
}
