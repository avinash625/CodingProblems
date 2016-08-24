/*Given three stacks of different heights , find the maximum height to which all the three stacks can be 
reduced by removing the top most element of the stack*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

//method signatures
int getLargestPossibleHeight(int *inputStack1, int *inputStack2, int *inputStack3, int len1, int len2, int len3);
void getRightSum(int *inputArray, int length);

//method definitions
int getLargestPossibleHeight(int *inputStack1, int *inputStack2, int *inputStack3, int len1, int len2, int len3){
	int iterator1 = 0,iterator2 = 0 , iterator3 = 0;
	//calculating the right cumulative sum 
	getRightSum(inputStack1, len1);
	getRightSum(inputStack2, len2);
	getRightSum(inputStack3, len3);
	while (!(inputStack1[iterator1] == inputStack2[iterator2] && inputStack2[iterator2] == inputStack3[iterator3])){
		if (inputStack1[iterator1] >= inputStack2[iterator2] && inputStack1[iterator1] >= inputStack3[iterator3])
			iterator1++;
		else if (inputStack2[iterator2] >= inputStack1[iterator1] && inputStack2[iterator2] >= inputStack3[iterator3])
			iterator2++;
		else if (inputStack3[iterator3] >= inputStack1[iterator1] && inputStack3[iterator3] >= inputStack2[iterator2])
			iterator3++;
		else if (iterator1 == len1 || iterator2 == len2 || iterator3 == len3)
			return 0;
	}
	return inputStack1[iterator1];
}

void getRightSum(int *inputArray, int length){
	int iterator = length - 2;
	for (; iterator >= 0; iterator--)
		inputArray[iterator] += inputArray[iterator + 1];
}

void main(void){
	int inputStack1[20] = { 15, 10, 5 };
	int inputStack2[20] = { 12, 8, 4 };
	int inputStack3[20] = { 9, 6, 3 };
	int len1 = 3, len2 = 3, len3 = 3;
	int result = 0;
	result = getLargestPossibleHeight(inputStack1, inputStack2, inputStack3, len1, len2, len3);
	printf("The possible Maximum height is %d", result);
	getchar();
}