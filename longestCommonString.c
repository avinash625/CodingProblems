//solution
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

//method signatures
void longestCommonSubstring(char *input1,char *input2,char *result){
	int len1 = strlen(input1);
	int len2 = strlen(input2);
	int **mapping = (int **)malloc(sizeof(int*)*(strlen(input1)+1));
	for (int iter = 0; iter <= strlen(input1)+1; iter++){
		mapping[iter] = (int *)malloc(sizeof(int)*(strlen(input1)+1));
		memset(mapping[iter], 0, strlen(input1)*sizeof(int));
	}
	int maximumx = 0, maximumy = 0;
	for (int i = 1; i <= strlen(input2); i++){
		for (int j = 1; j <= strlen(input1); j++){
			if (input2[i - 1] == input1[j - 1]){
				mapping[i][j] = mapping[i - 1][j - 1] + 1;
			}
			else
				mapping[i][j] = 0;
			if (mapping[maximumx][maximumy] < mapping[i][j]){
				maximumx = i;
				maximumy = j;
			}
		}
	}
	printf("%d%d", maximumx, maximumy);
	result[mapping[maximumx][maximumy]+1] = '\0';
	for (int iter = mapping[maximumx][maximumy]; iter>=0; iter--, maximumx--, maximumy--){
		result[iter] = input2[maximumx];
	}
	return;
}

void main(void){
	char input1[128], input2[128];
	printf("enter the string 1\n");
	scanf("%s", input1);
	printf("enter the string 2\n");
	scanf("%s", input2);
	char result[256];
	longestCommonSubstring(input1, input2, result);
	printf("the longest common substring is %s\n", result);
	fflush(stdin);
	getchar();
}