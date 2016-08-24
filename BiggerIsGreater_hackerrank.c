//given a string 'S', generate the next bigger word i.e generate the word which is lexicographically bigger than that .
//if multiple words exist , try to print the smallest  one among them.
/* for example let us consider the given word is "dkhc" then the next bigger word is hcdk*/


//solution
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


//mthod signatures
char * getNextBiggerWord(char *input);
int getSmallest(char *input, int start);
void swap(char *input, int pos1, int pos2);
void sortStringFromIndex(char *input, int start);


//method definitions
char *getNextBiggerWord(char *input){
	int iter;
	int length = strlen(input);
	for (iter = length - 1; iter >= 0; iter--){
		if (input[iter] < input[iter + 1])
			break;
	}
	if (iter == -1)
		return NULL;
	else{
		int smallest = getSmallest(input, iter);
		swap(input, iter, smallest);
		sortStringFromIndex(input, iter+1);
		return input;
	}
}
int getSmallest(char *input, int start){
	int smallest = start+1;
	char conditionChar = input[start];
	for (start = start + 1; input[start]; start++){
		if (input[start] > conditionChar && input[start] < input[smallest])
			smallest = start;
	}
	return smallest;
}
void swap(char *input, int pos1, int pos2){
	char temp = input[pos1];
	input[pos1] = input[pos2];
	input[pos2] = temp;
}
void sortStringFromIndex(char *input, int start){
	for (int iter = start; input[iter]; iter++){
		for (int iter2 = iter + 1; input[iter2]; iter2++){
			if (input[iter2] < input[iter])
				swap(input, iter2, iter);
		}
	}
}
void main(void){
	char input[32] = "";
	printf("enter the word \n");
	scanf("%s", input);
	char *result = getNextBiggerWord(input);
	if (!result)
		printf("The Given word is the lexicographically largest one ");
	else
		printf("the word is %s", result);
	fflush(stdin);
	getchar();
}