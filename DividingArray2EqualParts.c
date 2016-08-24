//given an integer array , find if the array can be divided into two equal parts of same sum  by deleting just a sinle element
/*  */

//solution
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>

//method signatures
int getIndexToDivide(int *input, int length);

//method definitions
int getIndexToDivide(int *input, int *length){
	int sum = 0;
	int leftSum = 0;
	for (int iter = 0; iter < length; iter++)
		sum += input[iter];
	for (int iter = 0; iter < length; iter++){
		if (sum - leftSum - input[iter]  == leftSum)
			return iter;
		else
			leftSum += input[iter];
	}
	return -1;
}


void main(void){
	int array[] = { 6, -2, 3, 2, 3 };
	int length = 5;
	int result = getIndexToDivide(array, length);
	if (result == -1){
		printf("No such point exist\n");
	}
	else{
		printf("The index to be removed is %d", result);
	}
	getchar();
}