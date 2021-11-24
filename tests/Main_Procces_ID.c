#include "ft_pipex.h"

int main()
{

int id = fork();
if (id == 0)
{
	sleep(1);
}
printf("current ID %d, parent ID: %d\n",
getpid(), getppid());
int res = wait(NULL);
if (res == -1)
{
	printf("el hijo espera a ");
} 
else
{
	printf("%d final de la eejcucion \n", res);
}
return (0);
}

