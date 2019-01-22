#include "display.h"
#include "alloc.h"
# include <GL/glew.h>
# include <GLFW/glfw3.h>

void init_window(t_ram *ram)
{
	t_display *d;

	d = &(ram->display);
	if (!glfwInit())
		exit_message(ram, EXIT_FAILURE, "Could not init GLFW");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	d->window = glfwCreateWindow(WIN_W, WIN_H, WIN_NAME, NULL, NULL);
	if (!d->window)
		exit_message(ram, EXIT_FAILURE, "Could not init window");
}

void init_context(t_ram *ram)
{
	glfwMakeContextCurrent(ram->display.window);
	glewExperimental = GL_TRUE;
	glewInit();
	// glfwSwapInterval(1);
	// tell GL to only draw onto a pixel if the shape is closer to the viewer
	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS);	// depth-testing interprets a smaller value as "closer"
}