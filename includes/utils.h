/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:17:57 by lmeyer            #+#    #+#             */
/*   Updated: 2019/01/28 15:18:10 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <libc.h>

int		first_word_is(char *s, char *word);
float	radians(float degrees);
float	minf(float a, float b);
float	maxf(float a, float b);
float	percentage_f(float min, float max, float f);

#endif
