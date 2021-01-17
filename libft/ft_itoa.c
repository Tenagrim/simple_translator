/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:12:06 by gshona            #+#    #+#             */
/*   Updated: 2020/11/02 10:35:05 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calc_digits_s(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	n = (n < 0) ? -n : n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*ft_str_new(size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char*)malloc(sizeof(char) * size + 1);
	if (res == NULL)
		return (NULL);
	res[size] = '\0';
	while (i < size)
		res[i++] = 0;
	return (res);
}

char			*ft_itoa(int n)
{
	size_t	len;
	size_t	sign;
	int		i;
	char	*res;

	sign = n < 0;
	len = ft_calc_digits_s(n) + sign;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n = n < 0 ? -n : n;
	i = len - 1;
	res = ft_str_new(len);
	if (!res)
		return (NULL);
	while (i >= 0)
	{
		res[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	res[0] = sign ? '-' : res[0];
	return (res);
}
