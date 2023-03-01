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

static int	ft_minimum(int a, int b, int c)
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
			if (map->array[j][i] == 1 && i > 0 && j > 0)
				map->array[j][i] = ft_minimum(map->array[j - 1][i], map->array[j][i - 1],
						map->array[j - 1][i - 1]) + 1;
			if (max < map->array[j][i])
			{
				max = map->array[j][i];
				max_pt.x = i;
				max_pt.y = j;
			}
		}
	}
	ft_print_map(map, max_pt, max);
}

/**
typedef struct s_point
{
	int		x;
	int		y;
	struct s_point	*next;
}	t_point;

t_point	*init_point(int x, int y, t_point next_point)
{
	t_point	*new_point;

	new_point = malloc(sizeof(new_point));
	if (!new_point)
	{
		free_obstacles(next_point);
		return (0);
	}
	new_point->x = x;
	new_point->y = y;
	new_point->next = next_point;
	return (new_point);
}**/
/**
t_point	*store_obstacles(char **map, char obstacle)
{
	int		i;
	int		j;
	t_point	*list_obstacles;

	list__obstacles = init_point(0, 0, list_obstacles);
	if (!list_obstacles)
		return (0);
	i = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == obstacle)
			{
				list_obstacles = init_point(i, j, list_obstacles);
				if (!list_obstacles)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (list_obstacles);
}

static int	check_possible_square(char **map, char obstacle, t_square *bsq)
{
	int	x;
	int	y;

	x = bsq->x_left;
	y = bsq->y_up;
	while (y < bsq->y_up + bsq->size)
	{
		while (x < bsq->x_left + bsq->size)
		{
			if (map[x][y] == obstacle)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

t_square	*find_square(char **map, char obstacle, int size_map)
{
	t_square	*bsq;

	bsq = malloc(sizeof(bsq));
	if (!bsq)
		return (0);
	bsq->size = size_map;
	while (bsq->size > 0)
	{
		bsq->x_left = 0;
		while (bsq->x_left < size_map - bsq->size)
		{
			bsq->y_up = 0;
			while (bsq->y_up < size_map - bsq->size)
			{
				if (check_possible_square(map, obstacle, bsq) == 0)
					return (bsq);
				bsq->y_up++;
			}
			bsq->x_left++;
		}
		bsq->size--;
	}
	return (0);
}**/
