/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:11:04 by gshona            #+#    #+#             */
/*   Updated: 2020/10/28 12:13:55 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *str, char sep)
{
	size_t	i;
	size_t	count;

	if (!str || !(str[0]))
		return (0);
	i = 1;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == sep && str[i - 1] != sep)
			count++;
		i++;
	}
	if (str[i - 1] != sep)
		count++;
	return (count);
}
