#ifndef DISPLAY_H
# define DISPLAY_H

# include <GL/glew.h>
# include <GLFW/glfw3.h>

typedef struct		s_display
{
	GLFWwindow *window;
	GLfloat vertices[9];
	int viewport_x;
	int viewport_y;
	GLuint vertex_buffer;
	GLuint vertex_shader;
	GLuint fragment_shader;
	GLuint program;
	GLuint vbo;
	GLuint vao;
	// GLint mvp_location;
	// GLint vpos_location;
	// GLint vcol_location;
} 					t_display;

# include "scop.h"
# define WIN_H		480
# define WIN_W		640
# define WIN_NAME	"scop"


void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void	error_callback(int error, const char* description);
void	set_buffers_shaders_and_program(t_ram *ram);
void	loop(t_ram *ram);

#endif
