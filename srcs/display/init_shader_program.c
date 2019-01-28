/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shader_program.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:43:51 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:44:03 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "scop.h"
#include "alloc.h"
#include "geometry.h"
#include <GLFW/glfw3.h>

void	create_vertex_shaders(t_ram *ram)
{
	char	*program;
	int		success;

	program = parse_shader(ram, "./shaders/vertex/coords.glsl");
	ram->display.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(ram->display.vertex_shader, 1,
			(const GLchar *const *)(&program), NULL);
	glCompileShader(ram->display.vertex_shader);
	glGetShaderiv(ram->display.vertex_shader, GL_COMPILE_STATUS, &success);
	free(program);
}

void	create_fragment_shaders(t_ram *ram)
{
	char	*program;
	int		success;

	program = parse_shader(ram, "./shaders/fragment/transition.glsl");
	ram->display.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(ram->display.fragment_shader, 1,
			(const GLchar *const *)(&program), NULL);
	glCompileShader(ram->display.fragment_shader);
	glGetShaderiv(ram->display.fragment_shader, GL_COMPILE_STATUS, &success);
	free(program);
}

void	init_program(t_ram *ram)
{
	int		link_success;
	GLuint	program;

	ram->display.program = glCreateProgram();
	if (0 == ram->display.program)
		exit_message(ram, EXIT_FAILURE, "Could not init program");
	program = ram->display.program;
	create_vertex_shaders(ram);
	glAttachShader(program, ram->display.vertex_shader);
	create_fragment_shaders(ram);
	glAttachShader(program, ram->display.fragment_shader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link_success);
	ram->display.proj_matrix_id = glGetUniformLocation(program, "projMatrix");
	ram->display.view_matrix_id = glGetUniformLocation(program, "viewMatrix");
	ram->display.model_matrix_id = glGetUniformLocation(program, "modelMatrix");
	ram->display.tex_slider_id = glGetUniformLocation(program, "textureSlider");
	ram->display.uv_slider_id = glGetUniformLocation(program, "uvSlider");
	if (-1 == ram->display.proj_matrix_id || -1 == ram->display.view_matrix_id
		|| -1 == ram->display.model_matrix_id
		|| -1 == ram->display.tex_slider_id || -1 == ram->display.uv_slider_id)
		exit_message(ram, EXIT_FAILURE, "Could not retrieve uniform Mat IDs");
}
