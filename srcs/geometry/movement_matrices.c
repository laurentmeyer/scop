#include "geometry.h"
#include "scop.h"
#include <libc.h>
#include <math.h>

void				translate(t_m4 *m, t_v4 *v)
{
	t_m4	cpy;
	t_m4	translation;

	cpy_m4(&cpy, m);
	translation_m4(&translation, v);
	mul_m_m(m, &cpy, &translation);
}

void				rotate(t_m4 *m, t_v4 *v)
{
	t_m4	tmp1;
	t_m4	tmp2;
	t_m4	rotation;

	cpy_m4(&tmp1, m);
	rotation_x_m4(&rotation, v->x);
	mul_m_m(&tmp2, &tmp1, &rotation);
	rotation_y_m4(&rotation, v->y);
	mul_m_m(&tmp1, &tmp2, &rotation);
	rotation_z_m4(&rotation, v->z);
	mul_m_m(m, &tmp1, &rotation);
}