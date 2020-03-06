class Solution {
    public boolean judgeCircle(String moves) {
        int row = 0, col = 0;
        
        for(char ch : moves.toCharArray()){
            if(ch == 'U'){
                row++;
            }else if(ch == 'D'){
                row--;
            }else if(ch == 'L'){
                col--;
            }else if(ch == 'R'){
                col++;
            }
        }
        if( row == 0 && col == 0) return true;
        return false;
    }
}