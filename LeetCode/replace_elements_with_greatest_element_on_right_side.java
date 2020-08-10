class Solution {
    public int[] replaceElements(int[] arr) {
        Stack<Integer> st = new Stack<Integer>();
        st.push(arr[arr.length-1]);
        arr[arr.length-1]=-1;
        int currentValue;
        for(int iter = arr.length-2; iter >= 0; iter--){
            currentValue = arr[iter];
            arr[iter] = st.peek();
            if(currentValue > st.peek()){
                st.push(currentValue);
            }
        }
        return arr;
    }
}

class Solution {
    public int[] replaceElements(int[] arr) {
        int greatest = -1;
        int[] result = new int[arr.length];
        for(int iter = arr.length-1; iter>= 0; iter--){
            if(greatest == -1){
                greatest = arr[iter];
                result[iter] = -1;
            }else{
                result[iter] = greatest;
                if(arr[iter] > greatest){
                    greatest = arr[iter];
                }
            }
        }
        return result;
    }
}