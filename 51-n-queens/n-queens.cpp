class Solution {
public:

bool isSafe(int row,int col,vector<string>&board){
    int n= board.size();
    int r=row;
    int c=col;

    // check for left upper diagonal
    while(row >=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }
    row=r;
    col=c;
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }

    row=r;
    col=c;
    while(row < n && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    
    return true;
}
void solve(int row,int col,vector<string>&board, vector<vector<string>>&ans){
    int n=board.size();
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,col,board)){
            board[row][col]='Q';
            solve(row,col+1,board,ans);
            board[row][col]='.';

        }
    }

      
        
    

}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }

        solve(0,0,board,ans);

        

         
        

       return ans; 
        
    }
};