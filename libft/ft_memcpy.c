/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:13:59 by gshona            #+#    #+#             */
/*   Updated: 2020/11/02 16:13:47 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*p_d;
	unsigned char	*p_s;
	size_t			i;

	if (!dest && !src && num)
		return (NULL);
	p_s = (unsigned char *)src;
	p_d = (unsigned char *)dest;
	i = 0;
	while (i < num)
	{
		p_d[i] = p_s[i];
		i++;
	}
	return (dest);
}
