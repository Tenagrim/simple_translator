/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:47:16 by gshona            #+#    #+#             */
/*   Updated: 2020/10/28 10:47:54 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*remove_spaces(const char *s)
{
	char	*str;

	str = (char *)s;
	while (*str == ' ' || *str == '\f' || *str == '\r' || *str == '\t' ||
							*str == '\n' || *str == '\v')
		str++;
	return (str);
}

static void		init(long long *result, long long *offset)
{
	*result = 0;
	*offset = 1;
}

int				ft_atoi(const char *s)
{
	long long		result;
	long long		offset;
	char			*temp_ptr;
	char			*str;

	str = remove_spaces(s);
	temp_ptr = str;
	init(&result, &offset);
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	while (*str >= '0' && *str <= '9')
	{
		offset *= 10;
		str++;
	}
	offset /= 10;
	str = (*temp_ptr == '-' || *temp_ptr == '+') ? temp_ptr + 1 : temp_ptr;
	while (*str >= '0' && *str <= '9')
	{
		result += ((int)(*str - 48)) * offset;
		offset /= 10;
		str++;
	}
	result = (*temp_ptr == '-') ? -result : result;
	return ((int)result);
}
