#include "ram.h"
#include "display.h"
#include "geometry.h"

void	loop(t_ram *ram)
{
	t_display *d;
	t_m4	proj_matrix;


	d = &(ram->display);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ortho(&proj_matrix, ram);
	glUseProgram(d->program);
	glUniformMatrix4fv(d->pMatID, 1, GL_FALSE, (GLfloat *)proj_matrix);
	glBindVertexArray(d->vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	// glBindVertexArray(0);
	// glUseProgram(0);

	glfwSwapBuffers(d->window);
	glfwPollEvents();
}