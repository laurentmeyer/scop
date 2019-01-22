#include "scop.h"
#include "alloc.h"

void		init_ram(t_ram *ram)
{
	bzero(ram, sizeof(t_ram));
	init_display(ram);
	init_model(ram);
}

void		destroy_ram(t_ram *ram)
{
	destroy_model(&(ram->model));
	destroy_display(&(ram->display));
}