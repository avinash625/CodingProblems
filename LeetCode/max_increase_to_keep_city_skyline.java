class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] topView = new int[grid.length];
        int[] sideView = new int[grid[0].length];
        
        updateTopView(grid, topView);
        updateSideView(grid,sideView);
        
        //printArray(topView);
        //printArray(sideView);
        
        int sum = 0;
        for(int row = 0; row < grid.length; row++){
            for(int col = 0; col < grid[0].length; col++){
                if(grid[row][col] < Integer.min(topView[col], sideView[row])){
                    sum = sum + Integer.min(topView[col], sideView[row]) - grid[row][col];
                }
            }
        }
        
        return sum;
    }
    
    public void printArray(int[] arr){
        for(int iter = 0; iter< arr.length; iter++){
            System.out.println(arr[iter] + " ");
        }
    }
    
    public void updateTopView(int[][] grid, int[] topView){
        for(int col = 0; col < topView.length; col++){
            int max = grid[0][col];
            for(int row = 1; row < grid.length; row++){
                if(max < grid[row][col])
                    max = grid[row][col];
            }
            topView[col] = max;
        }
    }
    
    public void updateSideView(int[][] grid, int[] sideView){
        for(int row = 0; row< grid.length; row++){
            int max = grid[row][0];
            for(int col = 1; col < sideView.length;col++){
                if(max < grid[row][col])
                    max = grid[row][col];
            }
            sideView[row] = max;
        }
    }
}