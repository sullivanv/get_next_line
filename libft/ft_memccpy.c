/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 01:47:45 by suvitiel          #+#    #+#             */
/*   Updated: 2017/01/09 20:51:20 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	char			*s1;

	s1 = dest;
	i = 0;
	while (i < n)
	{
		*(s1 + i) = *((unsigned char*)src + i);
		if ((unsigned char)c == *((unsigned char*)src + i))
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
