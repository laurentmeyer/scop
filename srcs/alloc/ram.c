#include "scop.h"
#include "alloc.h"

void		init_ram(t_ram *ram)
{
	bzero(ram, sizeof(t_ram));
	init_display(ram);
}

void		destroy_ram(t_ram *ram)
{
	destroy_display(&(ram->display));
}