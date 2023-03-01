/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:59:58 by nesdebie          #+#    #+#             */
/*   Updated: 2023/03/01 11:35:41 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_free(t_map *map)
{
	int	i;

	i = map->nb_lines - 1;
	while (i >= 0)
	{
		if (map->arr[i])
			free(map->arr[i]);
		i--;
	}
	if (map->arr)
		free(map->arr);
	free(map);
}

int	main(int ac, char **av)
{
	int		i;
	t_map	*map;

	i = 1;
	while (i < ac)
	{
		map = ft_map(av[i]);
		if (map)
		{
			ft_solve(map);
			ft_free(map);
		}
		else
			write(1, "map error\n", 10);
		if (i < ac - 1)
			write(1, "\n", 1);
		i++;
	}
	if (ac == 1)
		ft_stdin();
	system("leaks bsq");
	return (0);
}
