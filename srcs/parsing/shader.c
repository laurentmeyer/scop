#include <libc.h>
#include "ram.h"
#include "alloc.h"

char *parse_shader(t_ram *ram, char const *path)
{
	char *string;
	FILE *f;

	if (NULL == (f = fopen(path, "rb")))
		exit_message(ram, EXIT_FAILURE, "Invalid shader program path");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	if (NULL == (string = (char *)malloc(fsize + 1)))
		exit_message(ram, EXIT_FAILURE, "Could not allocate space for shader programs");
	fread(string, fsize, 1, f);
	fclose(f);
	string[fsize] = 0;
	return (string);
}