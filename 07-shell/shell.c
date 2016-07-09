/*
 * shell.c
 *
 *  Created on: Jul 9, 2016
 *      Author: manageryzy
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFFER 2048


char cmd[MAX_BUFFER]={0};
char buffer[MAX_BUFFER]={0};

int main(int argc, char **argv) {
	printf("cmd$");
	while(1){
		fgets(buffer,MAX_BUFFER,stdin);
		strcat(cmd,buffer);
		if(buffer[strlen(buffer)-2]=='\\'){
			printf(" >");
			cmd[strlen(cmd)-2]=0;
		}else{
			if(strcmp(cmd,"bye\n")==0||strcmp(cmd,"exit\n")==0){
				break;
			}
			system(cmd);
			cmd[0]=0;
			printf("cmd$");
		}
	}
	return 0;
}
