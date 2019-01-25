#include "display.h"
#include "scop.h"
#include "alloc.h"
#include "geometry.h"
#include "utils.h"
#include <float.h>
#include <GLFW/glfw3.h>

void	center_object(t_ram *ram)
{
	size_t		i;
	t_v3		min;
	t_v3		max;
	t_v3		cur;

	i = 0;
	min = (t_v3){FLT_MAX, FLT_MAX, FLT_MAX};
	max = (t_v3){FLT_MIN, FLT_MIN, FLT_MIN};
	while (i < ram->model.vertices_count)
	{
		cur = ram->model.vertices[i++].pos;
		min = (t_v3){minf(min.x, cur.x), minf(min.y, cur.y), minf(min.z, cur.z)};
		max = (t_v3){maxf(max.x, cur.x), maxf(max.y, cur.y), maxf(max.z, cur.z)};
	}
	cur = (t_v3){(max.x + min.x) / 2., (max.y + min.y) / 2., (max.z + min.z) / 2.};
	i = 0;
	while (i < ram->model.triangles_count)
	{
		ram->model.triangles[i][0].pos.x -= cur.x;
		ram->model.triangles[i][0].pos.y -= cur.y;
		ram->model.triangles[i][0].pos.z -= cur.z;
		ram->model.triangles[i][1].pos.x -= cur.x;
		ram->model.triangles[i][1].pos.y -= cur.y;
		ram->model.triangles[i][1].pos.z -= cur.z;
		ram->model.triangles[i][2].pos.x -= cur.x;
		ram->model.triangles[i][2].pos.y -= cur.y;
		ram->model.triangles[i][2].pos.z -= cur.z;
		i++;
	}
}

void create_vertex_buffer_objects(t_ram *ram)
{
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
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (const GLvoid *)(3 * sizeof(GLfloat)));
	glBindVertexArray(0);
}

void init_vertices(t_ram *ram)
{
	center_object(ram);
	create_vertex_buffer_objects(ram);
	create_vertex_array_objects(ram);
}