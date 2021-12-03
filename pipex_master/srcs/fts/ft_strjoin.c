/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:54:25 by ahernand          #+#    #+#             */
/*   Updated: 2021/09/07 17:12:15 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*cpy_str;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	cpy_str = str;
	if (s1)
		while (*s1 != '\0')
			*cpy_str++ = *s1++;
	if (s2)
		while (*s2 != '\0')
			*cpy_str++ = *s2++;
	*cpy_str = '\0';
	return (str);
}
