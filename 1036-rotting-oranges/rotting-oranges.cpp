class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<vector<int>>q;
        int cntfresh=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                    vis[i][j]=2;

                }

                if(grid[i][j]==1) cntfresh++;
            }
        }

        int cnt=0;
        int tm=0;

       static const  int dr[]={-1,0,1,0};
     static const   int dc[]={0,1,0,-1};

        while(!q.empty()){
            int size=q.size();

            while(size--){
                vector<int>temp=q.front();
                int r=temp[0];
                int c=temp[1];
                int t=temp[2];
                q.pop();
                tm=max(tm,t);

                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];

                    if(nr>=0 && nc>=0 && nr< n && nc<m &&
                    vis[nr][nc]!=2  && grid[nr][nc]==1)
                    {
                        vis[nr][nc]=2;
                        q.push({nr,nc,t+1});
                        cnt++;

                    }
                }




                
            }

        }
        
        if(cnt!=cntfresh) return -1;
        return tm;


        
    }
};