#include <libc.h>
#include <math.h>
#include "ram.h"
#include "model.h"
#include "alloc.h"
#include "utils.h"
#include "libft.h"

void	extract_int_params(t_ram *ram)
{
	size_t	i;

	i = ft_countwords(ram->parser.line, ' ') - 1;
	if (NULL == (ram->parser.ints = (int *)malloc(sizeof(int) * i))
		|| NULL == (ram->parser.split = ft_strsplit(ram->parser.line, ' ')))
		exit_message(ram, EXIT_FAILURE, "Memalloc failed to read ints");
	ram->parser.ints_count = i;
	i = 0;
	while (i < ram->parser.ints_count)
	{
		if (1 != sscanf(ram->parser.split[i + 1], "%d", ram->parser.ints + i))
		{
			fprintf(stderr, "Error parsing face: ");
			exit_message(ram, EXIT_FAILURE, ram->parser.line);
		}
		++i;
	}
	ft_free_strsplit(&(ram->parser.split));
	ram->parser.split = NULL;
}

void	fill_face(t_ram *ram)
{
	static size_t	pos = 0;
	t_triangle		*t;
	size_t			i;

	extract_int_params(ram);
	i = ram->parser.ints_count;
	while (i-- > 0)
		if (ram->parser.ints[i] < 1
			|| (size_t)ram->parser.ints[i] > ram->model.vertices_count)
			exit_message(ram, EXIT_FAILURE, "Out of bound vertex");
	i = 2;
	while (i <  ram->parser.ints_count)
	{
		t = ram->model.triangles + pos++;
		(*t)[0] = *(ram->model.vertices + ram->parser.ints[0] - 1);
		(*t)[1] = *(ram->model.vertices + ram->parser.ints[i - 1] - 1);
		(*t)[2] = *(ram->model.vertices + ram->parser.ints[i] - 1);
		i++;
	}
	free(ram->parser.ints);
	ram->parser.ints = NULL;
}

void fill_triangles(t_ram *ram)
{
	int f;
	int read;

	if (-1 == (f = open(ram->parser.obj_path, O_RDONLY)))
		exit_message(ram, EXIT_FAILURE, "Invalid shader program path");
	while (0 != (read = gnlite(f, &(ram->parser.line))))
	{
		if (-1 == read)
			exit_message(ram, EXIT_FAILURE, "Error reading obj file");
		if (ft_countwords(ram->parser.line, ' ') >= 4
			&& first_word_is(ram->parser.line, "f"))
			fill_face(ram);
		free(ram->parser.line);
		ram->parser.line = NULL;
	}
	free(ram->parser.line);
	ram->parser.line = NULL;
	close(f);
}