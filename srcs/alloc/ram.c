#include "scop.h"
#include "alloc.h"

void		init_ram(t_ram *ram, char *objpath)
{
	bzero(ram, sizeof(t_ram));

	init_parser(ram, objpath);
	init_model(ram);
	init_display(ram);
}

void		destroy_ram(t_ram *ram)
{
	destroy_display(&(ram->display));
	destroy_model(&(ram->model));
	destroy_parser(&(ram->parser));
}