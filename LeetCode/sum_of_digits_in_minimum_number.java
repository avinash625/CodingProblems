class Solution {
    public int sumOfDigits(int[] A) {
        int minimum = getMinimum(A);
        if(getDigits(minimum)%2 == 0)
            return 1;
        return 0;
    }
    
    public int getMinimum(int[] arr){
        int minimum = arr[0];
        for(int iter = 1; iter< arr.length; iter++){
            if(arr[iter] < minimum){
                minimum = arr[iter];
            }
        }
        return minimum;
    }
    
    public int getDigits(int value){
        int sum = 0;
        while(value >0){
            sum += (value%10);
            value = value/10;
        }
        return sum;
    }
}