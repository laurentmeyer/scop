#include "scop.h"
#include "alloc.h"
#include "utils.h"

int main(int ac, char **av)
{
	t_ram	ram;

	if (ac != 2)
	{
		fprintf(stderr, "usage: ./scop [obj file path]\n");
		return (EXIT_SUCCESS);
	}
	init_ram(&ram, av[1]);
	while (!glfwWindowShouldClose(ram.display.window))
		loop(&ram);
	destroy_ram(&ram);
	return (EXIT_SUCCESS);
}