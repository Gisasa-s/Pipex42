#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
//lectura 1
//escrritra 0 	
	int fd[2];
	int id;
	char buf[10];
	int		f;

	pipe(fd);
	id = fork();


	if (id != 0)
	{
		wait (NULL);
		close (fd[1]);
	//	printf("soyy el padre %d\n", id);
	
		f = read(fd[0], buf, 10);

		printf("Padre lee %d bytes: _%s_ \n", f, buf);

		close (fd[0]);
	}
	if (id == 0)
	{
		close (fd[0]);
		write(fd[1], "12345", 5); // con write le mando 3 o 4 para que 
		//printf("soy el hijo %d\n", id);
		close (fd[1]);
		exit(0);
	}
	
	return(0);
}