/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:52:24 by nesdebie          #+#    #+#             */
/*   Updated: 2023/03/01 08:00:58 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	char_is_in_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

static int	word_count(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (char_is_in_charset(str[i], charset))
			i++;
		if (!char_is_in_charset(str[i], charset) && str[i])
		{
			count++;
			while (!char_is_in_charset(str[i], charset) && str[i])
				i++;
		}
	}
	return (count);
}

static int	*get_next_tab(int *index, char *str, char *charset, char buf[2])
{
	int		len;
	int		*res;
	int		i;

	i = 0;
	len = 0;
	while (char_is_in_charset(str[*index], charset))
		(*index)++;
	while (!char_is_in_charset(str[*index + len], charset) && str[*index + len])
		len++;
	res = (int *)malloc((len) * sizeof(int));
	if (!res)
		return (NULL);
	while (i < len)
	{
		if (str[*index] == buf[0])
			res[i++] = 0;
		else
			res[i++] = 1;
		*index = *index + 1;
	}
	res[i] = 0;
	return (res);
}

int	**ft_splint(char *str, char *charset, char buf[2])
{
	int		**res;
	int		ac;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ac = word_count(str, charset);
	res = (int **)malloc(ac * sizeof(int *));
	if (!res)
		return (NULL);
	while (i < ac)
	{
		res[i++] = get_next_tab(&j, str, charset, buf);
		if (!res[i - 1])
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
	}
	return (res);
}