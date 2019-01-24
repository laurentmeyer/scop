#ifndef RAM_H
# define RAM_H

# include "display.h"
# include "model.h"
# include "parser.h"

typedef struct		s_ram
{
	t_display		display;
	t_model			model;
	t_parser		parser;
}					t_ram;

#endif