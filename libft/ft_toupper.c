/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:28:42 by gshona            #+#    #+#             */
/*   Updated: 2020/11/01 13:29:24 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_lower(int c)
{
	int res;

	res = c >= 'a' && c <= 'z';
	return (res);
}

int			ft_toupper(int c)
{
	return (ft_is_lower(c) ? c - 32 : c);
}
