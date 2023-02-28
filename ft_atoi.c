/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:39:31 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/27 23:37:12 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

unsigned int	ft_atoi(char *str, unsigned int *i)
{
	unsigned int	res;
	int				cpt;

	res = 0;
	*i = 0;
	cpt = 0;
	write(1, "z\n", 2);
	while (ft_isdigit(str[*i]) == 1)
	{
		res = res * 10 + str[*i] - 48;
		if (++cpt > 19)
			return (0);
		*i = *i + 1;
	}
	write(1, "y\n", 2);
	return (res);
}