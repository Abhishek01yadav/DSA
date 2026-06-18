class Solution {
    private:
     bool dfscheck(int node, vector<int>&vis , vector<int>&pathvis, vector<int>&check,vector<vector<int>> &graph){
        vis[node]=1;
       pathvis[node]=1;
       check[node]=0;
        
        for(auto adjnode:graph[node]){
            // if the node is not previously visited
            if(!vis[adjnode]){
                if(dfscheck(adjnode,vis,pathvis,check,graph)==true) return true;
                
            }
            
            // if the adjnode is visited on the same path 
            else if(pathvis[adjnode]){
                return true;
            }
          
        }
        pathvis[node]=0;
        check[node]=1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
int V=graph.size();
         vector<int>safenode;
        
       vector<int>vis(V,0) ;
        vector<int>pathvis(V,0) ;
         vector<int>check(V,0) ;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfscheck(i,vis,pathvis,check,graph);
            }
            
            
        }
        for(int i=0;i<V;i++){
            if(check[i]==1) safenode.push_back(i);
        }
     return safenode;
    
        
    }
};