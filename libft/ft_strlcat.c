/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 07:39:06 by suvitiel          #+#    #+#             */
/*   Updated: 2016/11/21 20:34:18 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;
	unsigned int i2;
	unsigned int j2;

	i = 0;
	j = 0;
	j2 = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	i2 = i;
	while (src[j2] && j2 < size && i2 + 1 < size)
	{
		dest[i2] = src[j2];
		i2++;
		j2++;
	}
	dest[i2] = '\0';
	if (j + size < j + i)
		return (j + size);
	else
		return (j + i);
}
