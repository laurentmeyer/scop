/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ram.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:21:53 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:21:54 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "alloc.h"

void		init_ram(t_ram *ram, char *objpath)
{
	bzero(ram, sizeof(t_ram));
	init_parser(ram, objpath);
	init_model(ram);
	init_display(ram);
}

void		destroy_ram(t_ram *ram)
{
	destroy_display(&(ram->display));
	destroy_model(&(ram->model));
	destroy_parser(&(ram->parser));
}
