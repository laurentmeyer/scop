#include "scop.h"
#include "alloc.h"
#include "utils.h"

void	test(void) //
{
	t_m4	m1;
	t_m4	m2;

	identity_m4(&m1);
	rotate(&m1, &(t_v4){radians(0), radians(0), radians(1), 1.0});
	rotate(&m1, &(t_v4){radians(0), radians(0), radians(1), 1.0});
	identity_m4(&m2);
	rotate(&m2, &(t_v4){radians(0), radians(0), radians(2), 1.0});
	return ;
}


int main(int ac, char **av)
{
	t_ram	ram;

	test();
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