/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:00:22 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/27 22:48:17 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
    char    **array;
    int     nb_line;
    char    wall;
    char    empty;
    char    full;
} t_map;

int ft_free(t_map *map, int i);

int ft_check_map(char *path, t_map **map);

unsigned int	ft_strlen(char *str);
unsigned int	ft_atoi(char const *str, unsigned int *i);

#endif