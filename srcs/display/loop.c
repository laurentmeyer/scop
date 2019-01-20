#include "display.h"

void	loop(t_ram *ram)
{
	t_display *d;

	d = &(ram->display);
	// glfwGetFramebufferSize(d->window, &(d->viewport_x), &(d->viewport_y));
	// glViewport(0, 0, d->viewport_x, d->viewport_y);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(ram->display.program);
	glBindVertexArray(ram->display.vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	// glBindVertexArray(0);
	// glUseProgram(0);
	glfwSwapBuffers(ram->display.window);
	glfwPollEvents();
}