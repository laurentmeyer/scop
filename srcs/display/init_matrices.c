/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:29:05 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:29:06 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "alloc.h"

void	init_matrices(t_ram *ram)
{
	glUseProgram(ram->display.program);
	ortho(&ram->display.proj_matrix, ram);
	glUniformMatrix4fv(ram->display.proj_matrix_id, 1,
			GL_FALSE, (GLfloat *)ram->display.proj_matrix);
	identity_m4(&ram->display.view_matrix);
	glUniformMatrix4fv(ram->display.view_matrix_id, 1,
			GL_FALSE, (GLfloat *)ram->display.view_matrix);
	identity_m4(&ram->display.model_matrix);
	glUniformMatrix4fv(ram->display.model_matrix_id, 1,
			GL_FALSE, (GLfloat *)ram->display.model_matrix);
	glUseProgram(0);
}
