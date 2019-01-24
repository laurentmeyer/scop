#ifndef ALLOC_H
# define ALLOC_H

# include "scop.h"

void		exit_message(t_ram *ram, int exit_code, char *message);
void		init_ram(t_ram *ram, char *objpath);
void		destroy_ram(t_ram *ram);
void		init_display(t_ram *ram);
void		destroy_display(t_display *display);
void		init_model(t_ram *ram);
void		destroy_model(t_model *model);
void 		init_parser(t_ram *ram, char *objpath);
void 		destroy_parser(t_parser *parser);

#endif