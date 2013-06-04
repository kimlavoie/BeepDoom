#include <stdio.h>
#include <stdlib.h>
#include "../ctemplate/ctemplate.h"

FILE* pipeFile;
TMPL_varlist *variableList;
player_t *mainPlayer;

char bufferPlayerHealth[4];
char bufferArmor[4];
char bufferClipAmmos[4];
char bufferShotgunOwned[2];
char bufferShellAmmos[4];
char bufferChaingunOwned[2];
char bufferMissileOwned[2];
char bufferMissileAmmos[4];
char bufferPlasmaOwned[2];
char bufferCellAmmos[4];
char bufferBfgOwned[2];
char bufferChainsawOwned[2];
char bufferSuperShotgunOwned[2];
char bufferActualWeapon[13];
char bufferAttacking[2];
char bufferPlayerX[10];
char bufferPlayerY[10];
char bufferPlayerZ[10];
char bufferAttackerHealth[4];
char bufferAttackerX[10];
char bufferAttackerY[10];
char bufferAttackerZ[10];
char bufferAction[2];

void beforeLoop()
{
	pipeFile = fopen("pipe.pipe", "w");
	mainPlayer = &players[consoleplayer];
}

void duringLoop()
{	
	if(mainPlayer->mo != 0){
		// convert an int in char[]
		// snprint(buffer, buffersize, "%d", intToConvert) 
		snprintf(bufferPlayerHealth, 4, "%d", (mainPlayer->health));
		snprintf(bufferArmor, 4, "%d", (mainPlayer->armorpoints));
		snprintf(bufferClipAmmos, 4, "%d", (mainPlayer->ammo[am_clip]));
		snprintf(bufferShellAmmos, 4, "%d", (mainPlayer->ammo[am_shell]));
		snprintf(bufferMissileAmmos, 4, "%d", (mainPlayer->ammo[am_misl]));
		snprintf(bufferCellAmmos, 4, "%d", (mainPlayer->ammo[am_cell]));
		
		switch(mainPlayer->readyweapon){
				case wp_fist:
					snprintf(bufferActualWeapon, 13, "fist");
					break;
				case wp_pistol:
					snprintf(bufferActualWeapon, 13, "pistol");
					break;
				case wp_shotgun:
					snprintf(bufferActualWeapon, 13, "shotgun");
					break;
				case wp_chaingun:
					snprintf(bufferActualWeapon, 13, "chaingun");
					break;
				case wp_missile:
					snprintf(bufferActualWeapon, 13, "missile");
					break;
				case wp_plasma:
					snprintf(bufferActualWeapon, 13, "plasma");
					break;
				case wp_bfg:
					snprintf(bufferActualWeapon, 13, "bfg");
					break;
				case wp_chainsaw:
					snprintf(bufferActualWeapon, 13, "chainsaw");
					break;
				case wp_supershotgun:
					snprintf(bufferActualWeapon, 13, "supershotgun");
					break;
		}

		
		snprintf(bufferPlayerX, 10, "%d", (mainPlayer->mo->x));
		snprintf(bufferPlayerY, 10, "%d", (mainPlayer->mo->y));
		snprintf(bufferPlayerZ, 10, "%d", (mainPlayer->mo->z));
		
		
		if(mainPlayer->attacker != 0){
			snprintf(bufferAttackerX, 10, "%d", (mainPlayer->attacker->x));
			snprintf(bufferAttackerY, 10, "%d", (mainPlayer->attacker->y));
			snprintf(bufferAttackerZ, 10, "%d", (mainPlayer->attacker->z));
			snprintf(bufferAttackerHealth, 4, "%d", (mainPlayer->attacker->health));
		}

		bufferShotgunOwned[0] = (mainPlayer->weaponowned[wp_shotgun] ? 'T' : 'F');
		bufferChaingunOwned[0] = (mainPlayer->weaponowned[wp_chaingun] ? 'T' : 'F');
		bufferMissileOwned[0] = (mainPlayer->weaponowned[wp_missile] ? 'T' : 'F');
		bufferPlasmaOwned[0] = (mainPlayer->weaponowned[wp_plasma] ? 'T' : 'F');
		bufferBfgOwned[0] = (mainPlayer->weaponowned[wp_bfg] ? 'T' : 'F');
		bufferChainsawOwned[0] = (mainPlayer->weaponowned[wp_chainsaw] ? 'T' : 'F');
		bufferSuperShotgunOwned[0] = (mainPlayer->weaponowned[wp_supershotgun] ? 'T' : 'F');
		bufferAttacking[0] = (mainPlayer->attackdown ? 'T' : 'F');
		bufferAction[0] = (mainPlayer->usedown ? 'T' : 'F');

		bufferShotgunOwned[1] = '\0';	
		bufferChaingunOwned[1] = '\0';	
		bufferMissileOwned[1] = '\0';	
		bufferPlasmaOwned[1] = '\0';	
		bufferBfgOwned[1] = '\0';	
		bufferChainsawOwned[1] = '\0';	
		bufferSuperShotgunOwned[1] = '\0';	
		bufferAttacking[1] = '\0';	
		bufferAction[1] = '\0';	

		// TMPL_add_var add a variable to the list in the first parameter and return the list.
		// if the first param is 0, it create a TMPL_varlist and return it.
		// TMPL_add_var(list, varName1, value1, varName2, value2, ..., 0)
		variableList = TMPL_add_var(0, "playerHealth", bufferPlayerHealth, 0);
		variableList = TMPL_add_var(variableList, "armor", bufferArmor, 0);
		variableList = TMPL_add_var(variableList, "pistolAmmos", bufferClipAmmos, 0);
		variableList = TMPL_add_var(variableList, "shotgunOwned", bufferShotgunOwned, 0);
		variableList = TMPL_add_var(variableList, "shotgunAmmos", bufferShellAmmos, 0);
		variableList = TMPL_add_var(variableList, "chaingunOwned", bufferChaingunOwned, 0);
		variableList = TMPL_add_var(variableList, "chaingunAmmos", bufferClipAmmos, 0);
		variableList = TMPL_add_var(variableList, "missileOwned", bufferMissileOwned, 0);
		variableList = TMPL_add_var(variableList, "missileAmmos", bufferMissileAmmos, 0);
		variableList = TMPL_add_var(variableList, "plasmaOwned", bufferPlasmaOwned, 0);
		variableList = TMPL_add_var(variableList, "plasmaAmmos", bufferCellAmmos, 0);
		variableList = TMPL_add_var(variableList, "bfgOwned", bufferBfgOwned, 0);
		variableList = TMPL_add_var(variableList, "bfgAmmos", bufferCellAmmos, 0);
		variableList = TMPL_add_var(variableList, "chainsawOwned", bufferChainsawOwned, 0);
		variableList = TMPL_add_var(variableList, "superShotgunOwned", bufferSuperShotgunOwned, 0);
		variableList = TMPL_add_var(variableList, "superShotgunAmmos", bufferShellAmmos, 0);
		variableList = TMPL_add_var(variableList, "actualWeapon", bufferActualWeapon, 0);
		variableList = TMPL_add_var(variableList, "attacking", bufferAttacking, 0);
		variableList = TMPL_add_var(variableList, "playerX", bufferPlayerX, 0);
		variableList = TMPL_add_var(variableList, "playerY", bufferPlayerY, 0);
		variableList = TMPL_add_var(variableList, "playerZ", bufferPlayerZ, 0);
		variableList = TMPL_add_var(variableList, "attackerX", bufferAttackerX, 0);
		variableList = TMPL_add_var(variableList, "attackerY", bufferAttackerY, 0);
		variableList = TMPL_add_var(variableList, "attackerZ", bufferAttackerZ, 0);
		variableList = TMPL_add_var(variableList, "attackerHealth", bufferAttackerHealth, 0);
		variableList = TMPL_add_var(variableList, "action", bufferAction, 0);


		// TMPL_write 's purpose is to output the text in a file (in our case, the pipe)
		// TMPL_write(templateFilename, 0, 0, list, outputFile, errorsOutputFile)
		TMPL_write("template.xml", 0, 0, variableList, pipeFile, 0);
	}
}

