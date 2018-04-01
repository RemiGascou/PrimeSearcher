#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "primesfileslib.h"

#define TRUE 1
#define FALSE 0

int primefexists(char fname[]) {
	if(access(fname, F_OK) != -1 ) {
   		return TRUE;
	} else {
		return FALSE;
	}
}

int primefwrite(char fname[], int data){
	if(fname != NULL) {
		FILE * pfd = fopen(fname, "r");
		fwrite(&data,sizeof(data),1,pfd);

		fclose(pfd);

		return 0;
	}
	return 1;
}

int primefretrieve(char fname[]) {

    FILE * pfd = fopen(fname, "r");
	//char buff[sizeof(long long int)];
    char * buff = malloc(100*sizeof(char));

    if (pfd != NULL) {
        fseek(pfd, 0, SEEK_SET); // make sure start from 0
        while(!feof(pfd)) {
            memset(buff, 0x00, sizeof(long long int)); // clean buffer
            fscanf(pfd, "%[^\n]\n", buff); // read file *prefer using fscanf
        }
    }
	fclose(pfd);
	return atoi(buff);
}

int primefupdate(char fname[], long int tab[], int tabsize) {
	int k;
	FILE * pfd = fopen(fname, "a");
	for (k = 0; k<tabsize;k++) {
		//fwrite(&tab[k],sizeof(tab[k]),1,pfd);
		fprintf(pfd,"%ld\n",tab[k]);
	}
	fclose(pfd);
	return 1;
}