#include "display.h"
#include "alloc.h"

void	init_display(t_ram *ram)
{
	if (!glfwInit())
		exit_message(ram, EXIT_FAILURE, "Could not init GLFW\n");
	glfwSetErrorCallback(error_callback);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	ram->display.window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!ram->display.window)
	{
		// Window or OpenGL context creation failed
	}
	glfwMakeContextCurrent(ram->display.window); // sauf si on veut utiliser une loading library type glad
	glfwSetKeyCallback(ram->display.window, key_callback);
	printf("%s\n", glGetString(GL_VERSION)); //connaitre la version d'OpenGL utilisée
}

void	destroy_display(t_display *display)
{
	glfwDestroyWindow(display->window);
	glfwTerminate();
}