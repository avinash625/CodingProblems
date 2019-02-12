class Solution {
    
    public boolean exist(char[][] board, String word) {
        int[][] visited = new int[board.length][board[0].length];
        char[] c = word.toCharArray();
        for(int row = 0; row < board.length; row++){
            for(int col = 0 ; col < board[0].length; col++){
                if(board[row][col] == c[0]){
                    visited[row][col]= 1;
                    boolean result = existUtil(board,visited,row,col,word.length(),1,word);
                    if(result == true) return  true;
                    visited[row][col] = 0;
                }
            }
        }
        return false;
    }

    public boolean existUtil(char[][] board, int [][] visited, int currentrow, int currentcol, int validLength, int currentLength,String word){
        if(validLength == currentLength){
            return true;
        }else{
            int[] x = {0,-1,0,1};
            int[] y = {-1,0,1,0};
            for(int iter = 0; iter< 4; iter++){
                if(isValidPosition(board, visited, currentrow+x[iter] , currentcol+y[iter], validLength, currentLength, word)){
                    visited[currentrow+x[iter]][currentcol+y[iter]] = 1;
                    boolean result = existUtil(board,visited, currentrow+x[iter] , currentcol+y[iter], validLength, currentLength+1, word);
                    if(result == true) return true;
                    visited[currentrow+x[iter]][currentcol+y[iter]] = 0;
                }
            }
            return false;
        }
    }

    public boolean isValidPosition(char[][] board, int [][] visited, int currentrow, int currentcol, int validLength, int currentLength, String word){
        if(currentrow<0 || currentrow >= board.length) return false;
        if(currentcol<0 || currentcol >= board[0].length) return false;
        if(visited[currentrow][currentcol] == 1) return false;
        if(word.toCharArray()[currentLength] != board[currentrow][currentcol]) return false;
        return true;
    }

}