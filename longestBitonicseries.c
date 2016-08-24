#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//method signatures
int getLongestBitonicSubsequenceLength(int *input, int length);

//mthod definitions
int getLongestBitonicSubsequenceLength(int *input, int length){
	int *leftlcs = (int *)malloc(sizeof(int)*length);
	int *rightlcs = (int *)malloc(sizeof(int)*length);
	/*for (int iter = 0; iter < length; iter++)
		leftlcs[iter] = 1;
	for (int iter = 0; iter < length; iter++)
		rightlcs[iter] = 1;*/
	int maximum = 0;
	leftlcs[0] = 1;
	rightlcs[length - 1] = 1;
	for (int i = 1; i < length; i++){
		leftlcs[i] = 1;
		for (int j = 0; j < i; j++){
			if (input[j] < input[i])
				leftlcs[i] = max(leftlcs[i], leftlcs[j] + 1);
		}
	}
	for (int i = length - 2; i >= 0; i--){
		rightlcs[i] = 1;
		for (int j = length - 1; j>i; j--){
			if (input[j] < input[i])
				rightlcs[i] = max(rightlcs[i], rightlcs[j] + 1);
		}
	}
	for (int iter = 0; iter < length; iter++)
		leftlcs[iter] = leftlcs[iter] + rightlcs[iter];
	for (int iter = 0; iter < length;iter++)
	if (maximum < leftlcs[iter])
		maximum = leftlcs[iter];
	return maximum-1;
}


void main(void){
	int length;
	scanf("%d", &length);
	int *input = (int *)malloc(sizeof(int)*length);
	for (int i = 0; i < length; i++){
		scanf("%d", &input[i]);
	}
	int result = getLongestBitonicSubsequenceLength(input, length);
	printf("%d", result);
	fflush(stdin);
	getchar();
}