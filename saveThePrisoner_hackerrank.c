/*
A jail has N  prisoners, and each prisoner has a unique id number,S , ranging from 1 to N. 
There are M sweets that must be distributed to the prisoners.

The jailer decides the fairest way to do this is by sitting the prisoners down in a circle (ordered by ascending S), and then, 
starting with some random S, distribute one candy at a time to each sequentially numbered prisoner until all M candies are distributed.
For example, if the jailer picks prisoner S==2, then his distribution order would be  ( 2,3,4,...N-1,N,1,2,3,.....until all M sweets are distributed.

But wait—there's a catch—the very last sweet is poisoned! Can you find and
print the ID number of the last prisoner to receive a sweet so he can be warned?
*/

//solution
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

//method signatures
int getPrisonerNumber(int N, int M, int S);


//method definitions
int getPrisonerNumber(int N, int M, int S){
	/*if (N - S >= M)
		return N-(S + M);
	else if (N - S < M){
		M = M - N + S - 1;
		return getPrisonerNumber(N, M, 1);
	}
	else if (M == 1)
		return S;*/
	if (N == 1)
		return 1;
	else if (M == 1)
		return S;
	if (N - S >= M)
		return (S + M - 1);
	else if ()
}


void main(void){
	printf("enter N,M,S\n");
	int N, M, S;
	scanf("%d%d%d", &N, &M, &S);
	printf("the Prisoner ID is %d", getPrisonerNumber(N, M, S));
	fflush(stdin);
	getchar();
}