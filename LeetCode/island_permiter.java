class Solution {
    public int islandPerimeter(int[][] grid) {
        int total = 0;
        for(int row = 0; row< grid.length; row++){
            for(int col = 0; col< grid[0].length; col++){
                if(grid[row][col] == 1)
                    total += calculatePermiter(row, col, grid.length, grid[0].length, grid);
            }
        }
        return total;
    }

    public int calculatePermiter(int row, int col, int r, int c, int[][] grid){
        int[] x = new int[]{-1,0,1,0};
        int[] y = new int[]{0,1,0,-1};
        int validPoints = 0;
        for(int iter = 0; iter< 4; iter++){
            validPoints += isValidPoint(row+x[iter] , col+y[iter] , r,c,grid);
        }
        return validPoints;
    }

    public int isValidPoint(int row, int col, int r, int c, int[][] grid){
        if(row < 0 || row >= r|| col < 0 || col >=c){
            return 1;
        }
        if(grid[row][col] == 0)
            return 1;
        return 0;
    }
}