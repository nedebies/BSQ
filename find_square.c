/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdegryse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:06:06 by kdegryse          #+#    #+#             */
/*   Updated: 2023/02/28 19:06:10 by kdegryse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
}**/

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

static int	min_max(int *max_size_line)
{
	int	max;
	int	i;
	int	count;

	i = 0;
	max = 0;
	while (max_size_line[i])
		if (max_size_line[i] > max)
			max = max_size_line[i];
	while (count < max)
	{
		count = 0;
		i = 0;
		while (max_size_line[i])
		{
			if (max_size_line[i] > max)
				count++;
			i++;
		}
		if (count < max)
			max--;
	}
	return (max);
}

static int	*count_max_line(int *max_size, char **map, char obstacle, int i)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	max_size[i] = 0;
	while (map[i][j])
	{
		if (map[i][j] == obstacle)
		{
			if (count > max_size[i])
				max_size[i] = count;
			count = 0;
		}
		else
			count++;
		j++;
	}
	return (max_size);
}

static int	max_possible_square(char **map, char obstacle)
{
	int	*max_size_line;
	int	i;
	int	max_size;

	i = 0;
	while (map[i])
		i++;
	max_size_line = malloc(sizeof(int) * i);
	while (map[i])
	{
		max_size_line = count_max_line(max_size_line, map, obstacle, i);
		i--;
	}
	max_size = min_max(max_size_line);
	free(max_size_line);
	return (max_size);
}

t_square	*find_square(char **map, char obstacle, int size_map)
{
	t_square	*bsq;

	bsq = malloc(sizeof(bsq));
	if (!bsq)
		return (0);
	bsq->size = max_possible_square(map, obstacle);
	while (bsq->size > 0)
	{
		bsq->y_up = 0;
		while (bsq->y_up < size_map - bsq->size)
		{
			bsq->x_left = 0;
			while (bsq->x_left < size_map - bsq->size)
			{
				if (check_possible_square(map, obstacle, bsq) == 0)
					return (bsq);
				bsq->x_left++;
			}
			bsq->y_up++;
		}
		bsq->size--;
	}
	return (0);
}
