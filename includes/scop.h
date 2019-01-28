#ifndef SCOP_H
# define SCOP_H

# include <libc.h>
# include <math.h>
# include "ram.h"
# include "display.h"
# include "parser.h"
# include "geometry.h"

# define WIN_H		768
# define WIN_W		1024
# define WIN_NAME	"scop"


void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void	error_callback(int error, const char* description);
void	loop(t_ram *ram);
void 	init_program(t_ram *ram);
void	init_vertices(t_ram *ram);
void 	init_shaders(t_ram *ram);
void	init_window(t_ram *ram);
void 	init_context(t_ram *ram);
void	init_callbacks(t_ram *ram);
void	init_matrices(t_ram *ram);
void 	init_texture(t_ram *ram, const char *path);
char	*parse_shader(t_ram *ram, char const *path);
unsigned char	*parse_bmp(t_ram *ram, const char *imagepath);
void	count_elements(t_ram *ram);
void	fill_vertices(t_ram *ram);
void	center_object(t_ram *ram);
void	fill_triangles(t_ram *ram);
void	fill_uvs(t_ram *ram);
void	fill_elements(t_ram *ram);
void	ortho(t_m4 *out, t_ram *ram); // a mettre dans le bon header

#endif