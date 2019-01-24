#ifndef DISPLAY_H
# define DISPLAY_H

# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include "geometry.h"

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
	GLint proj_matrix_id;
	GLint viewMatID;
	GLint modelMatID;
	t_m4	proj_matrix;
	t_m4	view_matrix;
	t_m4	model_matrix;
} 					t_display;

#endif
