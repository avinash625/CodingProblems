/* given a string , it has to be reduced to the most reduced form 
for example the strng is aabccdcc , then it has to return bd i.e it has to delete the characters that are 
present adjacent to each other , if the final reduced string doesn't have any characters pring "Empty String" */

//solution
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<stdbool.h>

//method signatures
char *getSuperReducedString(char *input);
bool isSuperReducedString(char *input);

//method definitions
char *getSuperReducedString(char *input){
	if (!input)
		return NULL;
	else{
		while (!isSuperReducedString(input)){
			int writingIndex = 0;
			bool deleting = false;
			for (int readingIndex = 1; readingIndex < strlen(input); readingIndex++){
				if (input[readingIndex-1] == input[readingIndex ] && deleting == false){
					//set the writingIndex and delete the two characters
					writingIndex = readingIndex-1;
					deleting = true; 
				}
				else if (input[readingIndex-1] == input[readingIndex ] && deleting == true){
					continue;
				}
				else if (deleting == true){
					input[writingIndex] = input[readingIndex-1];
					writingIndex++;
				}
			}
			/*input[writingIndex] = '\0';*/
		}
	}
}
bool  isSuperReducedString(char *input){
	char previous = input[0];
	for (int iter = 1; iter < strlen(input); iter++){
		if (input[iter] == previous)
			return false;
		previous = input[iter];
	}
	return true;
}

void main(void){
	char input[32] = "aabccdcc";
	char *result = getSuperReducedString(input);
	if (!result){
		printf("Empty String");
	}
	else
		printf("%s", result);
}

