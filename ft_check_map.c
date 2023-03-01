/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:40:19 by nesdebie          #+#    #+#             */
/*   Updated: 2023/03/01 15:15:23 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_map(char *str_map, t_map *map)
{
	int	i;
	int	char_count;
	int	line_count;

	i = 0;
	line_count = 0;
	while (str_map[i] != '\n')
		i++;
	while (str_map[++i])
	{
		char_count = 0;
		while (str_map[i] != '\n')
		{
			if (str_map[i] != map->wall && str_map[i] != map->empty)
				return (0);
			char_count++;
			i++;
		}
		if (char_count != map->length)
			return (0);
		line_count++;
	}
	return (line_count);
}

int	ft_first_line(char *str_map, t_map *map)
{
	int	i;

	i = 0;
	while (str_map[i] && str_map[i] != '\n')
	{
		if (str_map[i] < 32 || str_map[i] == 127)
			return (0);
		i++;
	}
	if (i < 4)
		return (0);
	map->full = str_map[i - 1];
	map->wall = str_map[i - 2];
	map->empty = str_map[i - 3];
	map->nb_lines = ft_simple_atoi(str_map, (i - 3));
	if (map->nb_lines <= 0 || map->wall == map->empty || map->wall == map->full
		|| map->full == map->empty)
		return (0);
	map->length = ft_linelen(str_map + i + 1);
	return (1);
}
