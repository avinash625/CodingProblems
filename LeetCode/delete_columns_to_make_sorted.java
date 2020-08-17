class Solution {
    public int minDeletionSize(String[] A) {
        int count = 0;
        if(A.length == 0) return 0;
        for(int iter = 0; iter< A[0].length(); iter++){
            char ch = A[0].charAt(iter);
            for(int i = 1 ; i< A.length; i++){
                if(ch > A[i].charAt(iter)){
                    count++;
                    break;
                }else{
                    ch = A[i].charAt(iter);
                }
            }
        }
        return count;
    }
}