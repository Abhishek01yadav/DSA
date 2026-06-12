// class Solution {
// public:
// void dfs(int node,vector<int> adjls[],int vis[]){
//   vis [node]=1;

//   // sare nodes k neighbours ko call lga do.
//   for(auto it:adjls[node]){
//       if(!vis[it]){
//           dfs(it,adjls,vis);
//       }
//   }
    
// }
//     int findCircleNum(vector<vector<int>>& adj) {
//         int V=adj.size();
//         vector<int>adjls[V];
//         // converting adjacency matri int o adj list
//         for(int i=0;i<V;i++){
//             for(int j=0;j<V;j++){
//                 if(adj[i][j]==1 && i!=j){
//                     adjls[i].push_back(j);
                     

//                 }
//             }
//         }

//         int vis[V]={0};
//         int cnt=0;
//         for(int i=0;i<V;i++){
//             if(!vis[i]){
//                 cnt++;
//                 dfs(i,adjls,vis);
//             }
//         }

//        return cnt; 
//     }
// };
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjls, vector<int>& vis) {
        vis[node] = 1;

        for (auto it : adjls[node]) {
            if (!vis[it]) {
                dfs(it, adjls, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();

        vector<vector<int>> adjls(V);

        // Converting adjacency matrix into adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                }
            }
        }

        vector<int> vis(V, 0);

        int cnt = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adjls, vis);
            }
        }

        return cnt;
    }
};