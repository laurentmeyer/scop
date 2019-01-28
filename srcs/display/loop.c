#include "ram.h"
#include "display.h"
#include "geometry.h"
#include "utils.h"
#include "scop.h"

void	update_uv_slider(t_ram *ram)
{
	static float	slider = 0.;
	static int		going_up = 0;
	const float		step = 0.03;

	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_R)
		&& (slider == 0. || slider == 1.))
		going_up = !going_up;
	if (going_up && slider < 1.)
		slider = slider + step > 1.0 ? 1.0 : slider + step;
	else if (!going_up && slider > 0.)
		slider = slider - step < 0.0 ? 0.0 : slider - step;
	glUniform1f(ram->display.uv_slider_id, slider);
}

void	update_texture_slider(t_ram *ram)
{
	static float	slider = 0.;
	static int		going_up = 0;
	const float		step = 0.03;

	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_T)
		&& (slider == 0. || slider == 1.))
		going_up = !going_up;
	if (going_up && slider < 1.)
		slider = slider + step > 1.0 ? 1.0 : slider + step;
	else if (!going_up && slider > 0.)
		slider = slider - step < 0.0 ? 0.0 : slider - step;
	glUniform1f(ram->display.tex_slider_id, slider);
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

void	update_matrices(t_ram *ram)
{
	t_v4	tmp;

	identity_m4(&ram->display.view_matrix);
	inverse_v4(&tmp, &ram->display.camera_rotation);
    rotate_m(&ram->display.view_matrix, &tmp);
	inverse_v4(&tmp, &ram->display.camera_position);
    translate_m(&ram->display.view_matrix, &tmp);
	glUniformMatrix4fv(ram->display.view_matrix_id, 1, GL_FALSE, (GLfloat *)ram->display.view_matrix);

	identity_m4(&ram->display.model_matrix);
	static size_t i = 0;
	rotate_m(&ram->display.model_matrix, &(t_v4){radians(0), radians(i++ * 0.5), radians(0), 1.0});
	glUniformMatrix4fv(ram->display.model_matrix_id, 1, GL_FALSE, (GLfloat *)ram->display.model_matrix);
}

void	loop(t_ram *ram)
{
	t_display *d;

	d = &(ram->display);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(d->program);

	update_camera(ram);
	update_matrices(ram);
	update_texture_slider(ram);
	update_uv_slider(ram);

	glBindVertexArray(d->vao);
	glDrawArrays(GL_TRIANGLES, 0, ram->model.triangles_count * sizeof(t_triangle));
	glBindVertexArray(0);

	glUseProgram(0);

	glfwSwapBuffers(d->window);
	glfwPollEvents();
}