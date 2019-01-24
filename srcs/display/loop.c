#include "ram.h"
#include "display.h"
#include "geometry.h"
#include "utils.h"
#include "scop.h"


void	update_camera(t_ram *ram)
{
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_UP))
	{
		ram->display.camera_position.z -= 1.0;
		// printf("==proj==\n");
		// print_matrix(&ram->display.proj_matrix);
		// printf("==view==\n");
		// print_matrix(&ram->display.view_matrix);
		// printf("==model==\n");
		// print_matrix(&ram->display.model_matrix);
	}
	if (GLFW_PRESS == glfwGetKey(ram->display.window, GLFW_KEY_DOWN))
	{
		ram->display.camera_position.z += 1.0;
		// printf("==proj==\n");
		// print_matrix(&ram->display.proj_matrix);
		// printf("==view==\n");
		// print_matrix(&ram->display.view_matrix);
		// printf("==model==\n");
		// print_matrix(&ram->display.model_matrix);
	}
}

void	update_matrices(t_ram *ram)
{
	static size_t i = 0;

	// identity_m4(&ram->display.proj_matrix);
	ortho(&ram->display.proj_matrix, ram);
	glUniformMatrix4fv(ram->display.proj_matrix_id, 1, GL_FALSE, (GLfloat *)ram->display.proj_matrix);

	identity_m4(&ram->display.view_matrix);
	// translate(&ram->display.view_matrix, &(t_v4){0.0, 0.0, -100.0, 1.0});
	translate(&ram->display.view_matrix, &ram->display.camera_position);
	// rotate(&ram->display.view_matrix, &ram->display.camera_direction);
	glUniformMatrix4fv(ram->display.view_matrix_id, 1, GL_FALSE, (GLfloat *)ram->display.view_matrix);

	identity_m4(&ram->display.model_matrix);
	rotate(&ram->display.model_matrix, &(t_v4){radians(0), radians(i * 0.5), radians(0), 1.0});
	glUniformMatrix4fv(ram->display.model_matrix_id, 1, GL_FALSE, (GLfloat *)ram->display.model_matrix);

	i++;
}

void	loop(t_ram *ram)
{
	t_display *d;

	d = &(ram->display);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(d->program);
	update_camera(ram);
	update_matrices(ram);
	glBindVertexArray(d->vao);
	glDrawArrays(GL_TRIANGLES, 0, ram->model.triangles_count * sizeof(t_triangle));
	glBindVertexArray(0);

	glUseProgram(0);

	glfwSwapBuffers(d->window);
	glfwPollEvents();
}