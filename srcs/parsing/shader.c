/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:04:17 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 16:05:04 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "ram.h"
#include "alloc.h"

char	*parse_shader(t_ram *ram, char const *path)
{
	char	*string;
	FILE	*f;
	long	fsize;

	if (NULL == (f = fopen(path, "rb")))
		exit_message(ram, EXIT_FAILURE, "Invalid shader program path");
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	if (NULL == (string = (char *)malloc(fsize + 1)))
		exit_message(ram, EXIT_FAILURE,
				"Could not allocate space for shader programs");
	fread(string, fsize, 1, f);
	fclose(f);
	string[fsize] = 0;
	return (string);
}
