#include <libc.h>
#include "model.h"
#include "ram.h"
#include "alloc.h"

void init_model(t_ram *ram)
{
	t_model	*m;

	m = &(ram->model);
	bzero(m, sizeof(t_model));
	count_elements(ram);
	m->triangles = (t_triangle *)malloc(m->triangles_count * sizeof(t_triangle));
	m->vertices = (t_vertex *)malloc(m->vertices_count * sizeof(t_vertex));
	if (NULL == m->triangles || NULL == m->vertices)
		exit_message(ram, EXIT_FAILURE, "Could not allocate model memory");
	fill_vertices(ram);
	center_object(ram);
	fill_triangles(ram);
	fill_uvs(ram);
}

void destroy_model(t_model *model)
{
	if (NULL != model->triangles)
	{
		free(model->triangles);
		model->triangles = NULL;
	}
	if (NULL != model->vertices)
	{
		free(model->vertices);
		model->vertices = NULL;
	}
}