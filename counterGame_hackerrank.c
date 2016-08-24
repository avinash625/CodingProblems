#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	unsigned long int t = 0;
	scanf("%lu", &t);
	for (; t>0; t--){
		unsigned long long int n;
		scanf("%llu", &n);
		int answer = 1;
		while (n != 1 && n>0){
			if (n&(n - 1) == 0)
				n = n / 2;
			else
				n = n - pow(2, floor(log(n) / log(2)));
			if (answer)
				answer = 0;
			else
				answer = 1;
		}
		if (answer == 1)
			printf("Richard");
		else
			printf("Louise");
	}
	return 0;
}
