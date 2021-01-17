/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:15:15 by gshona            #+#    #+#             */
/*   Updated: 2020/10/28 11:54:30 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		write_hex(unsigned char *p, size_t size, int i, int j)
{
	char	*hex;

	j = 0;
	hex = "0123456789abcdef";
	while (j < 16 && i + j < (int)size)
	{
		write(1, &hex[(*(p + i + j) / 16) % 16], 1);
		write(1, &hex[*(p + i + j) % 16], 1);
		if (j % 2)
			write(1, " ", 1);
		j++;
	}
}

static void		main_sycle(const void *addr, size_t size, int i, int j)
{
	unsigned char	*p;

	p = (unsigned char *)addr;
	write_hex(p, size, i, j);
	while (j < 16)
	{
		write(1, "  ", 2);
		if (j % 2)
			write(1, " ", 1);
		j++;
	}
	j = 0;
	while (j < 16 && i + j < (int)size)
	{
		if (*(p + i + j) >= 32 && *(p + i + j) < 127)
			write(1, p + i + j, 1);
		else
			write(1, ".", 1);
		j++;
	}
}

void			ft_print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (i < size)
	{
		main_sycle(addr, size, i, j);
		write(1, "\n", 1);
		i += 16;
	}
}
