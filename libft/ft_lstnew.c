/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:13:12 by gshona            #+#    #+#             */
/*   Updated: 2020/10/28 14:12:47 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content)
{
	t_list	*res;

	res = (t_list*)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = (void*)content;
	res->next = NULL;
	return (res);
}
