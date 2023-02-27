/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:30:54 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/27 23:37:48 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strdup(char *str)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!s)
		return (0);
	else
	{
		while (str[i])
		{
			s[i] = str[i];
			i++;
		}
		s[i] = 0;
		return (s);
	}
}