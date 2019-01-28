/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_matrices.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:50:32 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:56:42 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "scop.h"
#include <libc.h>
#include <math.h>

static inline void	orthographic_projection_m4(
		t_m4 *out,
		float const wh[2],
		float const znear,
		float const zfar)
{
	float const	c = 180. / M_PI;

	bzero(out, sizeof(t_m4));
	(*out)[0].x = atan(c * atan(wh[0] / znear));
	(*out)[1].y = atan(c * atan(wh[1] / znear));
	(*out)[2].z = -2. / (zfar - znear);
	(*out)[2].w = -(zfar + znear) / (zfar - znear);
	(*out)[3].w = 1;
}

void				ortho(t_m4 *out, t_ram *ram)
{
	orthographic_projection_m4(
			out,
			(float[2]){ram->display.width, ram->display.height},
			ram->display.znear,
			ram->display.zfar);
}
