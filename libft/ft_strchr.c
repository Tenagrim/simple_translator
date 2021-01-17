/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:19:39 by gshona            #+#    #+#             */
/*   Updated: 2020/10/28 11:19:50 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t		i;
	size_t		len;
	char		value;

	value = (char)c;
	len = ft_strlen(str);
	i = 0;
	while (i < len + 1)
	{
		if (str[i] == value)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
