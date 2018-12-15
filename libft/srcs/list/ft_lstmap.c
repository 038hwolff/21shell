/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:11:54 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/04 18:11:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;

	if (!lst || !(list = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	list = f(lst);
	list->next = ft_lstmap(lst->next, f);
	return (list);
}
