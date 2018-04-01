#include <math.h>
#include "primeslib.h"

int isPrime(int n){
	int k;
	if (n % 2 || n < 1) {
		for (k = 3; k < (int)(sqrt(n) + 1); k = k+2) {
			if (n % k == 0) {
				return 0;
			}
		}
		return 1;
	}
	return 0; 
}
