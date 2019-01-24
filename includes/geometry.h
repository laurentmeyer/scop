#ifndef GEOMETRY_H
# define GEOMETRY_H

typedef struct		s_v4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_v4;

typedef	t_v4		t_col;
typedef	t_col		t_m4[4];


void				cpy_m4(t_m4 *out, t_m4 *in);
void				mul_m_v(t_v4 *out, t_m4 *m, t_v4 *in);
void				mul_m_m(t_m4 *out, t_m4 *a, t_m4 *b);
void				identity_m4(t_m4 *out);
void				translation_m4(t_m4 *out, t_v4 *v);
void				scaling_m4(t_m4 *out, t_v4 *v);
void				rotation_x_m4(t_m4 *out, float radians);
void				rotation_y_m4(t_m4 *out, float radians);
void				rotation_z_m4(t_m4 *out, float radians);
void				translate(t_m4 *m, t_v4 *v);
void				rotate(t_m4 *m, t_v4 *v);
void				print_matrix(t_m4 *m);

#endif