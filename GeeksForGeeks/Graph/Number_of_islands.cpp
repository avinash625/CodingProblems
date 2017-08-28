bool isValid(int x, int y, int N,int M){
    if(x<0 || x>=N)
        return false;
    if(y<0 || y>=M)
        return false;
    return true;
}
void dfs(bool isVisited[MAX][MAX], int A[MAX][MAX],int N, int M,int row,int col){
    int xValue[] = {-1,-1,0,1,1,1,0,-1};
    int yValue[] = {0,1,1,1,0,-1,-1,-1};
    int newx,newy;
    for(int iter = 0;iter<8;iter++){
        newx = row+xValue[iter];
        newy = col+yValue[iter];
        if( isValid(newx,newy,N,M) && (!isVisited[newx][newy]) && (A[newx][newy]==1)){
            A[newx][newy] = 0;
            isVisited[newx][newy] = true;
            //cout<<"making unit "<<newx<<" "<<newy<<" as visited"<<endl;
            dfs(isVisited,A,N,M,newx,newy);
        }
    }
}
int findIslands(int A[MAX][MAX], int N, int M)
{
    bool isVisited[MAX][MAX];
    for(int row = 0;row<N;row++){
        for(int col = 0;col<M;col++)
            isVisited[row][col] = false;
    }
    int islands = 0;
    for(int row = 0;row<N;row++){
        for(int col = 0;col<M;col++){
            if(!isVisited[row][col] && A[row][col] == 1){
                isVisited[row][col] = true;
                //cout<<"starting a new island from "<<row<< " "<<col<<endl;
                dfs(isVisited,A,N,M,row,col);
                islands++;
            }
        }
    }
    return islands;
}
