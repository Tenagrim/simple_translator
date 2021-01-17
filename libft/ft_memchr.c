/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:13:41 by gshona            #+#    #+#             */
/*   Updated: 2020/11/02 14:40:07 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	val;
	size_t			i;

	p = (unsigned char *)str;
	val = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == val)
			return (p + i);
		i++;
	}
	return (NULL);
}
