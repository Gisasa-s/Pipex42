/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:23:56 by ahernand          #+#    #+#             */
/*   Updated: 2021/09/07 17:12:21 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../pipex.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	char	*ss;

	i = 0;
	ss = (char *)s;
	while (ss[i] != '\0')
		i++;
	return (i);
}
