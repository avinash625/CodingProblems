class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int[][] visited = new int[grid.length][grid[0].length];
        
        int maximumArea = 0;
        
        for(int row = 0;row<grid.length; row++){
            for(int col = 0; col< grid[0].length;col++){
                if(grid[row][col] == 1 && visited[row][col] == 0){
                    visited[row][col] = 1;
                    int area = (maxAreaOfIslandUtil(grid,visited,row,col)+1);
                    if(area > maximumArea)
                        maximumArea = area;
                }
            }
        }
        return maximumArea;
    }
    
    public int maxAreaOfIslandUtil(int[][] grid, int[][] visited, int currentrow, int currentcol){
        if(grid[currentrow][currentcol] == 0 ){
            return 0;
        }else{
            int[] x = {0,-1,0,1};
            int[] y = {-1,0,1,0};
            int area = 0;
            for(int iter =0; iter< 4; iter++){
                if(isValidPosition(grid,visited, currentrow+x[iter] , currentcol+y[iter])){
                    visited[currentrow+x[iter]][currentcol+y[iter]] = 1;
                    area += (maxAreaOfIslandUtil(grid,visited, currentrow+x[iter], currentcol+y[iter])+1);
                }
            }
            return area;
        }
    }
    
    public boolean isValidPosition(int[][] grid, int[][] visited, int currentrow, int currentcol){
        if(currentrow < 0 || currentrow >= grid.length) return false;
        if(currentcol < 0 || currentcol >= grid[0].length) return false;
        if(visited[currentrow][currentcol] == 1) return false;
        if(grid[currentrow][currentcol] == 0) return false;
        return true;
    }
}