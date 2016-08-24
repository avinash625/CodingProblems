/*Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Examples:

Input : arr[] = { 2, 0, 2 }
Output: 2
	Structure is like below
	| |
	| _ |
	We can trap 2 units of water in the middle gap.

Input : arr[] = { 3, 0, 0, 2, 0, 4 }
	Output: 10
		Structure is like below
		|
		| |
		| | |
		| __ | _ |
		We can trap "3*2 units" of water between 3 an 2,
		"1 unit" on top of bar 2 and "3 units" between 2
		and 4.  See below diagram also.

	Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
	   Output : 6
				|
				| || |
				_ | _ || _ || || ||
				Trap "1 unit" between first 1 and 2, "4 units" between
				first 2 and 3 and "1 unit" between second last 1 and last 2*/


//solution
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//method signatures
int getRainWaterCount(int *depthArray,int length);


//method definitions
int getRainWaterCount(int *depthArray,int length){
	int lowest = 0;
	int finalWaterCount = 0;
	int iter,highest=0;
	int *leftBars, *rightBars;
	leftBars = (int *)malloc(sizeof(int)*length);
	rightBars = (int *)malloc(sizeof(int)*length);
	leftBars[0] = depthArray[0];
	for (iter = 1; iter < length; iter++){
		leftBars[iter] = max(leftBars[iter - 1], depthArray[iter]);
	}
	rightBars[length - 1] = depthArray[length - 1];
	for (iter = length - 2; iter >= 0; iter--){
		rightBars[iter] = max(rightBars[iter + 1], depthArray[iter]);
	}
	for (iter = 0; iter < length; iter++){
		if(leftBars[iter] != 0 && rightBars[iter] != 0)
		{
			finalWaterCount += min(leftBars[iter], rightBars[iter]) - depthArray[iter];
		}
	}
	return finalWaterCount;
}

void main(void){
	int depthArray[10] = { 3,3,3,3,3,3 };
	int length = 6;
	int result = getRainWaterCount(depthArray, length);
	printf("the rainwater collected is %d", result);
	getchar();
}