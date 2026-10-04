class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        if(k>=m+n-2) return m+n-2;
       // vector<vector<vector<int>>>vis(n,vector<vector<int>(m,vector<int>(n*m+1,0)));
       int vis[40][40][1601];
       memset(vis,0,sizeof(vis));
      int dr[]={-1,0,1,0};
      int dc[]={0,1,0,-1};
        queue<vector<int>>q;
        q.push({0,0,k});
        vis[0][0][k]=1;

int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                vector<int>temp=q.front();
                int row=temp[0];
                int col=temp[1];
                int obs=temp[2];
                q.pop();

              if(row==n-1 && col==m-1){
                return steps;

              }

              for(int d=0;d<4;d++){
                int nrow=row+dr[d];
                int ncol=col+dc[d];

                if(nrow<0 || nrow >=n || ncol<0 || ncol>=m) continue;

                else if(!vis[nrow][ncol][obs] && grid[nrow][ncol]==0){
                    vis[nrow][ncol][obs]=1;
                    q.push({nrow,ncol,obs});
                }

                else if( obs >0 && !vis[nrow][ncol][obs-1] && grid[nrow][ncol]==1 ){
                    vis[nrow][ncol][obs-1]=1;
                    q.push({nrow,ncol,obs-1});


                }

              }


            }
            steps++;
        }



        
     
return -1;
        

        
    }
};