#ifndef PARSER_H
# define PARSER_H

# include <libc.h>

typedef struct		s_parser
{
	char			*obj_path;
	char			*line;
	char			**split;
	int				*ints;
	size_t			ints_count;
}					t_parser;

#endif