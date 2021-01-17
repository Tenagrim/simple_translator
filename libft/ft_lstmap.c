/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:13:07 by gshona            #+#    #+#             */
/*   Updated: 2020/10/28 14:51:30 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(t_list *elem),
		void (*del)(void *))
{
	t_list	*res;
	t_list	*p;
	t_list	*new;
	void	*tmp;

	res = NULL;
	p = lst;
	while (p)
	{
		tmp = f(p->content);
		if (tmp)
		{
			new = ft_lstnew(tmp);
			if (!new)
			{
				ft_lstclear(&res, del);
				return (NULL);
			}
			ft_lstadd_back(&res, new);
		}
		p = p->next;
	}
	return (res);
}
