/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:19:27 by gshona            #+#    #+#             */
/*   Updated: 2020/11/02 14:42:27 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*res;

	if (!dest && !src)
		return (NULL);
	len1 = ft_strlen(dest);
	len2 = ft_strlen(src);
	res = dest;
	i = 0;
	while (i < len2)
	{
		res[i + len1] = src[i];
		i++;
	}
	res[i + len1] = '\0';
	return (res);
}
