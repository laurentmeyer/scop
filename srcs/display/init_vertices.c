/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vertices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:33:59 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:43:39 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "scop.h"
#include "alloc.h"
#include "geometry.h"
#include "utils.h"
#include <GLFW/glfw3.h>

void	create_vertex_buffer_objects(t_ram *ram)
{
	glGenBuffers(1, &(ram->display.vbo));
	glBindBuffer(GL_ARRAY_BUFFER, ram->display.vbo);
	glBufferData(GL_ARRAY_BUFFER, ram->model.triangles_count
			* sizeof(t_triangle), ram->model.triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void	create_vertex_array_objects(t_ram *ram)
{
	glGenVertexArrays(1, &(ram->display.vao));
	glBindVertexArray(ram->display.vao);
	glBindBuffer(GL_ARRAY_BUFFER, ram->display.vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(t_vertex),
			(const GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(t_vertex),
			(const GLvoid *)(5 * sizeof(GLfloat)));
	glBindVertexArray(0);
}

void	init_vertices(t_ram *ram)
{
	create_vertex_buffer_objects(ram);
	create_vertex_array_objects(ram);
}
