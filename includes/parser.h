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
	unsigned char	bmp_header[54];
	unsigned int	bmp_pos;
	unsigned int	bmp_w;
	unsigned int	bmp_h;
	unsigned int	bmp_size;
}					t_parser;

#endif