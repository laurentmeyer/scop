/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:22:15 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:22:16 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "alloc.h"
#include "utils.h"
#include "libft.h"

void	init_parser(t_ram *ram, char *objpath)
{
	bzero(&(ram->parser), sizeof(t_parser));
	ram->parser.obj_path = objpath;
}

void	destroy_parser(t_parser *parser)
{
	if (NULL != parser->line)
	{
		free(parser->line);
		parser->line = NULL;
	}
	if (NULL != parser->split)
	{
		ft_free_strsplit(&(parser->split));
		parser->split = NULL;
	}
	if (NULL != parser->ints)
	{
		free(parser->ints);
		parser->ints = NULL;
	}
}
