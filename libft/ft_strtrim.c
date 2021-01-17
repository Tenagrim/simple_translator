/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:27:23 by gshona            #+#    #+#             */
/*   Updated: 2020/10/31 18:16:54 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		in_set(char c, const char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void		calc_spaces(const char *str, size_t *pref,
		size_t *post, const char *set)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	*post = 0;
	*pref = 0;
	while (i < len && in_set(str[i], set))
		i++;
	*pref = i;
	i = len - 1;
	while (i != 0 && in_set(str[i], set))
		i--;
	*post = len - i - 1;
}

static int		strcheck(const char *str, const char *set)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (!in_set(str[i], set))
			return (1);
		i++;
	}
	return (0);
}

static char		*null_res(void)
{
	char	*res;

	res = malloc(sizeof(char));
	if (!res)
		return (NULL);
	res[0] = 0;
	return (res);
}

char			*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	char	*res;
	size_t	pref;
	size_t	post;
	size_t	len;

	if (!strcheck(s, set))
		return (null_res());
	len = ft_strlen(s);
	calc_spaces(s, &pref, &post, set);
	i = pref;
	res = malloc(len - pref - post + 1);
	if (!res)
		return (NULL);
	res[len - pref - post] = 0;
	while (i < len - post)
	{
		res[i - pref] = s[i];
		i++;
	}
	return (res);
}
