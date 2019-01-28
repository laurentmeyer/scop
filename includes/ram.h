/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ram.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:14:54 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:14:55 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
