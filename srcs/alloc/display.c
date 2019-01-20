#include "display.h"
#include "alloc.h"

static void	set_context_and_window(t_ram *ram)
{
	t_display	*d;
	
	d = &(ram->display);
	if (!glfwInit())
		exit_message(ram, EXIT_FAILURE, "Could not init GLFW");
	// glfwSetErrorCallback(error_callback);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	d->window = glfwCreateWindow(640, 480, "Scop", NULL, NULL);
	if (!d->window)
		exit_message(ram, EXIT_FAILURE, "Could not init window");
	glfwMakeContextCurrent(d->window);

	glewExperimental = GL_TRUE;
	glewInit();

	glfwSetKeyCallback(ram->display.window, key_callback);
	// glfwSwapInterval(1);
	printf("Renderer: %s\n", glGetString(GL_RENDERER)); //connaitre la version d'OpenGL utilisée
	printf("Version: %s\n", glGetString(GL_VERSION));   //connaitre la version d'OpenGL utilisée

	// tell GL to only draw onto a pixel if the shape is closer to the viewer
	glEnable(GL_DEPTH_TEST);							// enable depth-testing
	glDepthFunc(GL_LESS);								// depth-testing interprets a smaller value as "closer"
	printf("%s\n", "[display.c] Need to check OpenGL errors");
}

void init_display(t_ram *ram)
{
	bzero(&(ram->display), sizeof(t_display));
	set_context_and_window(ram);
	set_buffers_shaders_and_program(ram);
}

void destroy_display(t_display *display)
{
	glfwDestroyWindow(display->window);
	glfwTerminate();
}