#include "scop.h"
#include "alloc.h"

int main(void)
{
	t_ram	ram;

	init_ram(&ram);
	while (!glfwWindowShouldClose(ram.display.window))
		loop(&ram);
	destroy_ram(&ram);
	return (EXIT_SUCCESS);
}