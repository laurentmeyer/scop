#include "display.h"
#include "scop.h"
#include "alloc.h"
#include "geometry.h"
#include <GLFW/glfw3.h>

void create_vertex_buffer_objects(t_ram *ram)
{

	GLfloat vertices[] = {-3.0f, -3.0f, -5.0f, 3.0f, -3.0f, -5.0f, 0.0f, 3.0f, -5.0f};
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

void init_buffers(t_ram *ram)
{
	create_vertex_buffer_objects(ram);
	create_vertex_array_objects(ram);
}