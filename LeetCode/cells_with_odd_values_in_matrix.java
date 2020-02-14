class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        int[] row = new int[n];
        int[] col = new int[m];
        for(int iter = 0 ; iter <  indices.length; iter++){
            row[indices[iter][0]]++;
            col[indices[iter][1]]++;
        }
        
        int count = 0;
        for(int rowi = 0; rowi < n; rowi++){
            for(int coli = 0; coli < m; coli++){
                if((row[rowi]+col[coli]) %2 == 1)
                    count++;
            }
        }
        return count;
    }
}