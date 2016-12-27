#include<stdlib.h>
#include"methods.h"//custom header file

bool tuple_with_sum_k(int *values, int n, int sum){
	int tuple;
	int currentSum;
	for (int iter = 0; iter < n; iter++){
		if (pair_with_sum_k(values + iter+1, n - iter, sum - values[iter])){
			return true;
		}
	}
	return false;
}