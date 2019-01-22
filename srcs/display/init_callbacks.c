#include "display.h"
#include "ram.h"
#include <libc.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)action;
	(void)mods;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s code %d\n", description, error);
}

void	init_callbacks(t_ram *ram)
{
	// set resize callback
	glfwSetErrorCallback(error_callback);
	glfwSetKeyCallback(ram->display.window, key_callback);
}