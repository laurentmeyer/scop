#include "display.h"
#include "alloc.h"

void init_display(t_ram *ram)
{
	bzero(&(ram->display), sizeof(t_display));
	init_window(ram);
	init_context(ram);
	init_program(ram);
	init_vertices(ram);
	init_callbacks(ram);
	// init_texture(ram, "./textures/yellow.bmp");
	init_texture(ram, "./textures/nadine.bmp");
	ram->display.zfar = 100.;
	ram->display.znear = .1;
	ram->display.camera_position = (t_v4){0., 0., 0., 1.};
	ram->display.camera_rotation = (t_v4){0., 0., 0., 0.};
	glfwGetFramebufferSize(ram->display.window, &(ram->display.width), &(ram->display.height));

	glUseProgram(ram->display.program);
	ortho(&ram->display.proj_matrix, ram);
	glUniformMatrix4fv(ram->display.proj_matrix_id, 1, GL_FALSE, (GLfloat *)ram->display.proj_matrix);
	identity_m4(&ram->display.view_matrix);
	glUniformMatrix4fv(ram->display.view_matrix_id, 1, GL_FALSE, (GLfloat *)ram->display.view_matrix);
	identity_m4(&ram->display.model_matrix);
	glUniformMatrix4fv(ram->display.model_matrix_id, 1, GL_FALSE, (GLfloat *)ram->display.model_matrix);
	glUseProgram(0);
}

void destroy_display(t_display *display)
{
	glfwDestroyWindow(display->window);
	glfwTerminate();
}