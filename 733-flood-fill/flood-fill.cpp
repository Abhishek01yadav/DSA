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

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int inicolor=image[sr][sc];
        dfs( sr,sc,ans,inicolor,color);
        return ans;
        
    }
};