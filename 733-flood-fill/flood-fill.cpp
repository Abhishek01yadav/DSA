class Solution {
public:
void dfs(int row,int col,vector<vector<int>>& ans,int inicolor,int newcolor){
    ans[row][col]=newcolor;
   static const int dr[]={-1,0,1,0};
    static const  int dc[]={0,1,0,-1};
    // visiting all neighbours.
    for(int k=0;k<4;k++){
        int nrow=row+dr[k];
        int ncol=col+dc[k];

        if(nrow >=0 && ncol>=0 && nrow < ans.size() && ncol <ans[0].size() && 
        ans[nrow][ncol]==inicolor && ans[nrow][ncol]!=newcolor){
            dfs(nrow,ncol,ans,inicolor,newcolor);
        }
    }


}
void bfs(int row,int col, vector<vector<int>>&ans,int inicolor,int newcolor){
    ans[row][col]=newcolor;
    queue<vector<int>>q;
    q.push({row,col});

    static const int dr[]={-1,0,1,0};
    static const int dc[]={0,1,0,-1};


    while(!q.empty()){
        vector<int>temp=q.front();
        int r=temp[0];
        int c=temp[1];
        
        q.pop();
//finding valid neighbours
        for(int k=0;k<4;k++){
            int nrow=r+dr[k];
            int ncol=c+dc[k];

            if(nrow>=0 && ncol>=0 && nrow< ans.size() && ncol<ans[0].size() && ans[nrow][ncol]==inicolor 
            && ans[nrow][ncol]!=newcolor)
            {
                ans[nrow][ncol]=newcolor;
                q.push({nrow,ncol});
            }

        }




    }


}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int inicolor=image[sr][sc];
        bfs( sr,sc,ans,inicolor,color);
        return ans;
        
    }
};