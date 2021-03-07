#include "api.h"

void fill(int * vector, int size, int value){
	for(int i = 0; i < size ; i++)
		vector[i] = value;
}

// if value exists in vector return the index of value , otherwise returns -1
int find(int* vector, int size, int value){
	int i;
	for(i = 0 ; i < size && vector[i] != value; i++ );
	if(i == size) return -1;
	else return i;
}
