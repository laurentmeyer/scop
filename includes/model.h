/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:14:20 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:14:22 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H

# include <GL/glew.h>
# include <GLFW/glfw3.h>

typedef struct		s_v2
{
	GLfloat			x;
	GLfloat			y;
}					t_v2;

typedef struct		s_v3
{
	GLfloat			x;
	GLfloat			y;
	GLfloat			z;
}					t_v3;

typedef struct		s_vertex
{
	t_v3			pos;
	t_v2			tcoord_sph;
	t_v2			tcoord_tri;
}					t_vertex;

typedef t_vertex	t_triangle[3];

typedef struct		s_model
{
	t_vertex		*vertices;
	size_t			vertices_count;
	t_triangle		*triangles;
	size_t			triangles_count;
}					t_model;

#endif
