#ifndef MODEL_H
# define MODEL_H

# include <GL/glew.h>
# include <GLFW/glfw3.h>

typedef struct		s_v3
{
	GLint			x;
	GLint			y;
	GLint			z;
}					t_v3;

typedef struct		s_vertexData
{
	t_v3			pos;
	t_v3			color;
}					t_vertexData;

typedef struct		s_model
{
	t_vertexData	*vertices;
	size_t			vertices_count;
}					t_model;



#endif