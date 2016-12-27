#include<stdio.h>
#include<iostream>
#include"methods.h"//custom header file

using namespace std;

void pair_with_sum_k_util(int *values, int n){
	int sum;
	cin >> sum;
	if (pair_with_sum_k(values, n, sum)){
		cout << "True" << endl;
	}
	else{
		cout << "Fale" << endl;
	}
}

void tuple_with_sum_k_util(int *values, int n){
	int sum;
	cin >> sum;
	if (tuple_with_sum_k(values, n, sum)){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
}

void number_repeated_odd_number_of_times_util(int *values, int n){
	int result = number_repeated_odd_number_of_times(values, n);
	printf("The number repeated odd number of times is %d", result);
}

void main(void){
	int n;
	cin >> n;
	int *values = (int *)malloc(sizeof(int)*n);
	for (int iter = 0; iter < n; iter++){
		scanf("%d", &values[iter]);
	}


	//all the util function calls
	//pair_with_sum_k_util(values, n);
	//tuple_with_sum_k_util(values, n);
	//number_repeated_odd_number_of_times_util(values, n);
	
}