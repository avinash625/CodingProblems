#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int minimum(int a, int b){
	if (a>b)
		return b;
	else
		return a;
}
int getMinimumJumps(int *input, int length, int start){
	int steps = 0;
	for (int iter = start; iter < length-1; ){
		if (input[iter + 2] == 0){
			steps++;
			iter += 2;
		}
		else if (input[iter + 1] == 0){
			steps++;
			iter += 1;
		}
		else
			return -1;
	}
	return steps;
}
int main(){
	int n;
	scanf("%d", &n);
	int *c = malloc(sizeof(int)* n);
	for (int c_i = 0; c_i < n; c_i++){
		scanf("%d", &c[c_i]);
	}
	int result = getMinimumJumps(c, n, 0);
	printf("%d", result);
	fflush(stdin);
	getchar();
	return 0;
}