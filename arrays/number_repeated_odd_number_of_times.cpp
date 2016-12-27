#include<stdlib.h>
#include"methods.h"//custom header file 

int number_repeated_odd_number_of_times(int *values, int n){
	int result = values[0];
	for (int iter = 1; iter < n; iter++){
		result = result^values[iter];
	}
	return result;
}