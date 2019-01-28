#ifndef DISPLAY_H
# define DISPLAY_H

# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include "geometry.h"

# define KEY_UP     1UL << 0
# define KEY_DOWN   1UL << 1
# define KEY_LEFT   1UL << 2
# define KEY_RIGHT  1UL << 3

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
	GLuint texture_id;
	GLint proj_matrix_id;
	GLint view_matrix_id;
	GLint model_matrix_id;
	GLint tex_slider_id;
	GLint uv_slider_id;
	t_m4	proj_matrix;
	t_m4	view_matrix;
	t_m4	model_matrix;
	t_v4	camera_position;
	t_v4	camera_rotation;
} 					t_display;

#endif
