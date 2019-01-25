#include "geometry.h"
#include <libc.h>
#include <math.h>

void				inverse_v4(t_v4 *out, t_v4 *in)
{
	(*out).x = -(*in).x;
	(*out).y = -(*in).y;
	(*out).z = -(*in).z;
	(*out).w = (*in).w;
}

void				mul_v_f(t_v4 *out, float f)
{
	(*out).x *= f;
	(*out).y *= f;
	(*out).z *= f;
}