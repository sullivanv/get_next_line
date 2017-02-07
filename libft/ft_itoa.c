/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 23:35:33 by suvitiel          #+#    #+#             */
/*   Updated: 2017/01/10 02:40:59 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_apply(int n, char *str, int isneg, int i)
{
	str[i] = '\0';
	i--;
	if (isneg == 1)
	{
		str[0] = '-';
		n = -n;
	}
	while ((i > 0 && isneg == 1) || (i >= 0 && isneg == 0))
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		nb;
	int		i;
	char	*str;
	int		isneg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 1;
	isneg = 0;
	if (n < 0)
	{
		i++;
		isneg = 1;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	str = (char*)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	return (ft_apply(n, str, isneg, i));
}
