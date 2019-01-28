/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:54:15 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:54:16 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <libc.h>
#include <math.h>

void				translation_m4(t_m4 *out, t_v4 *v)
{
	bzero(out, sizeof(t_m4));
	(*out)[0].x = 1.;
	(*out)[1].y = 1.;
	(*out)[2].z = 1.;
	(*out)[3].w = 1.;
	(*out)[3].x = v->x;
	(*out)[3].y = v->y;
	(*out)[3].z = v->z;
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
	(*out)[3].w = 1.;
	(*out)[1].y = cos(radians);
	(*out)[1].z = sin(radians);
	(*out)[2].y = -sin(radians);
	(*out)[2].z = cos(radians);
}

void				rotation_y_m4(t_m4 *out, float radians)
{
	bzero(out, sizeof(t_m4));
	(*out)[1].y = 1.;
	(*out)[3].w = 1.;
	(*out)[0].x = cos(radians);
	(*out)[0].z = -sin(radians);
	(*out)[2].x = sin(radians);
	(*out)[2].z = cos(radians);
}

void				rotation_z_m4(t_m4 *out, float radians)
{
	bzero(out, sizeof(t_m4));
	(*out)[2].z = 1.;
	(*out)[3].w = 1.;
	(*out)[0].x = cos(radians);
	(*out)[0].y = sin(radians);
	(*out)[1].x = -sin(radians);
	(*out)[1].y = cos(radians);
}
