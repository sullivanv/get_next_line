/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 02:20:27 by suvitiel          #+#    #+#             */
/*   Updated: 2016/12/23 01:04:26 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		res;

	i = 0;
	res = -1;
	str = (char*)s;
	if (str[i] == c)
		res = i;
	while (str[i])
	{
		if (str[i + 1] == c)
			res = i + 1;
		i++;
	}
	if (res == -1)
		return (NULL);
	return (&str[res]);
}
