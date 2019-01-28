/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:43:00 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:48:32 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ram.h"
#include "display.h"
#include "geometry.h"
#include "utils.h"
#include "scop.h"

void	update_sliders(t_ram *ram)
{
	static float	slider_uv = 0.;
	static int		going_up_uv = 0;
	const float		step = 0.03;
	static float	slider_tex = 0.;
	static int		going_up_tex = 0;

	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_R)
			&& (slider_uv == 0. || slider_uv == 1.))
		going_up_uv = !going_up_uv;
	if (going_up_uv && slider_uv < 1.)
		slider_uv = slider_uv + step > 1.0 ? 1.0 : slider_uv + step;
	else if (!going_up_uv && slider_uv > 0.)
		slider_uv = slider_uv - step < 0.0 ? 0.0 : slider_uv - step;
	glUniform1f(ram->display.uv_slider_id, slider_uv);
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_T)
			&& (slider_tex == 0. || slider_tex == 1.))
		going_up_tex = !going_up_tex;
	if (going_up_tex && slider_tex < 1.)
		slider_tex = slider_tex + step > 1.0 ? 1.0 : slider_tex + step;
	else if (!going_up_tex && slider_tex > 0.)
		slider_tex = slider_tex - step < 0.0 ? 0.0 : slider_tex - step;
	glUniform1f(ram->display.tex_slider_id, slider_tex);
}

void	update_camera_pt2(t_ram *ram)
{
	t_v4	direction;

	direction = (t_v4){0., 0., -1., 1.};
	rotate_v(&direction, &ram->display.camera_rotation);
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_RIGHT))
	{
		rotate_v(&direction, &(t_v4){0., radians(-90), 0., 0.});
		mul_v_f(&direction, 0.2);
		direction.y = 0;
		translate_v(&ram->display.camera_position, &direction);
	}
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_E))
		ram->display.camera_position.y += 0.5;
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_Q))
		ram->display.camera_position.y -= 0.5;
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_S))
		ram->display.camera_rotation.x += radians(1);
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_W))
		ram->display.camera_rotation.x -= radians(1);
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_A))
		ram->display.camera_rotation.y += radians(1);
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_D))
		ram->display.camera_rotation.y -= radians(1);
}

void	update_camera(t_ram *ram)
{
	t_v4	tmp;
	t_v4	direction;

	direction = (t_v4){0., 0., -1., 1.};
	rotate_v(&direction, &ram->display.camera_rotation);
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_DOWN))
	{
		inverse_v4(&tmp, &direction);
		translate_v(&ram->display.camera_position, &tmp);
	}
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_UP))
		translate_v(&ram->display.camera_position, &direction);
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_LEFT))
	{
		rotate_v(&direction, &(t_v4){0., radians(90), 0., 0.});
		mul_v_f(&direction, 0.2);
		direction.y = 0;
		translate_v(&ram->display.camera_position, &direction);
	}
	update_camera_pt2(ram);
}

void	update_matrices(t_ram *ram)
{
	t_v4			tmp;
	static size_t	i = 0;

	identity_m4(&ram->display.view_matrix);
	inverse_v4(&tmp, &ram->display.camera_rotation);
	rotate_m(&ram->display.view_matrix, &tmp);
	inverse_v4(&tmp, &ram->display.camera_position);
	translate_m(&ram->display.view_matrix, &tmp);
	glUniformMatrix4fv(ram->display.view_matrix_id, 1,
			GL_FALSE, (GLfloat *)ram->display.view_matrix);
	identity_m4(&ram->display.model_matrix);
	rotate_m(&ram->display.model_matrix, &(t_v4){radians(0),
			radians(i++ * 0.5), radians(0), 1.0});
	glUniformMatrix4fv(ram->display.model_matrix_id,
			1, GL_FALSE, (GLfloat *)ram->display.model_matrix);
}

void	loop(t_ram *ram)
{
	t_display *d;

	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(ram->display.window, GLFW_TRUE);
	d = &(ram->display);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(d->program);
	update_camera(ram);
	update_matrices(ram);
	update_sliders(ram);
	glBindVertexArray(d->vao);
	glDrawArrays(GL_TRIANGLES, 0,
			ram->model.triangles_count * sizeof(t_triangle));
	glBindVertexArray(0);
	glUseProgram(0);
	glfwSwapBuffers(d->window);
	glfwPollEvents();
}
