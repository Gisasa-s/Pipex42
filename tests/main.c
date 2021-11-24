
#include "ft_pipex.h"

int main()
{
	int i;
	int k;
  
	i = 0;
	k = 5;
	int id = fork();
	wait(NULL);
 	
	if (id == 0)
	{
		printf("soy el hijo %d\n", id);
		while (i <= 5)
		{
			i++;
			printf("%d \n", i );
		}
	}

	if (id != 0)
	{
		printf("soy el padre %d\n", id);
		while (k <= 10)
		{
			k++;
		printf("%d \n", k);
		}
	}
		

	printf("\n");
	return(i);
}
