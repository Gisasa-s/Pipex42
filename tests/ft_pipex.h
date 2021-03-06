/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisasa-s <gisasa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:04:09 by gisasa-s          #+#    #+#             */
/*   Updated: 2021/11/27 19:25:15 by gisasa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FT_PIPEX_H
# define FT_PIPEX_H

#include <unistd.h>
#include <stdio.h>

#include <fcntl.h>

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(char const *str);
char	**ft_split(char const *s, char c);
#endif