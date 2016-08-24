//given a series 5, 25, 30, 125, 130, ....... , given n find the nth term in the series.

//solution
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//method signatures
long long int getNthTerm(int n);

//method definition
long long int getNthTerm(int n){
	long long int sum = 0;
	int currentPower = 1;
	for (; n; ){
		int bit = (n & 1);
		n = n / 2;
		sum = sum + (pow(5, currentPower)*bit);
		currentPower++;
	}
	return sum;
}

void main(void){
	int n;
	printf("enter the number\n");
	scanf("%d", &n);
	if (n < 0){
		printf("Enter a valid number\n");
		return;
	}
	else{
		long long int result = getNthTerm(n);
		printf("%lld", result);
		fflush(stdin);
		getchar();
	}
	return;
}
