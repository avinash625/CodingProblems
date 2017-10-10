/*
Problem Link:
https://leetcode.com/problems/island-perimeter/description/
*/

class Solution {
public:
    int isValid(int a , int b, int row, int col){
        if(a<0 || a>=row)
            return false;
        else if(b<0 || b>=col)
            return false;
        return true;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        int xvalues[] = {0,-1,0,1};
        int yvalues[] = {-1,0,1,0};
        int startx, starty, finalCount = 0;
        for(int iter = 0;iter<row;iter++){
            startx = iter;
            for(int iter1 = 0;iter1<col;iter1++){
                count = 0;
                starty = iter1;
               if(grid[startx][starty] == 1){
                    for(int value = 0;value<4;value++){
                        if(isValid(startx+xvalues[value],starty+yvalues[value],row,col) && grid[startx+xvalues[value]][starty+yvalues[value]] == 1){
                            count++;
                            //cout<<"It is valid at "<<startx+xvalues[value]<<" "<<starty+yvalues[value]<<endl;
                        }
                    }
                    finalCount = finalCount + (4-count);
               }
            }
        }
        return finalCount;
    }
};
