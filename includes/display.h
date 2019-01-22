#ifndef DISPLAY_H
# define DISPLAY_H

# include <GL/glew.h>
# include <GLFW/glfw3.h>

typedef struct		s_display
{
	GLFWwindow *window;
	GLfloat vertexData[18];
	int	width;
	int	height;
	float	znear;
	float	zfar;
	GLuint vertex_buffer;
	GLuint vertex_shader;
	GLuint fragment_shader;
	GLuint program;
	GLuint vbo;
	GLuint vao;
	GLint pMatID;
} 					t_display;

#endif
