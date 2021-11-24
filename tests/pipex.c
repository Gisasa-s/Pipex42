#include "ft_pipex.h"

#define READ_END 0
#define WRITE_END 1

#define FILE_NAME "file.txt"

int main(int argc, char* argv[])
{
 	int fd1[2], fd2;
	int status, pid;

	pipe(fd1);

	pid = fork();

	if (pid == 0)
	{
		close(fd1[READ_END]);

		dup2(fd1[WRITE_END], STDOUT_FILENO);
		close(fd1[WRITE_END]);

		execlp("/bin/ls", "ls", "-l", NULL);

	}
	else
	{




		close(fd1[WRITE_END]);

		pid =fork();

		if (pid == 0)
		{
			fd2 = open(FILE_NAME, O_WRONLY);
			dup2(fd1[READ_END], STDIN_FILENO);


			close(fd1[READ_END]);

			dup2(fd2, STDIN_FILENO);
			execlp("/usr/bin/wc", "wc", NULL );
		}
		else
		{
			close(fd1[READ_END]);
		}
	}
	wait(&status);
	wait(&status);
	return(0);
}	