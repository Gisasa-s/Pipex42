/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:12:36 by ahernand          #+#    #+#             */
/*   Updated: 2021/09/07 17:12:09 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	pos_word(char *s, char c, unsigned int order)
{
	int				is_word;
	unsigned int	cnt;
	unsigned int	pos;

	is_word = 0;
	cnt = 0;
	pos = 0;
	while (s[pos] != '\0')
	{
		if (is_word == 0 && s[pos] != c)
		{
			cnt++;
			if (cnt == order + 1)
				break ;
			is_word = 1;
		}
		else if (is_word == 1 && s[pos] == c)
			is_word = 0;
		pos++;
	}
	return (pos);
}

static int	count_words(char *s, char c)
{
	int				is_word;
	unsigned int	cnt;

	cnt = 0;
	is_word = 0;
	while (*s != '\0')
	{
		if (is_word == 0 && *s != c)
		{
			cnt++;
			is_word = 1;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (cnt);
}

static char	*assign_word(char *s, char c)
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	nb;
	unsigned int	i;
	char			**str;
	char			*ptr;

	if (!s)
		return (0);
	ptr = (char *)s;
	nb = count_words(ptr, c);
	str = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < nb)
	{
		str[i] = assign_word(ptr + pos_word(ptr, c, i), c);
		i++;
	}
	str[i] = 0;
	return (str);
}
