/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:06:08 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/27 23:36:51 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static char	*ft_addchar(char *str, char *buf)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i])
		i++;
	new = malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = buf[0];
	new[i + 1] = 0;
	free(str);
	return (new);
}

static int  ft_only_valid_char(t_map *m, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != m->empty || str[i] != m->full || str[i] != m->wall)
            return (0);
        i++;
    }
    return (1);
}

static int  ft_check_lines(t_map *m)
{
    int i;

    i = 0;
    while (m->array[i])
    {
        if (!ft_only_valid_char(m, m->array[i]))
            return (0);
        if (i > 0 && ft_strlen(m->array[i]) != ft_strlen(m->array[i - 1]))
            return (0);
        i++;
    }
    return (1);
}

static int  ft_set_map(int fd, t_map **map, char *buf, char *str)
{
    t_map           *m;
    unsigned int    i;

    i = 0;
    m = malloc(sizeof(t_map));
    if (!m)
        return (0);
    m->nb_line = ft_atoi(str, &i);
    m->empty = str[i++] - '0';
    m->wall = str[i++] - '0';
    m->full = str[i] - '0';
    i = 0;
    free (str);
    m->array = malloc(sizeof(char *) * m->nb_line + 1);
    if (!m->array)
    {
        free (m);
        return (0);
    }
    while ((read(fd, buf, 1)) != 0 && i < m->nb_line)
	{
		if (buf[0] != '\n')
		{
			str = ft_addchar(str, buf);
			if (!str && i > 0)
				return (ft_free(m, --i));
            else if (!str && i == 0)
                return (ft_free(m, - 1));
		}
		else
		{
            m->array[i] = ft_strdup(str);
            if (!m->array[i])
            {
                free (str);
                return (ft_free(m, --i));
            }
            i++;
			free(str);
			str = malloc(sizeof(char));
			str[0] = 0;
		}
	}
    if (i != m->nb_line)
    {
        free (str);
        return (ft_free(m, i));
    }
    if (!ft_check_lines(m))
    {
        free (str);
        return (ft_free(m, i));
    }
    m->array[i] = 0;
    *map = m;
    free(str);
    return (1);
}

static int ft_check_params(char *str)
{
    unsigned int i;
    unsigned int j;

    i = 0;
    j = 0;
    if (ft_atoi(str, &i) == 0)
        return (0);
    while (str[i + j])
    {
        if (str[i + j] < 32 || str[i + j] == 127)
            return (0);
        j++;
    }
    if (j != 3)
        return (0);
    return (1);
}

static int  ft_buffer(int fd, t_map **map)
{
    char    buf[1];
    char    *str;

    str = malloc(sizeof(char));
    if (!str)
        return (0);
    str[0] = 0;
    while ((read(fd, buf, 1)) != 0 && buf[0] != '\n')
	{
		str = ft_addchar(str, buf);
		if (!str)
			return (0);
	}
    if (!ft_strlen(str) || !ft_check_params(str))
    {
        free(str);
        return (0);
    }
    if (!ft_set_map(fd, map, str, buf))
    {
        free(str);
        return (0);
    }
    free (str);
    return (1);
}

int ft_check_map(char *path, t_map **map)
{
    int fd;

    fd = open(path, O_RDWR);
    if (fd != -1)
        if (ft_buffer(fd, map))
            return (1);
    return (0);
}