/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:00:22 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/27 23:36:26 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h> // TO DEL

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
    char    **array;
    unsigned int     nb_line;
    char    wall;
    char    empty;
    char    full;
} t_map;

typedef struct s_square
{
	int	size;
	int	x_left;
	int	y_up;
}	t_square;

int ft_free(t_map *map, int i);

void    ft_print_map(t_map *map);
int ft_check_map(char *path, t_map **map);

char	*ft_strdup(char *str);
unsigned int	ft_strlen(char *str);
unsigned int	ft_atoi(char *str, unsigned int *i);
t_square	*find_square(char **map, char obstacle, int size_map);

#endif