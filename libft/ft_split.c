/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:17:39 by gshona            #+#    #+#             */
/*   Updated: 2020/10/31 15:48:10 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	arr_len(char **arr)
{
	size_t	len;

	if (!arr)
		return (0);
	len = 0;
	while (arr[len])
		len++;
	return (len);
}

static void		push_back(char ***arr, char *add)
{
	size_t	len;
	size_t	i;
	char	**res;

	len = arr_len(*arr);
	res = malloc(sizeof(char *) * (len + 2));
	if (!res)
		return ;
	i = 0;
	while (i < len)
	{
		res[i] = arr[0][i];
		i++;
	}
	res[len] = add;
	res[len + 1] = NULL;
	if (arr[0])
		free(arr[0]);
	*arr = res;
}

static int		strcheck(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] != c)
			return (1);
		i++;
	}
	return (0);
}

static char		**null_res(void)
{
	char	**res;

	res = malloc(sizeof(char*));
	res[0] = NULL;
	return (res);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word_len;
	char	**res;
	char	*substr;

	if (!strcheck(s, c))
		return (null_res());
	i = 0;
	word_len = 0;
	res = NULL;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			word_len++;
		else if (word_len != 0)
		{
			substr = ft_substr(s, i - word_len, word_len);
			push_back(&res, substr);
			word_len = 0;
		}
		i++;
	}
	if (s[i - 1] != c)
		push_back(&res, ft_substr(s, i - word_len, word_len));
	return (res);
}
