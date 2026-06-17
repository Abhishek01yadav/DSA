class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
          vector<int>color(n,-1);
          for(int  i=0;i<n;i++){
            if(color[i]!=-1) continue;
          
        queue<int>q;
        q.push(i);
        color[i]=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto adjnode: graph[node]){
                // if it has not given color yet
                if(color[adjnode]==-1){
                    color[adjnode]=!color[node];
                    q.push(adjnode);
                }
                //
                else if(color[adjnode]==color[node]){
                    return false;
                }

            }
        }
          }
return true;
        
    }
};