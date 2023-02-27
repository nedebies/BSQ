/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:59:58 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/27 23:28:59 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int ft_free(t_map *map, int i)
{
    int j;

    j = 0;
    if (i == -1)
    {
        while (map->array[j])
            j++;
        i = j;
    }
    while (i >= 0)
    {
        free (map->array[i]);
        i--;
    }
    free(map->array);
    free(map);
    return (0);
}

int main(int ac, char **av)
{
    int i;
    t_map   *map;

    i = 1;
    while (i < ac)
    {
        if (!ft_check_map(av[i], &map))
            write (1, "Error\n", 6);
        else
        {
            //solve
            ft_print_map(map);
            ft_free(map, -1);
        }
    }
    if (ac == 1)
    {
        write (1, "todo\n", 5);
        //check
        //malloc
        //solve
        //print
        //free
    }
    return (0);
}