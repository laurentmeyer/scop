/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:50:24 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:50:25 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "scop.h"
#include <libc.h>
#include <math.h>

void				translate_m(t_m4 *out, t_v4 *v)
{
	t_m4	cpy;
	t_m4	translation;

	cpy_m4(&cpy, out);
	translation_m4(&translation, v);
	mul_m_m(out, &cpy, &translation);
}

void				translate_v(t_v4 *out, t_v4 *v)
{
	t_v4	cpy;
	t_m4	translation;

	cpy = *out;
	translation_m4(&translation, v);
	mul_m_v(out, &translation, &cpy);
}

void				rotate_m(t_m4 *out, t_v4 *v)
{
	t_m4	tmp1;
	t_m4	tmp2;
	t_m4	rotation;

	cpy_m4(&tmp1, out);
	rotation_x_m4(&rotation, v->x);
	mul_m_m(&tmp2, &tmp1, &rotation);
	rotation_y_m4(&rotation, v->y);
	mul_m_m(&tmp1, &tmp2, &rotation);
	rotation_z_m4(&rotation, v->z);
	mul_m_m(out, &tmp1, &rotation);
}

void				rotate_v(t_v4 *out, t_v4 *v)
{
	t_m4	rotation;
	t_v4	tmp1;
	t_v4	tmp2;

	tmp1 = *out;
	rotation_x_m4(&rotation, v->x);
	mul_m_v(&tmp2, &rotation, &tmp1);
	rotation_y_m4(&rotation, v->y);
	mul_m_v(&tmp1, &rotation, &tmp2);
	rotation_z_m4(&rotation, v->z);
	mul_m_v(out, &rotation, &tmp1);
}
