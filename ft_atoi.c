/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:39:31 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/27 22:06:18 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static	int	ft_isovermaxmin(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

unsigned int	ft_atoi(char const *str, unsigned int *i)
{
	unsigned int	res;
	int				cpt;

	res = 0;
	i = 0;
	cpt = 0;
	while (ft_isdigit(str[*i]))
	{
		res = res * 10 + str[*i] - 48;
		if (++cpt > 19)
			return (0);
		i++;
	}
	return (res);
}