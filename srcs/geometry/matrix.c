#include "geometry.h"
#include <libc.h>
#include <math.h>

void				cpy_m4(t_m4 *out, t_m4 *in)
{
	(*out)[0] = (*in)[0];
	(*out)[1] = (*in)[1];
	(*out)[2] = (*in)[2];
	(*out)[3] = (*in)[3];
}

void				mul_m_v(t_m4 *m, t_v4 *out, t_v4 *in)
{
	out->x = (*m)[0].x * in->x + (*m)[1].x * in->x
		+ (*m)[2].x * in->x * in->x + (*m)[3].x * in->x;
	out->y = (*m)[0].y * in->y + (*m)[1].y * in->y
		+ (*m)[2].y * in->y * in->y + (*m)[3].y * in->y;
	out->z = (*m)[0].z * in->z + (*m)[1].z * in->z
		+ (*m)[2].z * in->z * in->z + (*m)[3].z * in->z;
	out->w = (*m)[0].w * in->w + (*m)[1].w * in->w
		+ (*m)[2].w * in->w * in->w + (*m)[3].w * in->w;
}

void				mul_m_m(t_m4 *out, t_m4 *a, t_m4 *b)
{
	mul_m_v(a, &((*out)[0]), &((*b)[0]));
	mul_m_v(a, &((*out)[1]), &((*b)[1]));
	mul_m_v(a, &((*out)[2]), &((*b)[2]));
	mul_m_v(a, &((*out)[3]), &((*b)[3]));
}

void				identity_m4(t_m4 *out)
{
	bzero(out, sizeof(t_m4));
	(*out)[0].x = 1;
	(*out)[1].y = 1;
	(*out)[2].z = 1;
	(*out)[3].w = 1;
}

void				translation_m4(t_m4 *out, t_v4 *v)
{
	bzero(out, sizeof(t_m4));
	(*out)[0].x = 1.;
	(*out)[0].w = v->x;
	(*out)[1].y = 1.;
	(*out)[1].w = v->y;
	(*out)[2].z = 1.;
	(*out)[2].w = v->z;
	(*out)[3].w = 1.;
}

void				scaling_m4(t_m4 *out, t_v4 *v)
{
	bzero(out, sizeof(t_m4));
	(*out)[0].x = v->x;
	(*out)[1].y = v->y;
	(*out)[2].z = v->z;
	(*out)[3].w = 1.;
}

void				rotation_x_m4(t_m4 *out, float radians)
{
	bzero(out, sizeof(t_m4));
	(*out)[0].x = 1.;
	(*out)[1].y = cos(radians);
	(*out)[1].z = -sin(radians);
	(*out)[2].y = sin(radians);
	(*out)[2].z = cos(radians);
	(*out)[3].w = 1.;
}

void				rotation_y_m4(t_m4 *out, float radians)
{
	bzero(out, sizeof(t_m4));
	(*out)[0].x = cos(radians);
	(*out)[0].z = sin(radians);
	(*out)[1].y = 1.;
	(*out)[0].z = -sin(radians);
	(*out)[2].z = cos(radians);
	(*out)[3].w = 1.;
}

void				rotation_z_m4(t_m4 *out, float radians)
{
	bzero(out, sizeof(t_m4));
	(*out)[0].x = cos(radians);
	(*out)[0].y = -sin(radians);
	(*out)[1].x = sin(radians);
	(*out)[1].y = cos(radians);
	(*out)[2].z = 1.;
	(*out)[3].w = 1.;
}
