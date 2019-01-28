/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:28:33 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:44:50 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "alloc.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void	init_window(t_ram *ram)
{
	t_display *d;

	d = &(ram->display);
	if (!glfwInit())
		exit_message(ram, EXIT_FAILURE, "Could not init GLFW");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	d->window = glfwCreateWindow(WIN_W, WIN_H, WIN_NAME, NULL, NULL);
	if (!d->window)
		exit_message(ram, EXIT_FAILURE, "Could not init window");
}

void	init_context(t_ram *ram)
{
	glfwMakeContextCurrent(ram->display.window);
	glewExperimental = GL_TRUE;
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}
