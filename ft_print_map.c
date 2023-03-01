/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:21:02 by nesdebie          #+#    #+#             */
/*   Updated: 2023/03/01 07:48:32 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	ft_print_no_square(t_map *map, int x, int y)
{
	if (map->arr[y][x] == 0)
		ft_putchar(map->wall);
	else
		ft_putchar(map->empty);
}

void	ft_print_map(t_map *map, t_point p, int max)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->nb_lines)
	{
		x = -1;
		while (++x < map->length)
		{
			if ((x < p.x - (max - 1) || x > p.x) || (y < p.y - (max - 1)
					|| y > p.y))
				ft_print_no_square(map, x, y);
			else
				ft_putchar(map->full);
		}
		ft_putchar('\n');
	}
}
