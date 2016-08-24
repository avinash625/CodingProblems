#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//methods
int getLongestCommonSubsequenceLength(char *input1,char *input2){
	int **mapping = (int **)malloc(sizeof(int *)*(strlen(input1) + 1));
	for (int iter = 0; iter < strlen(input1) + 1; iter++){
		mapping[iter] = (int *)malloc(sizeof(int)*(strlen(input2) + 1));
		memset(mapping[iter], 0, (sizeof(int)*strlen(input2) + 1));
	}
	for (int i = 1; i <= strlen(input2); i++){
		for (int j = 1; j <= strlen(input1); j++){
			if (input1[j - 1] == input2[i - 1])
				mapping[i][j] = mapping[i - 1][j - 1] + 1;
			else
				mapping[i][j] = max(mapping[i - 1][j], mapping[i][j - 1]);
		}
	}
	return mapping[strlen(input2)][strlen(input1)];
}

void main(void){
	char input1[128],input2[128];
	printf("enter the first string\n");
	scanf("%s", input1);
	printf("enter the second string\n");
	scanf("%s", input2);
	int result = getLongestCommonSubsequenceLength(input1, input2);
	printf("the length of the longest common subsequence is %d", result);
	fflush(stdin);
	getchar();
}