/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:34 by ahernand          #+#    #+#             */
/*   Updated: 2021/09/29 14:17:12 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error_m(int err_code, int argc)
{
	if (err_code == 1 && argc < 5)
		write(2, "Error: Not enough arguments\n", 28);
	if (err_code == 1 && argc > 5)
		write(2, "Error: Too many arguments\n", 26);
	if (err_code == 2)
		write(2, "Error: Couldn't create pipe\n", 28);
	if (err_code == 3)
		write(2, "Error: Fork coudln't start\n", 27);
	return (0);
}

int	ft_error(int err_code)
{
	if (err_code == 4)
		write(2, "Error: execve error on first command\n", 38);
	if (err_code == 5)
		write(2, "Error: execve error on second command\n", 39);
	if (err_code == 6)
		write(2, "Error: couldn't open input file\n", 38);
	return (-1);
}

void	ft_free_fork(char **a, int fd)
{
	int		i;

	i = 0;
	close(fd);
	if (a)
	{
		while (a[i] != NULL)
		{
			free(a[i]);
			i++;
		}
		if (a)
			free(a);
	}
}

int	ft_full_route(char *str)
{
	if (str[0] == '/')
	{
		if (access(str, F_OK) == 0)
			return (1);
	}
	return (-1);
}
