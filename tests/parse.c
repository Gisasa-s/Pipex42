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


#define READ_END 0 // lectura 
#define WRITE_END 1 // escritura 

#define FILE_NAME "file.txt"

int main(int argc, char* argv[], char**envp)
{
	int pid;
	int a;
	int aux;
	char	**str;
	str = malloc(5*(sizeof(char*)));

	str[0] = malloc(5*(sizeof(char)));

	str[0][0] = 'H';
	str[0][1] = 'o';
	str[0][2] = 'l';
	str[0][3] = 'a';
	str[0][4] = '\0';

	str[1] = malloc(5*(sizeof(char)));

	str[1][0] = 'Q';
	str[1][1] = 'u';
	str[1][2] ='e';
	str[1][3] = '\0';

	printf("%s %s", str[0], str[1]);

return (0);
}