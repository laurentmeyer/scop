#include "display.h"
#include "scop.h"
#include "alloc.h"
#include "geometry.h"
#include <GLFW/glfw3.h>


void create_vertex_shaders(t_ram *ram)
{
	char	*program;
	int		success;

	program = parse_shader(ram, "./shaders/vertex/movement.glsl");
	// program = parse_shader(ram, "./shaders/vertex/basic.glsl");
	ram->display.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(ram->display.vertex_shader, 1, (const GLchar *const *)(&program), NULL);
	glCompileShader(ram->display.vertex_shader);
	glGetShaderiv(ram->display.vertex_shader, GL_COMPILE_STATUS, &success);
	printf("vertex shader compilation: %s\n", success ? "success" : "failure");
	free(program);
}

void create_fragment_shaders(t_ram *ram)
{
	char	*program;
	int success;

	program = parse_shader(ram, "./shaders/fragment/basic.glsl");
	ram->display.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(ram->display.fragment_shader, 1, (const GLchar *const *)(&program), NULL);
	glCompileShader(ram->display.fragment_shader);
	glGetShaderiv(ram->display.fragment_shader, GL_COMPILE_STATUS, &success);
	printf("fragment shader compilation: %s\n", success ? "success" : "failure");
	free(program);
}

void init_program(t_ram *ram)
{
	int link_success;

	ram->display.program = glCreateProgram();
	if (0 == ram->display.program)
		exit_message(ram, EXIT_FAILURE, "Could not init program");
	create_vertex_shaders(ram);
	glAttachShader(ram->display.program, ram->display.vertex_shader);
	create_fragment_shaders(ram);
	glAttachShader(ram->display.program, ram->display.fragment_shader);
	glLinkProgram(ram->display.program);
	glGetProgramiv(ram->display.program, GL_LINK_STATUS, &link_success);
	printf("shader program linking: %s\n", link_success ? "success" : "failure");
	// check for linking errors ??
	ram->display.proj_matrix_id = glGetUniformLocation(ram->display.program, "projMatrix");
	ram->display.viewMatID = glGetUniformLocation(ram->display.program, "viewMatrix");
	ram->display.modelMatID = glGetUniformLocation(ram->display.program, "modelMatrix");
	if (-1 == ram->display.proj_matrix_id
		|| -1 == ram->display.viewMatID
		|| -1 == ram->display.modelMatID)
		exit_message(ram, EXIT_FAILURE, "Could not retrieve uniform Mat IDs");
}