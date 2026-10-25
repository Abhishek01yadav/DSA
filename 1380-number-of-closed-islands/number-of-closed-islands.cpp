class Solution {
public:
int n,m;
void bfs(int row,int col,vector<vector<int>>& grid, vector<vector<int>>&vis){
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    static const int dr[]={-1,0,1,0};
     static const int dc[]={0,1,0,-1};



    while(!q.empty()){
        auto[r,c]=q.front();
        q.pop();

        // traverse all its neighbours
        for(int k=0;k<4;k++){
            int nrow=r+dr[k];
            int ncol=c+dc[k];


            if(nrow>=0 && nrow<n && ncol >=0 && ncol <m && grid[nrow][ncol]==0 && !vis[nrow][ncol]){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }
        }

    }



}
    int closedIsland(vector<vector<int>>& grid) {
         n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool border=(i==0 || j==0 || i==n-1 || j==m-1);
                if(border && grid[i][j]==0 && !vis[i][j]){
                    bfs(i,j,grid,vis);
                }

            }
        }

       int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=0 && j!=0 && i!=n-1 && j!=m-1  ){
                    if(grid[i][j]==0 && !vis[i][j]){
                        cnt++;
                        bfs(i,j,grid,vis);
                       
                      
                        
                    }
                }
            }
        }

       
      

    return cnt;
        
    }
};