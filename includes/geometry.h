/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:12:57 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:13:03 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void				mul_v_f(t_v4 *out, float f);
void				inverse_v4(t_v4 *out, t_v4 *in);
void				identity_m4(t_m4 *out);
void				translation_m4(t_m4 *out, t_v4 *v);
void				scaling_m4(t_m4 *out, t_v4 *v);
void				rotation_x_m4(t_m4 *out, float radians);
void				rotation_y_m4(t_m4 *out, float radians);
void				rotation_z_m4(t_m4 *out, float radians);
void				translate_m(t_m4 *m, t_v4 *v);
void				translate_v(t_v4 *out, t_v4 *v);
void				rotate_m(t_m4 *m, t_v4 *v);
void				rotate_v(t_v4 *out, t_v4 *v);
void				print_matrix(t_m4 *m);
void				print_vector(t_v4 *v);

#endif
