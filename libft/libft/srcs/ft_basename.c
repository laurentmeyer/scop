/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:35:36 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/14 14:41:42 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_basename(char *path)
{
	int		i;

	if (!path || !*path)
		return (".");
	i = 0;
	while (path[++i])
		;
	while (path[--i] == '/')
		if (i == 0)
			return ("/");
	while (path[i] != '/' && i >= 0)
		--i;
	return (path + i + 1);
}
