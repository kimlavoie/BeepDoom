/**
 * Exemple de création d'un fifo et d'écriture dans celui-ci.
 */

#include <sys/stat.h>		//pour mkfifo
#include <stdio.h>			//pour fopen et FILE
#include <string.h>			//pour strlen

int main()
{	
	mkfifo("test.pipe", S_IRWXU);							//créer un pipe nommé "test.pipe" en lecture et écriture
	
	FILE* fichier;											//pointeur vers le fichier à ouvrir
	char string[] = "Test d'ecriture dans un fifo\n";		//ce qu'on veut écrire dans le fichier
	fichier = fopen("test.pipe", "w");						//on ouvre le fichier en écriture
	fwrite(string,1,strlen(string),fileHandle);				//écriture dans le fichier
	
	return 0;												//fin du programme
}
