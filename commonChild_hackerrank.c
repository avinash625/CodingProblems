/*given two strings , find the logest common subsequence among them , 

the subsequence could be a null string also,

for example consider the two strings : Harry , sally , you need to print the longest common subsequence length
i.e len(ay)  = 2;
*/
 
//solution
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

//method signatures
int getLongestCommonSubsequence(char *string1, char *string2);

//method definitions
int getLongestCommonSubsequence(char *string1, char *string2){
	if (!string1 || !string2){
		return 0;
	}
	else{
		int **characterMap = (int **)malloc(sizeof(int *)*strlen(string1)+1);
		for (int iter = 0; iter <= strlen(string2); iter++){
			characterMap[iter] = (int *)malloc(sizeof(int)*strlen(string2)+1);
		}
		for (int iter = 0; iter < strlen(string1); iter++){
			for (int iter2 = 0; iter2 < strlen(string2); iter2++){
				if (iter == 0 || iter2 == 0)
					characterMap[iter][iter2] = 0;
			}
		}
		for (int iter1 = 1; iter1 < strlen(string1) + 1; iter1++){
			for (int iter2 = 1; iter2 <  strlen(string2) + 1; iter2++){
				if (string1[iter1-1] == string2[iter2-1]){
					characterMap[iter1][iter2] = characterMap[iter1-1][iter2-1] + 1;
				}
				else{
					characterMap[iter1][iter2] = max(characterMap[iter1-1][iter2], characterMap[iter1][iter2-1]);
				}
			}
		}
		return characterMap[strlen(string1)][strlen(string2)];
	}
}
void main(void){
	char string1[32];
	char string2[32];
	scanf("%s%s", string1, string2);
	int result = getLongestCommonSubsequence(string1, string2);
	printf("%d", result);
	fflush(stdin);
	getchar();
}