/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:19:00 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:19:22 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "alloc.h"
#include "utils.h"

int		main(int ac, char **av)
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
