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

/*

  char **str;
  
  str = malloc(2*(sizeof(char*)));
  
  str[0] = malloc(5*(sizeof(char)));
  
  str[0][0] = 'V';
  str[0][1] = 'i'; 
  str[0][2] = 'v';
  str[0][3] = 'a'; 
  str[0][4] = '\0';
  
  str[1] = malloc(7*(sizeof(char)));
  
  str[1][0] = 'M';
  str[1][1] = 'a'; 
  str[1][2] = 'd';
  str[1][3] = 'r'; 
  str[1][4] = 'i';
  str[1][5] = 'd';
  str[1][6] = '\0';


*/