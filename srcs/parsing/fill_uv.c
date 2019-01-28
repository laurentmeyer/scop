#include <libc.h>
#include <math.h>
#include "ram.h"
#include "model.h"
#include "alloc.h"
#include "utils.h"
#include "libft.h"

void fill_uv_sphere(t_triangle *t)
{
	size_t j;
	t_v3 p;
	float norm;
	t_v2 *uv;

	j = 0;
	while (j < 3)
	{
		p = (*t)[j].pos;
		norm = sqrtf(p.x * p.x + p.y * p.y + p.z * p.z);
		p = (t_v3){-p.x / norm, -p.y / norm, -p.z / norm};
		uv = &(*t)[j].tcoord_sph;
		uv->x = atan2f(p.x, p.z) / (2 * M_PI) + 0.5;
		uv->y = 0.5 - asinf(p.y) / M_PI;
		j++;
	}
}

void normalize_uv_sphere(t_triangle *t)
{
	float u[3];

	u[0] = (*t)[0].tcoord_sph.x;
	u[1] = (*t)[1].tcoord_sph.x;
	u[2] = (*t)[2].tcoord_sph.x;
	if (u[0] < 0.2 && u[1] > 0.8 && u[2] > 0.8)
		(*t)[0].tcoord_sph.x = 0.99;
	else if (u[1] < 0.2 && u[0] > 0.8 && u[2] > 0.8)
		(*t)[1].tcoord_sph.x = 0.99;
	else if (u[2] < 0.2 && u[0] > 0.8 && u[1] > 0.8)
		(*t)[2].tcoord_sph.x = 0.99;
	else if (u[0] > 0.8 && u[1] < 0.2 && u[2] < 0.2)
		(*t)[0].tcoord_sph.x = 0.0;
	else if (u[1] > 0.8 && u[0] < 0.2 && u[2] < 0.2)
		(*t)[1].tcoord_sph.x = 0.0;
	else if (u[2] > 0.8 && u[0] < 0.2 && u[1] < 0.2)
		(*t)[2].tcoord_sph.x = 0.0;
}

void fill_uv_triangle(t_triangle *t)
{
	t_v2 min;
	t_v2 max;

	min = (t_v2){minf((*t)[0].pos.x, (*t)[1].pos.x),
				 minf((*t)[0].pos.y, (*t)[1].pos.y)};
	min = (t_v2){minf(min.x, (*t)[2].pos.x),
				 minf(min.y, (*t)[2].pos.y)};
	max = (t_v2){maxf((*t)[0].pos.x, (*t)[1].pos.x),
				 maxf((*t)[0].pos.y, (*t)[1].pos.y)};
	max = (t_v2){maxf(max.x, (*t)[2].pos.x),
				 maxf(max.y, (*t)[2].pos.y)};
	(*t)[0].tcoord_tri = (t_v2){percentage_f(min.x, max.x,
											 (*t)[0].pos.x),
								percentage_f(min.y, max.y, (*t)[0].pos.y)};
	(*t)[1].tcoord_tri = (t_v2){percentage_f(min.x, max.x,
											 (*t)[1].pos.x),
								percentage_f(min.y, max.y, (*t)[1].pos.y)};
	(*t)[2].tcoord_tri = (t_v2){percentage_f(min.x, max.x,
											 (*t)[2].pos.x),
								percentage_f(min.y, max.y, (*t)[2].pos.y)};
}

void fill_uvs(t_ram *ram)
{
	size_t i;

	i = 0;
	while (i < ram->model.triangles_count)
	{
		fill_uv_sphere(ram->model.triangles + i);
		normalize_uv_sphere(ram->model.triangles + i);
		fill_uv_triangle(ram->model.triangles + i);
		i++;
	}
}