/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:32:44 by nesdebie          #+#    #+#             */
/*   Updated: 2023/03/01 11:35:11 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_stdin_to_str(int fd)
{
	char	buffer[BUFFER_MAX];
	int		length;
	char	*str;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = 0;
	length = 1;
	while (length > 0)
	{
		length = read(fd, buffer, BUFFER_MAX);
		if (length > 0)
			str = ft_strdupncat(str, buffer, length);
	}
	return (str);
}

t_map	*ft_stdin_to_map(void)
{
	t_map	*map;
	char	*str_map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	str_map = ft_stdin_to_str(0);
	if (ft_first_line(str_map, map)
		&& ft_check_map(str_map, map, 0) == map->nb_lines)
		map->arr = ft_array(str_map, map->full, map->empty);
	else
	{
		free(str_map);
		free(map);
		return (0);
	}
	return (map);
}

void	ft_stdin(void)
{
	t_map	*map;

	map = ft_stdin_to_map();
	if (!map)
		write(2, "map error\n", 10);
	else
	{
		ft_solve(map);
		ft_free(map);
	}
}
