#include <stdio.h>
#include <stdlib.h>
#include "../ctemplate/ctemplate.h"
#include "timestats.h"

FILE* pipeFile;
TMPL_varlist *variableList;
player_t *mainPlayer;
//Variables pour tester l'impact temporel de l'isntrumentation
extern float endInstruFPS;
extern clock_t endInstruCPU;

void beforeLoop()
{
	pipeFile = fopen("pipe.pipe", "w");
	mainPlayer = &players[consoleplayer];
}

void duringLoop()
{	
	char buffer[3];

	// convert an int in char[]
	// snprint(buffer, buffersize, "%d", intToConvert) 
	snprintf(buffer, 3, "%d", (mainPlayer->health));

	// TMPL_add_var add a variable to the list in the first parameter and return the list.
	// if the first param is 0, it create a TMPL_varlist and return it.
	// TMPL_add_var(list, varName1, value1, varName2, value2, ..., 0)
	variableList = TMPL_add_var(0, "test", buffer, 0);

	// TMPL_write 's purpose is to output the text in a file (in our case, the pipe)
	// TMPL_write(templateFilename, 0, 0, list, outputFile, errorsOutputFile)
	TMPL_write("template.xml", 0, 0, variableList, pipeFile, 0);

	//Time 
	endInstruFPS = SDL_GetTicks();
	endInstruCPU = clock();
}

