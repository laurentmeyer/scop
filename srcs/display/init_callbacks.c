/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_callbacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:26:29 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:47:40 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "ram.h"
#include <libc.h>

void	error_callback(int error, const char *description)
{
	fprintf(stderr, "Error: %s code %d\n", description, error);
}

void	init_callbacks(t_ram *ram)
{
	(void)ram;
	glfwSetErrorCallback(error_callback);
}
