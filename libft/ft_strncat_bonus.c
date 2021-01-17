/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:24:18 by gshona            #+#    #+#             */
/*   Updated: 2020/11/02 14:42:50 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len1;
	size_t	i;
	char	*res;

	if (!dest && !src)
		return (NULL);
	len1 = ft_strlen(dest);
	res = dest;
	i = 0;
	while (i < n && src[i])
	{
		res[i + len1] = src[i];
		i++;
	}
	res[i + len1] = '\0';
	return (res);
}
