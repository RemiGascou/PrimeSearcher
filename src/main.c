#include <stdio.h>
#include <string.h>
#include <time.h>
#include "./lib/primeslib.h"
#include "./lib/primesfileslib.h"
#include "./lib/lib_bash_colors.h"

#define MAX_WORKERS 4

//int[] workers[MAX_WORKERS];

void * worker(char workername[], char fname[], int checkpoint) {

	long clk_tck = CLOCKS_PER_SEC;

	printf("\n["ANSI_COLOR_LIGHTGREEN"Boot"ANSI_COLOR_RESET"] Starting Worker %s.\n",workername);
	int buffersize = 1;
	long int buffer[1] = {0}; //calloc();
	int ptabindex = 0;
	int clear = 0;
	int numberofprimesfound = 0;
	double tic = (double) clock();
	//double starttime = tic;
	double logtime = 1;

	while (checkpoint <= 1000000) {
	//while (1) {
		if (ptabindex == buffersize) {primefupdate(fname,buffer,buffersize);ptabindex = 0;clear++;}
		checkpoint++;
		if (isPrime(checkpoint)) {
			if (((clock()-tic)/clk_tck) >= logtime && numberofprimesfound != 0) {
				printf("[LOG "ANSI_COLOR_LIGHTBLUE"%s"ANSI_COLOR_RESET"] %d primes found. In %f seconds.\n",workername,numberofprimesfound,((clock()-tic)/clk_tck));
				//printf(" | clock %ld, tic %f\n",clock(),tic);
				numberofprimesfound = 0;
				tic = clock();
			}
			buffer[ptabindex] = checkpoint;
			ptabindex++;
			numberofprimesfound++;
		}
	}
	return 0;
}

int main (int argc, char *argv[]) {
	int last = 1;
	char * primefilename = "primeslist.primes";

	printf(ANSI_COLOR_LIGHTYELLOW"============= Prime Searcher v1.0.1 =============\n"ANSI_COLOR_RESET);
	printf("Prime file exixsting ? ");

	if (primefexists(primefilename)) {
		printf(ANSI_COLOR_LIGHTGREEN"Yes.\n"ANSI_COLOR_RESET);
		printf("  | Retrieving last checkpoint ...\n");
		last = primefretrieve(primefilename);
		printf("  | Last checkpoint is : %d\n",last);
	}
	else {
		printf(ANSI_COLOR_LIGHTRED"No.\n"ANSI_COLOR_RESET);
		printf("  | Creating %s ... ",primefilename);
		FILE * fd = fopen(primefilename, "w+");
		fclose(fd);
		printf("Done.\n");
	}

	worker("wk1",primefilename,last);
	return 0;
}
