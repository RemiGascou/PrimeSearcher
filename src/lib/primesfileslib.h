#ifndef PRIMESFILESLIB_H
#define PRIMESFILESLIB_H

int primefexists(char fname[]);
int primefwrite(char fname[], int data);
int primefretrieve(char fname[]);
int primefupdate(char fname[], long int tab[], int tabsize);

#endif