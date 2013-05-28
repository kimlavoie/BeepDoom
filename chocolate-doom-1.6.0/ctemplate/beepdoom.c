#include <stdio.h>
#include <stdlib.h>
#include "ctemplate.h"

FILE* pipeFile;
TMPL_varlist *variableList;

void beforeLoop()
{
	pipeFile = fopen("pipe.pipe", "w");
}

void duringLoop()
{
	variableList = TMPL_add_var(0,"test", "Hello the world!",0);
	TMPL_write("template.xml", 0, 0, variableList, pipeFile, 0);
}

int main(){return 0;}
