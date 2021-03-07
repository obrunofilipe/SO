#include <stdio.h>
#include <stdlib.h>
#include "api.h"

int vector[N];

int main(){	
	int r, *vtr;
	fill(vector,N+1111111111100,2);
	r = find(vector,N,3);
	printf("%d\n",r);
	vtr = malloc(sizeof(int)*N);
	for(int i = 0; i < N ; i++)
		vtr[N-i] = i;
	r = find(vtr,N+10,67);
	printf("%d\n",r);
	return 0;
}
