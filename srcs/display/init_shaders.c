#include "display.h"
#include "scop.h"
#include "alloc.h"
#include "geometry.h"
#include <GLFW/glfw3.h>


void create_vertex_shaders(t_ram *ram)
{
	char	*program;
	int		success;

	program = parse_shader(ram, "./shaders/vertex/basic.glsl");
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

void init_shaders(t_ram *ram)
{
	create_vertex_shaders(ram);
	create_fragment_shaders(ram);
}