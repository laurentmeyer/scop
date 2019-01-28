/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:20:42 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:20:44 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "alloc.h"

void	init_display(t_ram *ram)
{
	bzero(&(ram->display), sizeof(t_display));
	init_window(ram);
	init_context(ram);
	init_program(ram);
	init_vertices(ram);
	init_callbacks(ram);
	init_texture(ram, "./textures/nadine.bmp");
	ram->display.zfar = 100.;
	ram->display.znear = .1;
	ram->display.camera_position = (t_v4){0., 0., 0., 1.};
	ram->display.camera_rotation = (t_v4){0., 0., 0., 0.};
	glfwGetFramebufferSize(ram->display.window, &(ram->display.width),
			&(ram->display.height));
	init_matrices(ram);
}

void	destroy_display(t_display *display)
{
	glfwDestroyWindow(display->window);
	glfwTerminate();
}
