/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 04:04:39 by suvitiel          #+#    #+#             */
/*   Updated: 2017/01/10 04:59:04 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *list;

	if (lst && f)
	{
		list = f(lst);
		temp = list;
		while (lst->next)
		{
			lst = lst->next;
			temp->next = f(lst);
			if (temp->next == NULL)
				return (NULL);
			temp = temp->next;
		}
		return (list);
	}
	return (NULL);
}
