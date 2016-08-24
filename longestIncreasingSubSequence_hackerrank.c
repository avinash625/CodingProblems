//problem statement

//solution
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>


//method signatures
int longestIncreasingSubsequence(int *input, int length);

//method definition
int longestIncreasingSubsequence(int *input, int length){
	int *lcs = (int *)malloc(sizeof(int)*length);
	for (int iter = 0; iter < length; iter++)
		lcs[iter] = 1;
	for (int i = 1; i < length; i++){
		for (int j = 0; j < i; j++){
			if (input[j] < input[i])
				lcs[i] = max(lcs[i], lcs[j] + 1);
		}
	}
	int maximum = 0;
	for (int iter = 0; iter < length;iter++)
	if (maximum < lcs[iter])
		maximum = lcs[iter];
	return maximum;
}

void main(void){
	int length = 0;
	scanf("%d", &length);
	int *input = (int *)malloc(sizeof(int)*length);
	for (int iter = 0; iter < length; iter++){
		scanf("%d", &input[iter]);
	}
	int result = longestIncreasingSubsequence(input, length);
	printf("%d", result);
	fflush(stdin);
	getchar();
}