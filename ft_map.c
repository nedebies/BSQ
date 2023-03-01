/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:06:08 by nesdebie          #+#    #+#             */
/*   Updated: 2023/03/01 08:09:40 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**ft_array(char *str, char obst, char empty)
{
	int		i;
	int		**mtx;
	char	chrs[2];

	chrs[0] = obst;
	chrs[1] = empty;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	mtx = ft_splint(str + i, "\n", chrs);
	if (!mtx)
		return (NULL);
	return (mtx);
}

int	ft_check_map(char *str_map, t_map *map)
{
	int	i;
	int	char_count;
	int	line_count;

	i = 0;
	line_count = 0;
	while (str_map[i] != '\n')
		i++;
	i++;
	while (str_map[i])
	{
		char_count = 0;
		while (str_map[i] != '\n')
		{
			if (str_map[i] != map->wall && str_map[i] !=map->empty)
            	return (0);
			char_count++;
			i++;
		}
		if (char_count != map->length)
			return (0);
		line_count++;
		i++;
	}
	return (line_count);
}

char	*process_file(int fd, int size)
{
	int		length;
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	length = 1;
	while (length > 0)
	{
		length = read(fd, str + i, 1024);
		i += length;
	}
	*(str + i) = 0;
	return (str);
}

int	ft_linelen(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

int	ft_first_line(char *str_map, t_map *map)
{
	int	i;

	i = 0;
	while (str_map[i] && str_map[i] != '\n')
		i++;
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

int	ft_get_map_size(int *fd, char *filepath)
{
	int		read_size;
	int		len;
	char	c;

	c = 1;
	len = 0;
	read_size = 1;
	while (read_size)
	{
		read_size = read(*fd, &c, 1);
		len += read_size;
	}
	close(*fd);
	*fd = open(filepath, O_RDONLY);
	if (*fd < 0)
		return (-1);
	return (len);
}

/**cas d'une map full obstacle à gérer**/
t_map	*ft_map(char *read_size)
{
	t_map	*map;
	char	*str_map;
	int		fd;

	fd = open(read_size, O_RDONLY);
	if (fd < 0)
		return (0);
	else
	{
		map = malloc(sizeof(t_map));
		if (!map)
			return (NULL);
		str_map = process_file(fd, ft_get_map_size(&fd, read_size));
		if (ft_first_line(str_map, map)
			   	 && ft_check_map(str_map, map) == map->nb_lines)
			map->array = ft_array(str_map, map->wall, map->empty);
		else
		{
			free(str_map);
			return (0);
		}
	}
	close(fd);
	return (map);
}