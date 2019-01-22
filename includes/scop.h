#ifndef SCOP_H
# define SCOP_H

# include <libc.h>
# include <math.h>
# include "ram.h"
# include "display.h"

# define WIN_H		480
# define WIN_W		640
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
char	*parse_shader(t_ram *ram, char const *path);

#endif