/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:33:11 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/13 10:40:47 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_str(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 1;
	if (!(s[i]))
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			++n;
		++i;
	}
	return (n);
}

static char	*ft_strndup(char const *str, size_t size)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(sizeof(*dest) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_create_str(char **spl, char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	while (s[start])
	{
		end = 0;
		while (s[start + end] && s[start + end] != c)
			++end;
		if (end > 0)
		{
			spl[i] = ft_strndup(s + start, end);
			++i;
			start = start + end;
		}
		if (s[start])
			++start;
	}
	spl[i] = NULL;
	return (spl);
}

char	**ft_split(char const *s, char c)
{
	char	**spl;
	size_t	size;

	size = check_str(s, c);
	if (!s)
		return (NULL);
	spl = (char **)malloc(sizeof(spl) * (size + 1));
	if (!spl)
		return (NULL);
	spl = ft_create_str(spl, s, c);
	spl[size] = NULL;
	return (spl);
}

// int		main(void)
// {
// 	// char	s[] = "b";
// 	char	s[] = "aaabcaAaAaefaa a";
// 	// char	s[] = "bac";
// 	char	c;
// 	char	**ret;
// 	int		j;

// 	c = 'a';
// 	ret = ft_split(s, c);
// 	j = 0;
// 	while (ret[j])
// 	{
// 		printf("str[%d] is '%s'\n", j, ret[j]);
// 		++j;
// 	}
// 	printf("Final amount of strings is %d\n", j);
// 	free(ret);
// 	return (0);
// }