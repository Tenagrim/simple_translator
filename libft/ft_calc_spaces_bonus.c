/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:09:57 by gshona            #+#    #+#             */
/*   Updated: 2020/10/28 12:15:43 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	calc_spaces(const char *str, size_t len, size_t *pref, size_t *post)
{
	size_t	i;

	i = 0;
	*post = 0;
	*pref = 0;
	while (i < len && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		i++;
	*pref = i;
	i = len - 1;
	while (i != 0 && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		i--;
	*post = len - i - 1;
}
