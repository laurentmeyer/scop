#include "display.h"
#include "scop.h"
#include "alloc.h"
#include "geometry.h"
#include <GLFW/glfw3.h>

void create_vertex_buffer_objects(t_ram *ram)
{
	// GLfloat vertexData[] = {0.0f, 3.0f, -5.0f, 1.0f, 1.0f, 0.0f, -3.0f, -3.0f, -5.0f, 0.0f, 1.0f, 1.0f, 3.0f, -3.0f, -5.0f, 1.0f, 0.0f, 1.0f};
	// size_t i = 0;
	// while (i < ram->model.triangles_count * sizeof(t_triangle) / sizeof(GLfloat))
	// {
	// 	printf("%f\n", ((GLfloat *)(ram->model.triangles))[i]);
	// 	i++;
	// }
	glGenBuffers(1, &(ram->display.vbo));
	glBindBuffer(GL_ARRAY_BUFFER, ram->display.vbo);
	glBufferData(GL_ARRAY_BUFFER, ram->model.triangles_count * sizeof(t_triangle), ram->model.triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void create_vertex_array_objects(t_ram *ram)
{
	glGenVertexArrays(1, &(ram->display.vao));
	glBindVertexArray(ram->display.vao);
	glBindBuffer(GL_ARRAY_BUFFER, ram->display.vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertex), 0);
	// glEnableVertexAttribArray(1);
	// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (const GLvoid *)(3 * sizeof(GLfloat)));
	glBindVertexArray(0);
}

void init_vertices(t_ram *ram)
{
	create_vertex_buffer_objects(ram);
	create_vertex_array_objects(ram);
}