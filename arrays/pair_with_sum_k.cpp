#include<stdbool.h>
#include<stdlib.h>
#include"methods.h"//custom header file

//comparator function for the qsort.
int comporator(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}


//returns true if a pair with the required sum is present
bool pair_with_sum_k(int *values, int n, int k /*pair should be equal to this sum */){

	qsort(values, n, sizeof(int), comporator);

	int currentValue = 0;
	for (int iter = 0, iter1 = n - 1; iter < iter1;){
		currentValue = values[iter] + values[iter1];
		if (currentValue == k){
			return true;
		}
		else if (currentValue > k){
			iter1--;
		}
		else if (currentValue < k){
			iter++;
		}
	}
	return false;
}