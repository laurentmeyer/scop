#include "display.h"
#include "scop.h"
#include "alloc.h"
#include <GLFW/glfw3.h>

const char* vertex_shader =
"#version 400\n"
"in vec3 vp;"
"void main() {"
"  gl_Position = vec4(vp, 1.0);"
"}";

void create_vertex_shaders(t_ram *ram)
{
	ram->display.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(ram->display.vertex_shader, 1, &vertex_shader, NULL);
	glCompileShader(ram->display.vertex_shader);
	// check for compile errors ??
}

const char* fragment_shader =
"#version 400\n"
"out vec4 frag_colour;"
"void main() {"
"  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
"}";

void create_fragment_shaders(t_ram *ram)
{
	ram->display.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(ram->display.fragment_shader, 1, &fragment_shader, NULL);
	glCompileShader(ram->display.fragment_shader);
	// check for compile errors ??
}

void create_vertex_buffer_objects(t_ram *ram)
{
	GLfloat vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
	memcpy(&(ram->display.vertices), vertices, sizeof(vertices));
	glGenBuffers(1, &(ram->display.vbo));
	glBindBuffer(GL_ARRAY_BUFFER, ram->display.vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), ram->display.vertices, GL_STATIC_DRAW);
	// glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void create_vertex_array_objects(t_ram *ram)
{
	glGenVertexArrays(1, &(ram->display.vao));
	glBindVertexArray(ram->display.vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, ram->display.vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	// glBindVertexArray(0);
}

void create_program(t_ram *ram)
{
	ram->display.program = glCreateProgram();
	if (0 == ram->display.program)
		exit_message(ram, EXIT_FAILURE, "Could not init proram");
	glAttachShader(ram->display.program, ram->display.vertex_shader);
	glAttachShader(ram->display.program, ram->display.fragment_shader);
	glLinkProgram(ram->display.program);
	// check for linking errors ??
}

void set_buffers_shaders_and_program(t_ram *ram)
{
	create_vertex_buffer_objects(ram);
	create_vertex_array_objects(ram);
	create_vertex_shaders(ram);
	create_fragment_shaders(ram);
	create_program(ram);
	printf("%s\n", "[display/init.c] Need to import buffers, shaders etc");
}