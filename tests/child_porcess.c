
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

/*
** EJEMPLO
** ./pipex <arch entrada> "comando 1" "comando 2" <archivo salida>
**
** ./pipex a "cat -e" "grep b" b
**
** equivale a lo siguiente
** a > cat -e | grep b > b
**
**
** TODO:
**    1º controlar que <arch entrada> sea un archivo y sea accesible
**              ACCESS devuelve un entero que indica si es accesible o no  (man 2 access)
**    2º intentar parsear los comandos separandolos completamente
**          "cat -e"       "grep b"
**    3º splitees el comando en cuestion
**         cat    -e          grep    b
**    4º procesos de pipe para input y output con los forks    (man 2 fork)  whentruethendream        
*/    

int main(int argc, char* argv[], char**envp)
{
	int pid;
	int a;
	int aux;

	pid = fork();

	//quiero manga por a.txt
	//quiero anime por pantalla
	if (pid == 0) // si la id es igual a 0 es el proceso hijo 
	{
		a = open("a.txt", O_CREAT | O_WRONLY | O_APPEND, 0644); // con el (a) declarado le digo que con la funcion open me cree el archivo .txt ademas de que sea el puerto 3 que no  exisitia hasta 



		write(a, "hola quiero mangas \n", 20); // le indico con write que me escriba en a que es el fd3 que esta en a , el texto de "hola quiero mangas" + indicarle cuantos carcteres son 


		write(1, "hola anime\n", 11);

		
		
		// creo un archivo 
		//execlp("/bin/ls", "ls", "-l", NULL); // me busca en la ruta de donde se encuentra el ls y lo d detras lo destruye todo 
		// por lo que debo neter un archivo para que no se borre y pasar el sdouta al archivo 

	}
	
}