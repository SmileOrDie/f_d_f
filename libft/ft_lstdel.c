/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:30:59 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/08 17:42:18 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*alst_tmp;
	t_list	*next_tmp;

	alst_tmp = *alst;
	while (alst_tmp)
	{
		next_tmp = alst_tmp->next;
		del(alst_tmp->content, alst_tmp->content_size);
		free(alst_tmp);
		alst_tmp = next_tmp;
	}
	*alst = (NULL);
}
