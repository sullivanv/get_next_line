/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 00:55:45 by suvitiel          #+#    #+#             */
/*   Updated: 2017/01/10 03:11:24 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_init_line(char *line, int *i, int j, char const *str)
{
	int x;

	x = 0;
	while (j < *i)
	{
		line[x] = str[j];
		j++;
		x++;
	}
	line[x] = '\0';
	return (line);
}

static char	**ft_init_tab(char const *str, int count, int *i, char c)
{
	int		x;
	int		j;
	char	**tab;

	x = 0;
	*i = 0;
	tab = (char**)malloc((sizeof(tab) * count) + 1);
	if (tab == NULL)
		return (NULL);
	while (x < count)
	{
		while (str[*i] == c && str[*i])
			*i = *i + 1;
		j = *i;
		while (str[*i] != c && str[*i])
			*i = *i + 1;
		tab[x] = (char*)malloc(sizeof(tab[x]) * (*i - j) + 2);
		if (tab[x] == NULL)
			return (NULL);
		tab[x] = ft_init_line(tab[x], i, j, str);
		x++;
	}
	tab[x] = 0;
	return (tab);
}

char		**ft_strsplit(char const *str, char c)
{
	int i;
	int count;
	int first;

	i = 0;
	count = 0;
	first = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		while ((str[i] == c) && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			if (first == 0)
				count++;
			first = 1;
			i++;
		}
		first = 0;
	}
	return (ft_init_tab(str, count, &i, c));
}
