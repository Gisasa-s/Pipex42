/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisasa-s <gisasa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:08:34 by ahernand          #+#    #+#             */
/*   Updated: 2021/12/03 17:08:52 by gisasa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//		./pipex	infile cmd1 cmd2 outfile

int	main(int argc, char **argv, char **envp)		//argc = NUMERO DE ARGUMENTOS
{
	int		pipe_fd[2];								// Las pipes sirven para meter datos, y ser usados por lso comandos. Usando file descriptors(fd)
	int		id;										// El id se usará para saber si es padre (id != 0) o hijo (id == 0)

	if (argc != 5)									// El programa solo admite 5 argumentos
		return (ft_error_m(1, argc));
	if (pipe(pipe_fd) < 0 || !argv)					// Se inicia la pipa
		return (ft_error_m(2, argc));

		

	id = fork();									// Se duplica el programa. Ahora hay un clon, llamado hijo



	if (id < 0)										//control de errores por si no se inica bien el pipex
		return (ft_error_m(3, argc));



		
	if (id == 0)									// Si es el hijo, pasa por aqui
		if ((ft_child(argv, envp, pipe_fd)) == -1)	// Se ejecuta la función hijo
			return (0);


	if (id != 0)									// Si es el padre, pasa por aqui
	{
		waitpid(0, 0, WNOWAIT);						// Espera a que el hijo termine de hacer sus cosas ( ejecutar comando 1 )
		if ((ft_parent(argv, envp, pipe_fd)) == -1) // Se ejecuta la función padre
			return (0);
	}


	
	close(pipe_fd[0]);								// Cerrar la pipe de lectura
	close(pipe_fd[1]);								// Cerrar la pipe de escritura
	return (0);
}

// el hijo toma como argumentos :
//		_	argv		los argumentos pasados por el main
//		_	envp		los variables de la terminal, (CONTIENE PATH)
//		_	pipe_fd		la pipa




int	ft_child(char **argv, char **envp, int pipe_fd[])	
{
	int		in_fd;									//	File descriptor del archivo por donde vas a recibir los argumentos para el commando 1
	char	**a;									//	Es un doble puntero. Guardará varias strings (char *)

	in_fd = open(argv[1], O_RDONLY);				//	Abres el "infile" 
	if (in_fd < 0)
		return (ft_error(6));
	close(pipe_fd[0]);								//	Cierras la parte de lectura, porque vas a leer primero
	dup2(in_fd, 0);									//	Haces que el fd 0 deje de apuntar a la terminal de entrada, y ahora apuntará al archivo, para que después el comando1 lea del archivo
	dup2(pipe_fd[1], 1);							//	Haces que el fd 1 deje de apuntar a la terminal de salida, y ahora apuntará a la pipa[1], para que después el comando 2 lea de la pipa. 
	a = ft_split(argv[2], ' ');						//	usamos split para sacar de una string, varias, sapraras por espacios// EJ:  "Hola que tal" dividido por espacios -> "Hola" "Que" "Tal"
	if (!a)											//	control de errores, si split a fallado
		return (ft_error(4));
	a[0] = ft_path(envp, a);						//	Busca en envp, para PATH, y recoge el path adecuado	EJ : "ls" -> "/bin/ls"
	if (execve(a[0], a, envp) < 0)					//	Ejecuta el comando 1. Toma de argumento, a[0]-> cmd1, a-> el comando + todos los argumentos, envp____ EJ: a[0] = "/bin/ls" a[1] = "-l", a[2] = NULL
	{
		ft_free_fork(a, in_fd);						//	liberar memoria en caso de fail
		return (ft_error(4));						
	}
	ft_free_fork(a, in_fd);							
	return (1);
}

int	ft_parent(char **argv, char **envp, int pipe_fd[])
{
	int		out_fd;									//	File descriptor del archivo (outfile) por donde vas a echar las lineas que expulse el comando 2
	char	**a;									//	Es un doble puntero. Guardará varias strings (char *)

	out_fd = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0644);				//	Abres el "outfile", que es el argv[4], si no existe lo creas
	if (out_fd < 0)
		return (-1);
	close(pipe_fd[1]);								//	Cierras la parte de escritura, para leer el output del comando 1
	dup2(pipe_fd[0], 0);							//	Haces que el fd 0 deje de apuntar al archivo infile , y ahora apuntará a la pipa[0], donde está el output del comando 1
	dup2(out_fd, 1);								//	Haces que el fd 1 deje de apuntar a la pipa y apunte al archivo  output, donde se meterá las lines que expulse el comando 2
	a = ft_split(argv[3], ' ');						//	usamos split para sacar de una string, varias strings, sapraras por espacios// EJ:  "ls -la" dividido por espacios -> "ls" "-la"
	if (!a)
		return (-1);
	a[0] = ft_path(envp, a);						//	Busca en envp, para PATH, y recoge el path adecuado	EJ : "ls" -> "/bin/ls"
	if (execve(a[0], a, envp) < 0)					//	Ejecuta el comando 2. Toma de argumento, a[0]-> cmd2, a-> el comando + todos los argumentos, envp____ EJ: a[0] = "/bin/ls" a[1] = "-l", a[2] = NULL
	{	
		ft_free_fork(a, out_fd);					//	liberar memoria en caso de fail
		return (ft_error(5));
	}
	ft_free_fork(a, out_fd);
	return (1);
}
