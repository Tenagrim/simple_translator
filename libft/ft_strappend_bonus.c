/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:18:58 by gshona            #+#    #+#             */
/*   Updated: 2020/10/28 11:19:15 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strappend(char **str, char *append)
{
	char *res;

	if (!*str)
	{
		*str = ft_strdup(append);
		return ;
	}
	res = ft_strjoin(*str, append);
	if (*str)
		free(*str);
	*str = res;
}
