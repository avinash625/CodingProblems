class Solution {
    public int numIslands(char[][] grid) {
        boolean[][] visited = new boolean[grid.length][];
        for(int iter = 0; iter< grid.length; iter++){
            visited[iter] = new boolean[grid[0].length];
        }
        
        int numberOfIslands = 0;
        for(int row = 0; row < grid.length; row++){
            for(int col = 0; col< grid[0].length; col++){
                if(grid[row][col] == '1' && visited[row][col] == false){
                    visited[row][col] = true;
                    //System.out.println("starting island exploration at " + row + " " + col);
                    startBreadthFirstSearch(grid, visited, row, col);
                    numberOfIslands++;
                }   
            }
        }
        return numberOfIslands;
    }
    
    public void startBreadthFirstSearch(char[][] grid, boolean[][] visited, int row, int col){
        if(row < 0 || col < 0 || row > grid.length || col > grid[0].length) return ;
        else{
            int[] xValues = new int[]{0,-1,0,1};
            int[] yValues = new int[]{-1,0,1,0};
            
            for(int position = 0; position < xValues.length; position++){
                if(isValidPosition(visited, row+xValues[position] , col+yValues[position], grid)){
                    visited[row+xValues[position]][col+yValues[position]] = true;
                    startBreadthFirstSearch(grid, visited, row+xValues[position], col+yValues[position]);
                }
            }
        }
    }
    
    public boolean isValidPosition(boolean[][] visited, int row, int col, char[][] grid){
        //System.out.println("checking position for "+ row + " " + col);
        if(row < 0 || col < 0 || row >= visited.length || col >= visited[0].length || visited[row][col] == true || grid[row][col] == '0') return false;
        else return true;
    }
}