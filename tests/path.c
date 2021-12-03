#include "ft_pipex.h"


int main(int argc, char* argv[], char**envp)
{	
	int i;
	char **str;
	char **ptr;

	i = 0;
str = malloc(3 *(sizeof(char*)));

str[0] = malloc(5 *(sizeof(char)));
	str[0][0] = 'P';
	str[0][1] = 'A';
	str[0][2] = 'T';
	str[0][3] = 'H';
	str[0][4] = '\0';
	while (envp[i] != NULL)
	{
		i++;
		if (str[0][0] == envp[i][0])
		{
			if (str[0][1] == envp[i][1])
			{
				if (str[0][2] == envp[i][2])
				{
					if (str[0][3] == envp[i][3])
					{
						printf("%s\n", envp[i]);

						ptr = ft_split(envp[i], ':'); //Y le digo que con  la fuuncion split me guarde en str espliteado el envp[i] y que esolite
						while(ptr[2] == envp[i])
						{
							free(ptr);

						}
						if(str == NULL)
						{
							return(0);

						}
					}
				}
			}
		}
	}
return (0);

}