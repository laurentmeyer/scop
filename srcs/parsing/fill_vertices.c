#include <libc.h>
#include <math.h>
#include "ram.h"
#include "model.h"
#include "alloc.h"
#include "utils.h"
#include "libft.h"
#include <float.h>

void	fill_vertex(t_ram *ram)
{
	static size_t	pos = 0;
	t_vertex		*v;
	int				s;

	v = ram->model.vertices + pos++;
	s = sscanf(ram->parser.line, "v %f %f %f", &(v->pos.x), &(v->pos.y),
			&(v->pos.z));
	// printf("%f.3 %f.3 %f.3\n", v->pos.x, v->pos.y, v->pos.z);
	if (3 != s)
	{
		fprintf(stderr, "Error parsing vertex: ");
		exit_message(ram, EXIT_FAILURE, ram->parser.line);
	}
}

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
	while (i < ram->model.vertices_count)
	{
		ram->model.vertices[i].pos.x -= cur.x;
		ram->model.vertices[i].pos.y -= cur.y;
		ram->model.vertices[i++].pos.z -= cur.z;
	}
}

void fill_vertices(t_ram *ram)
{
	int f;
	int read;

	if (-1 == (f = open(ram->parser.obj_path, O_RDONLY)))
		exit_message(ram, EXIT_FAILURE, "Invalid shader program path");
	while (0 != (read = gnlite(f, &(ram->parser.line))))
	{
		if (-1 == read)
			exit_message(ram, EXIT_FAILURE, "Error reading obj file");
		if (ft_countwords(ram->parser.line, ' ') == 4
			&& first_word_is(ram->parser.line, "v"))
			fill_vertex(ram);
		free(ram->parser.line);
		ram->parser.line = NULL;
	}
	free(ram->parser.line);
	ram->parser.line = NULL;
	close(f);
}