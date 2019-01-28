/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:01:02 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 16:01:25 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "ram.h"
#include "model.h"
#include "alloc.h"
#include "utils.h"
#include "libft.h"

void	count_elements(t_ram *ram)
{
	char	*line;
	FILE	*f;
	int		read;
	size_t	len;
	size_t	w;

	if (NULL == (f = fopen(ram->parser.obj_path, "rb")))
		exit_message(ram, EXIT_FAILURE, "Invalid obj file path");
	len = 0;
	line = NULL;
	while (-1 != (read = getline(&line, &len, f)))
	{
		if ((w = ft_countwords(line, ' ')) < 4)
			continue ;
		if (first_word_is(line, "v"))
			ram->model.vertices_count += w - 3;
		else if (first_word_is(line, "f"))
			ram->model.triangles_count += w - 3;
	}
	if (NULL != line)
		free(line);
	fclose(f);
}
