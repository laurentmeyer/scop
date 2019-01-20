#ifndef DISPLAY_H
# define DISPLAY_H

# include <GLFW/glfw3.h>
# define WIN_H		480
# define WIN_W		640
# define WIN_NAME	"scop"

typedef struct		s_display
{
	GLFWwindow *window;
	GLuint vertex_buffer;
	GLuint vertex_shader;
	GLuint fragment_shader;
	GLuint program;
	GLint mvp_location;
	GLint vpos_location;
	GLint vcol_location;
} t_display;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void error_callback(int error, const char* description);

#endif
