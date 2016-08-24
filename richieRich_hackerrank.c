//solution
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>


//method signatures
int getLargestPalindrome(int n, int k, char *inputArray);
bool palindrome(char *inputArray);



//method definitions
bool palindrome(char *inputArray){
	int n = strlen(inputArray);
	for (int i = 0; i < n / 2; i++){
		if (inputArray[i] != inputArray[n - i - 1])
			return false;
	}
	return true;
}
int getLargestPalindrome(int n, int k, char *inputArray){
	if (k >= n && !palindrome(inputArray)){
		int i;
		for (i = 0; i < n; i++){
			inputArray[i] = '9';
		}
		inputArray[i] = '\0';
	}
	else if (k != 0 && palindrome(inputArray)){
		for (int i = 0; k != 0 && k != 1; k -= 2,i++){
			if (inputArray[i] != '9')
				inputArray[i] = inputArray[n - i - 1] = '9';
			else{
				k = k + 2;
			}
		}
		if (k == 1)
			inputArray[(n / 2) ] = '9';
	}
	else
	{
		/*int *characterMap = (int *)malloc(sizeof(int)*10);
		memset(characterMap, 0, sizeof(characterMap));
		for (int i = 0; i < n; i++){
			characterMap[inputArray[i]] = characterMap[inputArray[i]] + 1;
		}*/
		int minimumChangesRequired = 0;
		int changesRequired = 0;
		for (int i = 0; i < n / 2; i++){
			if (inputArray[i] != inputArray[n - 1 - i]){
				minimumChangesRequired += 1;
				if (inputArray[i] == '9' || inputArray[n-1-i]=='9')
					changesRequired += 1;
				else
					changesRequired += 2;
			}
		}
		if (minimumChangesRequired>k)
			return -1;
		else if (k == minimumChangesRequired){
			for (int i = 0; i < n / 2; i++){
				if (inputArray[i] < inputArray[n - 1 - i])
					inputArray[i] = inputArray[n - 1 - i];
				else
					inputArray[n - i - 1] = inputArray[i];
			}
		}
		else if (k == changesRequired){
			for (int i = 0; i < n / 2; i++){
				if (inputArray[i] != inputArray[n - 1 - i])
					inputArray[i] = inputArray[n - 1 - i] = '9';
			}
		}
	}
	
	return atoi(inputArray);
}


void main(void){
	int n, k;
	scanf("%d%d", &n, &k);
	char *inputArray = (char *)malloc(sizeof(char)*(n + 1));
	scanf("%s", inputArray);
	int result = getLargestPalindrome(n, k, inputArray);
	printf("%d", result);
	fflush(stdin);
	getchar();
}