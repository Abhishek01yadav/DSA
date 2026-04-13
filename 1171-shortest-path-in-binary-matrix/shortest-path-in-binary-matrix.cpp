class Solution {
private:
    int bfs(vector<vector<int>>& grid, int row, int col, int R, int C){
        grid[row][col] = 1;
        queue<tuple<int,int,int>> q;
        q.push(make_tuple(0,0,1));

        int minpath = INT_MAX;
        vector<vector<int>> diff = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

        while(!q.empty()){
            auto val = q.front();
            q.pop();
            int currentrow = get<0>(val), currentcol = get<1>(val), currentpathlength = get<2>(val);
            for(int di = 0 ; di < 8 ; di++){
                int adjR = currentrow + diff[di][0];
                int adjC = currentcol + diff[di][1];
                if(adjR>=0 && adjR<R && adjC>=0 && adjC<C){
                    if(adjR == R-1 && adjC == C-1){
                        minpath = min(minpath,currentpathlength+1);
                    }
                    else if(grid[adjR][adjC] == 0){
                        grid[adjR][adjC] = 1;
                        q.push(make_tuple(adjR,adjC,currentpathlength+1));
                    }
                }
            }
        }
        return minpath;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        if(grid[0][0]!=0 || grid[R-1][C-1]!=0) return -1;
        if(R==1 && C==1) return 1;
        int ans = bfs(grid,0,0,R,C);
        if(ans!=INT_MAX) return ans;
        else return -1;
    }
};