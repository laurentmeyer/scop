/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:21:25 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:21:26 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "alloc.h"

void	exit_message(t_ram *ram, int exit_code, char *message)
{
	if (NULL != message)
		fprintf(stderr, "%s\n", message);
	if (NULL != ram)
		destroy_ram(ram);
	exit(exit_code);
}
