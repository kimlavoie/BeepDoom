#include <stdio.h>
#include <stdlib.h>
#include "../ctemplate/ctemplate.h"

FILE* pipeFile;
TMPL_varlist *variableList;
player_t *mainPlayer;

void beforeLoop()
{
	pipeFile = fopen("pipe.pipe", "w");
	mainPlayer = &players[consoleplayer];
}

void duringLoop()
{
	char buffer[10];
	snprintf(buffer, 10, "%d", (mainPlayer->health));
	variableList = TMPL_add_var(0, "test", buffer, 0);
	TMPL_write("template.xml", 0, 0, variableList, pipeFile, 0);
}

