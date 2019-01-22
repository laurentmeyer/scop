#include "display.h"
#include "scop.h"
#include "alloc.h"
#include "geometry.h"
#include <GLFW/glfw3.h>

void create_vertex_buffer_objects(t_ram *ram)
{
	GLfloat vertexData[] = {0.0f, 3.0f, -5.0f, 1.0f, 1.0f, 0.0f, -3.0f, -3.0f, -5.0f, 0.0f, 1.0f, 1.0f, 3.0f, -3.0f, -5.0f, 1.0f, 0.0f, 1.0f};
	ram->model.vertices_count = sizeof(vertexData) / sizeof(t_vertexData);
	ram->model.vertices = (t_vertexData *)malloc(ram->model.vertices_count * sizeof(t_vertexData));
	if (NULL == ram->model.vertices)
		exit_message(ram, EXIT_FAILURE, "Could not allocate vertex data");
	memcpy(ram->model.vertices, vertexData, sizeof(vertexData));
	glGenBuffers(1, &(ram->display.vbo));
	glBindBuffer(GL_ARRAY_BUFFER, ram->display.vbo);
	glBufferData(GL_ARRAY_BUFFER, ram->model.vertices_count * sizeof(t_vertexData), vertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void create_vertex_array_objects(t_ram *ram)
{
	glGenVertexArrays(1, &(ram->display.vao));
	glBindVertexArray(ram->display.vao);
	glBindBuffer(GL_ARRAY_BUFFER, ram->display.vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertexData), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertexData), (const GLvoid *)(3 * sizeof(GLfloat)));
	glBindVertexArray(0);
}

void init_vertices(t_ram *ram)
{
	create_vertex_buffer_objects(ram);
	create_vertex_array_objects(ram);
}