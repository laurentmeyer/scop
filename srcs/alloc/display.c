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
	ram->display.zfar = 100.;
	ram->display.znear = .1;
	identity_m4(&ram->display.view_matrix);
	identity_m4(&ram->display.model_matrix);
	identity_m4(&ram->display.proj_matrix);
	glfwGetFramebufferSize(ram->display.window, &(ram->display.width), &(ram->display.height));
}

void destroy_display(t_display *display)
{
	glfwDestroyWindow(display->window);
	glfwTerminate();
}