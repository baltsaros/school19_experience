/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:33:11 by abuzdin           #+#    #+#             */
/*   Updated: 2022/05/16 16:19:18 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static size_t	check_str(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 1;
	n = 0;
	if (!(s[0]))
		return (0);
	if (s[0] != c)
		++n;
	if (s[0] == '"')
		i = 0;
	while (s[i])
	{
		if (s[i] == '"')
		{
			if (s[i] != c && s[i - 1] == c)
				++n;
			++i;
			while (s[i] && s[i] != '"')
				++i;
			++i;
		}
		if (s[i] != c && s[i - 1] == c)
			++n;
		++i;
	}
	return (n);
}

static char	**ft_create_str(char **spl, char const *s, char c, int i)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (s[start])
	{
		end = 0;
		while (s[start + end] && s[start + end] != c && s[start + end] != '"')
			++end;
		if (s[start + end] == '"')
		{
			++end;
			while (s[start + end] && s[start + end] != '"')
				++end;
			++end;
		}
		if (end > 0)
		{
			spl[i] = ft_strndup(s + start, end);
			if (!spl[i])
			{
				ft_free(spl);
				return (NULL);
			}
			++i;
			start = start + end;
		}
		if (s[start])
			++start;
	}
	spl[i] = NULL;
	return (spl);
}

char	**ft_split_op(char const *s, char c)
{
	char	**spl;
	size_t	size;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	size = check_str(s, c);
	spl = (char **)malloc(sizeof(*spl) * (size + 1));
	if (!spl)
		return (NULL);
	spl = ft_create_str(spl, s, c, i);
	return (spl);
}
