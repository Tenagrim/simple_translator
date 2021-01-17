/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:25:15 by gshona            #+#    #+#             */
/*   Updated: 2020/11/03 10:52:17 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t len1;
	size_t len2;

	len1 = ft_strlen(haystack);
	len2 = ft_strlen(needle);
	if (len2 == 0)
		return ((char*)haystack);
	while (*haystack && len2 <= len--)
	{
		if (!ft_strncmp(haystack, needle, len2))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
