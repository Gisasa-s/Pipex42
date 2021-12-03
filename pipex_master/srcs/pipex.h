/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:34:09 by ahernand          #+#    #+#             */
/*   Updated: 2021/09/27 18:09:32 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>

/*
**		P I P E X
**		_ _ _ _ _
*/

int		ft_child(char **argv, char **envp, int pipe_fd[]);
int		ft_parent(char **argv, char **envp, int pipe_fd[]);
char	**ft_args_b(int argc, char **argv, char **envp, char *path);

int		ft_error(int err_code);
int		ft_error_m(int err_code, int argc);
void	ft_free_fork(char **a, int fd);

/*
**		P A R S I N G
**		_ _ _ _ _
*/

char	*ft_path(char **envp, char **a);
char	*ft_good_path(char **list_paths, char *cmd);
char	*ft_fix_first(char **list_paths);
int		ft_path_pos(char **envp);
int		ft_full_route(char *str);

/*
**		L I B F T
*/

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif
