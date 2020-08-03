class Solution {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        int iter1 =0, iter2 = 0, iter3 = 0;
        for(; iter1 < arr1.length && iter2 < arr2.length && iter3 < arr3.length; ){
            if(arr1[iter1] == arr2[iter2] && arr2[iter2] == arr3[iter3]){
                result.add(arr1[iter1]);
                iter1++;
                iter2++;
                iter3++;
            }else if(arr1[iter1] > arr2[iter2] && arr1[iter1] > arr3[iter3]){
                iter2++;
                iter3++;
            }else if(arr2[iter2] > arr1[iter1] && arr2[iter2] > arr3[iter3]){
                iter1++;
                iter3++;
            }else if(arr3[iter3] > arr2[iter2] && arr3[iter3] > arr1[iter1]){
                iter1++;
                iter2++;
            }else if(arr3[iter3] < arr2[iter2] && arr3[iter3] < arr1[iter1]){
                iter3++;
            }else if(arr2[iter2] < arr3[iter3] && arr2[iter2] < arr1[iter1]){
                iter2++;
            }else if(arr1[iter1] < arr2[iter2] && arr1[iter1] < arr3[iter3]){
                iter1++;
            }
        }
        return result;
    }
}