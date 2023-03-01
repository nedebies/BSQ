/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:40:43 by nesdebie          #+#    #+#             */
/*   Updated: 2023/03/01 16:02:59 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_simple_atoi(char *str, int i)
{
	int	res;
	int	cpt;
	int	tmp;

	tmp = i;
	res = 0;
	i = 0;
	cpt = 0;
	while (str[i] >= 48 && str[i] <= 57 && i < tmp)
	{
		res = res * 10 + str[i] - 48;
		if (++cpt > 19)
			return (0);
		i++;
	}
	return (res);
}

char	*ft_strdupncat(char *old, char *src, int n)
{
	int			i;
	int			size;
	char		*new;

	new = malloc((ft_strlen(old) + n + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (old[++i])
		new[i] = old[i];
	new[i] = 0;
	size = ft_strlen(old);
	i = 0;
	while (src[i] && i < n)
	{
		new[size + i] = src[i];
		i++;
	}
	new[size + i] = 0;
	free(old);
	return (new);
}
