/*Given a string, find the longest palindrome that can be constructed by removing or shuffling characters from the string.Return only one palindrome if there are multiple palindrome strings of longest length.

Examples:

Input : abc
Output : a OR b OR c

	 Input : aabbcc
		 Output : abccba OR baccab OR cbaabc OR
				  any other palindromic string of length 6.

			  Input : abbaccd
				  Output : abcdcba OR ...

					   Input : aba
						   Output : aba*/

//solution
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>


//method signatures
char * getLargestPalindrome(char *inputArray);

//method definition
char *getLargestPalindrome(char *inputArray,char *result){
	int length = strlen(inputArray);
	int writingIndex = 0;
	int mapping[256] = { 0 };
	bool isMidSet = false;
	char mid;
	/*char *result = (char *)malloc(sizeof(char)*length);*/
	memset(result, 0, length+1);
	for (int iter = 0; inputArray[iter]; iter++){
		mapping[inputArray[iter]]++;
	}
	for (int i = 256; i > 0; i--){
		if ((mapping[i] % 2 == 1 && !isMidSet)){
			mid = i;
			isMidSet = true;
		}
		else{
			for (int j = mapping[i] / 2; j > 0; j--, writingIndex++){
				result[writingIndex] = i;
			}
		}
	}

	if (isMidSet){
		result[writingIndex] = mid;
		writingIndex++;
		for (int j = writingIndex-2; j >= 0; j--,writingIndex++)
			result[writingIndex] = result[j];	
	}
	else{
		for (int j = writingIndex-1, k = 0; j >= 0; j--, writingIndex++,k++)
			result[writingIndex] = result[j];
	}
}

void main(void){
	char input[32] = "amulya mithra";
	char *result = (char *)malloc(sizeof(char)*strlen(input));
	getLargestPalindrome(input, result);
	printf("the palindrome constructed is %s", result);
	getch();
}