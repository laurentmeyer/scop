#include "display.h"
#include "scop.h"
#include "alloc.h"
#include "geometry.h"
#include <GLFW/glfw3.h>

const char* vertex_shader =
"#version 400\n"
"in vec3 vp;"
"uniform mat4 projMatrix;"
"void main() {"
"  gl_Position = projMatrix * vec4(vp, 1.0);"
"}";

void create_vertex_shaders(t_ram *ram)
{
	int success;

	ram->display.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(ram->display.vertex_shader, 1, &vertex_shader, NULL);
	glCompileShader(ram->display.vertex_shader);
	glGetShaderiv(ram->display.vertex_shader, GL_COMPILE_STATUS, &success);
	printf("vertex shader compilation: %s\n", success ? "success" : "failure");
}

const char* fragment_shader =
"#version 400\n"
"out vec4 frag_colour;"
"void main() {"
"  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
"}";

void create_fragment_shaders(t_ram *ram)
{
	int success;

	ram->display.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(ram->display.fragment_shader, 1, &fragment_shader, NULL);
	glCompileShader(ram->display.fragment_shader);
	glGetShaderiv(ram->display.fragment_shader, GL_COMPILE_STATUS, &success);
	printf("fragment shader compilation: %s\n", success ? "success" : "failure");
}

void init_shaders(t_ram *ram)
{
	create_vertex_shaders(ram);
	create_fragment_shaders(ram);
}