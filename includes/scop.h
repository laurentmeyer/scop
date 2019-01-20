#ifndef SCOP_H
# define SCOP_H

# include <libc.h>
# include <math.h>

typedef struct		s_ram t_ram;

# include "display.h"

struct				s_ram
{
	t_display		display;
};

#endif