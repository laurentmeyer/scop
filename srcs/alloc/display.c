#include "display.h"
#include "alloc.h"

void init_display(t_ram *ram)
{
	bzero(&(ram->display), sizeof(t_display));
	init_window(ram);
	init_context(ram);
	init_program(ram);
	init_buffers(ram);
	init_callbacks(ram);
	ram->display.zfar = 100.;
	ram->display.znear = .1;
	glfwGetFramebufferSize(ram->display.window, &(ram->display.width), &(ram->display.height));
}

void destroy_display(t_display *display)
{
	glfwDestroyWindow(display->window);
	glfwTerminate();
}