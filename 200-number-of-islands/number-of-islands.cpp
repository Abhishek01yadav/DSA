class Solution {
public:
void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis,int dr[],int dc[]){
    int n=grid.size();
    int m=grid[0].size();
    vis[row][col]=1;
    //traverse all neighbours.
    for(int k=0;k<4;k++){
        int nrow=row+dr[k];
        int ncol=col+dc[k];

        if(nrow>=0 && nrow<n && ncol >=0 && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol] =='1'){

            dfs(nrow,ncol,grid,vis,dr,dc);
        }

    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[]={-1,0,+1,0};
        int dc[]={0,1,0,-1};
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]  && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid,vis,dr,dc);
                }
            }
        }

        
return cnt;
        
    }
};