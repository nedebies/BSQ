/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:00:22 by nesdebie          #+#    #+#             */
/*   Updated: 2023/03/01 08:00:16 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct s_map
{
    int    **array;
    int     nb_lines;
    int     length;
    char    wall;
    char    empty;
    char    full;
} t_map;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

char	*process_file(int fd, int fileSize);
char	*ft_stdin_to_str(int fd);
int		ft_first_line(char *str_map, t_map *map);
t_map	*ft_map(char *file);
void	ft_print_map(t_map *map, t_point p, int max);
int		**ft_array(char *str, char obst, char empty);
void	ft_solve(t_map *map);
int		ft_get_line_length(char *str);
int		ft_check_map(char *str_map, t_map *map);

int		ft_simple_atoi(char *str, int n);
int		**ft_splint(char *str, char *charset, char chrs[2]);
char	*ft_strdupncat(char *old, char *src, int n);
int		ft_strlen(char *str);
void	ft_putchar(char c);

/**
typedef struct s_square
{
	int	size;
	int	x_left;
	int	y_up;
}	t_square;

int ft_free(t_map *map, int i);

void    ft_print_map(t_map *map);
int ft_check_map(char *path, t_map **map);


unsigned int	ft_strlen(char *str);
unsigned int	ft_simple_atoi(char *str, unsigned int *i);
t_square	*find_square(char **map, char obstacle, int size_map);
**/
#endif