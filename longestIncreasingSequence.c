#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int longestIncreasingSequence(int *input, int length){
	int *mapping = (int *)malloc(sizeof(int)*length);
	int maximum = 0;
	mapping[0] = 1;
	for (int i = 1; i <= length; i++){
		mapping[i] = 1;
		for (int j = 0; j < i; j++){
			if (input[j] < input[i]){
				mapping[i] = max(mapping[i], mapping[j] + 1);
			}
		}
		if (mapping[i] > maximum)
			maximum = mapping[i];
	}
	return maximum;
}

void main(void){
	int length;
	printf("enter the no. of elements\n");
	scanf("%d", &length);
	printf("enter the elements\n");
	int *input = (int *)malloc(sizeof(int)*length);
	for (int iter = 0; iter < length; iter++)
		scanf("%d", &input[iter]);
	int result = longestIncreasingSequence(input, length);
	printf("the length of the longest increasing suquence is %d", result);
	fflush(stdin);
	getchar();
}