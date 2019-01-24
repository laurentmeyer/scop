#include "ram.h"
#include "display.h"
#include "geometry.h"
#include "utils.h"
#include "scop.h"


void	update_matrices(t_ram *ram)
{
	static size_t i = 0;

	ortho(&ram->display.proj_matrix, ram);
	glUniformMatrix4fv(ram->display.proj_matrix_id, 1, GL_FALSE, (GLfloat *)ram->display.proj_matrix);
	// translate(&view_matrix, &(t_v4){0.0, 0.0, -1.0, 1.0});
	glUniformMatrix4fv(ram->display.viewMatID, 1, GL_FALSE, (GLfloat *)ram->display.view_matrix);
	identity_m4(&ram->display.model_matrix);
	rotate(&ram->display.model_matrix, &(t_v4){radians(0), radians(i * 0.5), radians(i * 1), 1.0});
	glUniformMatrix4fv(ram->display.modelMatID, 1, GL_FALSE, (GLfloat *)ram->display.model_matrix);
	i++;
}

void	loop(t_ram *ram)
{
	t_display *d;

	d = &(ram->display);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(d->program);
	update_matrices(ram);
	glBindVertexArray(d->vao);
	glDrawArrays(GL_TRIANGLES, 0, ram->model.triangles_count * sizeof(t_triangle));
	glBindVertexArray(0);

	glUseProgram(0);

	glfwSwapBuffers(d->window);
	glfwPollEvents();
}