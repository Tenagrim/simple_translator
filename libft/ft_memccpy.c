/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:13:22 by gshona            #+#    #+#             */
/*   Updated: 2020/11/02 14:39:34 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	unsigned char	*p_d;
	unsigned char	*p_s;
	unsigned char	stop;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	p_s = (unsigned char *)src;
	p_d = (unsigned char *)dest;
	stop = (unsigned char)c;
	i = 0;
	while (i < num)
	{
		p_d[i] = p_s[i];
		if (p_d[i] == stop)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
