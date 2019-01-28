/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:54:27 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:54:28 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void				mul_m_v(t_v4 *out, t_m4 *m, t_v4 *in)
{
	out->x = (*m)[0].x * in->x + (*m)[1].x * in->y
		+ (*m)[2].x * in->z + (*m)[3].x * in->w;
	out->y = (*m)[0].y * in->x + (*m)[1].y * in->y
		+ (*m)[2].y * in->z + (*m)[3].y * in->w;
	out->z = (*m)[0].z * in->x + (*m)[1].z * in->y
		+ (*m)[2].z * in->z + (*m)[3].z * in->w;
	out->w = (*m)[0].w * in->x + (*m)[1].w * in->y
		+ (*m)[2].w * in->z + (*m)[3].w * in->w;
}

void				mul_m_m(t_m4 *out, t_m4 *a, t_m4 *b)
{
	mul_m_v(&((*out)[0]), a, &((*b)[0]));
	mul_m_v(&((*out)[1]), a, &((*b)[1]));
	mul_m_v(&((*out)[2]), a, &((*b)[2]));
	mul_m_v(&((*out)[3]), a, &((*b)[3]));
}

void				identity_m4(t_m4 *out)
{
	bzero(out, sizeof(t_m4));
	(*out)[0].x = 1;
	(*out)[1].y = 1;
	(*out)[2].z = 1;
	(*out)[3].w = 1;
}
