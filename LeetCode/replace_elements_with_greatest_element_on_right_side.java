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