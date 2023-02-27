/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:21:02 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/27 23:28:46 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void    ft_print_map(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->array[i])
    {
        j = 0;
        while (map->array[i][j])
        {
            write(1, &map->array[i][j], 1);
            j++;
        }
        write (1, "\n", 1);
        i++;
    }
    write (1, "\n", 1);
}