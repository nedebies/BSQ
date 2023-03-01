/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:06:06 by kdegryse          #+#    #+#             */
/*   Updated: 2023/03/01 07:58:15 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	ft_min(int a, int b, int c)
{
	if (a <= c && a <= b)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

void	ft_solve(t_map *map)
{
	int		i;
	int		j;
	int		max;
	t_point	max_pt;

	j = -1;
	max = -1;
	while (++j < map->nb_lines)
	{
		i = -1;
		while (++i < map->length)
		{
			if (map->arr[j][i] == 1 && i > 0 && j > 0)
				map->arr[j][i] = ft_min(map->arr[j - 1][i], map->arr[j][i - 1],
						map->arr[j - 1][i - 1]) + 1;
			if (max < map->arr[j][i])
			{
				max = map->arr[j][i];
				max_pt.x = i;
				max_pt.y = j;
			}
		}
	}
	ft_print_map(map, max_pt, max, 0);
}
