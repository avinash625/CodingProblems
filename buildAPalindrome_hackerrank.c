#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//mehtod signatures
void buildLargestPalindrome(char *input1, char *input2, char *result);

//mehtod definitions
void printMappingArray(int **mapping, int row, int column){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			printf("%d\t", mapping[i][j]);
		}
		printf("\n");
	}
}

void  buildLargestPalindrome(char *input1, char *input2, char *result){
	strrev(input2);
	int **mapping = (int *)malloc(sizeof(int *)*(strlen(input2) + 1));
	for (int i = 0; i < strlen(input2) + 1; i++)
		mapping[i] = (int *)malloc(sizeof(int)*(strlen(input1) + 1));
	for (int i = 0; i < strlen(input2) + 1; i++){
		if (i == 0){
			for (int j = 0; j < strlen(input1) + 1; j++){
				mapping[i][j] = 0;
			}
		}
		else
			mapping[i][0] = 0;
	}
	for (int i = 1; i < strlen(input2) + 1; i++){
		for (int j = 1; j < strlen(input1) + 1; j++){
			if (input1[j - 1] == input2[i-1])
				mapping[i][j] = mapping[i - 1][j - 1] + 1;
			else
				mapping[i][j] = 0;
		}
	}
	int highestx = 0, highesty = 0;
	for (int i = 1; i < strlen(input2) + 1; i++){
		for (int j = 1; j < strlen(input1) + 1; j++){
			if (mapping[i][j] > mapping[highestx][highesty]){
				highestx = i;
				highesty = j;
			}
		}
	}
	//printf("highestx:%d\nhighesty:%d\n", highestx, highesty);
	//printf("%d\n", mapping[highestx][highesty]);
	char lastChar1, lastChar2;
	lastChar2 = input2[highestx];
	lastChar1 = input1[highesty];
	if (lastChar2 && lastChar1 > lastChar2)
		lastChar1 = lastChar2;
	if (lastChar1 == '\0')
		lastChar1 = lastChar2;
	//printf("the last character is %c\n", lastChar2);

	int nullIndex = mapping[highestx][highesty] ;
	if (nullIndex == 0){
		result[0] = '\0';
		return;
	}
	for (; mapping[highestx][highesty]; highestx--, highesty--){
		result[mapping[highestx][highesty]-1] = input2[highestx-1];
	}
	
	//lastChar1 = input1[]

	result[nullIndex] = lastChar1;
	nullIndex = nullIndex + 1;
	for (int iter = nullIndex - 2; iter >= 0; iter--,nullIndex++)
		result[nullIndex] = result[iter];
	result[nullIndex] = '\0';
	printMappingArray(mapping, strlen(input2)+1, strlen(input1)+1);
}

int main(void){
	char input1[128], input2[128];
	char result[256];
	printf("enter the two strings \n");
	scanf("%s%s", input1, input2);
	buildLargestPalindrome(input1, input2, result);
	if (strlen(result))
		printf("the largest palindrome is \"%s\"", result);
	else
		printf("-1");
	fflush(stdin);
	getchar();
}