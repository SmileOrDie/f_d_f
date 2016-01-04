/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 23:26:29 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/10 14:43:30 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*newlst2;

	newlst = f(lst);
	newlst2 = newlst;
	while (lst->next)
	{
		lst = lst->next;
		newlst2->next = f(lst);
		newlst2 = newlst2->next;
	}
	return (newlst);
}
