class Solution {
    public int uniquePathsIII(int[][] grid) {
        int[][] visited =  new int[grid.length][grid[0].length];
        int startingX =0, startingY = 0;
        boolean found = false;
        int valid = 0;
        for(int row = 0;row< grid.length; row++){
            for(int col = 0; col< grid[row].length; col++){
                if(grid[row][col] == 1){
                    startingX = row;
                    startingY = col;
                    found = true;
                }
                if(grid[row][col] == 0){
                    valid++;
                }
            }
        }
        visited[startingX][startingY] = 1;
        return uniquePathsIII(grid,visited,startingX, startingY, valid,0);
    }
    
    public int uniquePathsIII(int[][] grid, int[][] visited, int currentrow, int currentCol,int validCount ,int valid){
        if(currentrow >= grid.length || currentCol >= grid[0].length || currentrow < 0 || currentCol < 0){
            return 0;
        }else{
            if((grid[currentrow][currentCol] == 2) && (validCount+1 == valid)){
                return 1;
            }else{
                int[] x = {0, -1, 0, 1};
                int[] y = {-1, 0, 1, 0};
                int count = 0;
                for(int iter = 0;iter< 4;iter++){
                    if(isValidPosition(grid,visited, currentrow+x[iter], currentCol+y[iter]) == true){
                        visited[currentrow+x[iter]][currentCol+y[iter]] = 1;
                        count += uniquePathsIII(grid,visited,currentrow+x[iter], currentCol+y[iter], validCount, valid+1);
                        visited[currentrow+x[iter]][currentCol+y[iter]] = 0;    
                    }
                    
                }
                return count;
            }
        }
    }
    
    public boolean isValidPosition(int [][] grid, int[][] visited,int currentrow, int currentcol){
        if(currentrow >= grid.length || currentrow < 0) return false;
        if(currentcol >= grid[0].length || currentcol <0) return false;
        if(grid[currentrow][currentcol] == -1) return false;
        if(visited[currentrow][currentcol] == 1) return false;
        return true;
    }
}
