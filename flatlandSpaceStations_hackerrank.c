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
	else return a;
}
int getLargestDistanceToCover(int *input, int n, int m){
	int previous = 0;
	int mIter = 0;
	int *distance = (int *)malloc(sizeof(int)*n);
	for (int iter = 0; iter< n; iter++){
		if (iter == input[mIter]){
			distance[iter] = 0;
			previous = 0;
			mIter++;
		}
		else {
			previous = previous + 1;
			distance[iter] = previous;
		}
	}
	previous = 0;
	bool firstFound = false;
	for (int iter = n - 1; iter>0; iter--){
		if (!firstFound && distance[iter] == 0){
			previous = 1;
			firstFound = true;
			continue;
		}
		else if (distance[iter] == 0){
			distance[iter] = minimum(distance[iter], previous);
			previous = 1;
		}
		else{
			distance[iter] = minimum(distance[iter], previous );
			previous = previous + 1;
		}
	}
	int largestDistance = 0;
	for (int iter = 0; iter < n; iter++){
		if (distance[iter]>largestDistance)
			largestDistance = distance[iter];
	}
	return largestDistance;
}
int main(){
	int n;
	int m;
	scanf("%d %d", &n, &m);
	int *c = malloc(sizeof(int)* m);
	for (int c_i = 0; c_i < m; c_i++){
		scanf("%d", &c[c_i]);
	}
	int result = getLargestDistanceToCover(c, n, m);
	printf("%d", result);
	fflush(stdin);
	getchar();
	return 0;
}
