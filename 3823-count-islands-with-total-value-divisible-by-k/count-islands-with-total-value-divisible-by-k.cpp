class Solution {
public:
const long long  mod=1e9+7;
int m,n;
void bfs(int row,int col,vector<vector<int>>& grid, vector<vector<int>>&vis,long long  &sum){
 queue<pair<int,int>>q;
    vis[row][col]=1;
    sum+=grid[row][col];
    q.push({row,col});
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};

    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int nrow=r+dr[k];
            int ncol=c+dc[k];

            if(nrow>=0 && nrow <m && ncol>=0 && ncol <n && !vis[nrow][ncol] && grid[nrow][ncol]!=0){
                q.push({nrow,ncol});
                sum+=grid[nrow][ncol];
                vis[nrow][ncol]=1;
            }
        }


    }
}
    int countIslands(vector<vector<int>>& grid, int k) {
    
         m=grid.size();
         n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(!vis[i][j] && grid[i][j]!=0){
                    long long sum=0;
                  
                    bfs(i,j,grid,vis,sum);
                    cout<<sum;
                    if(sum % k==0) cnt++;
                }
            }
        }

    return cnt;
        
    }
};