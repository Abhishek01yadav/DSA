class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<vector<int>>> adj(n);

         for(auto edge:flights){
            adj[edge[0]].push_back({edge[1],edge[2]});
         }


         vector<int>dist(n,1e9);

         dist[src]=0;
         queue<pair<int,pair<int,int>>>q;
         q.push({0,{src,0}});

         while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int  dis=it.second.second;
            if(stops>k) continue;

            for(auto iter:adj[node]){
                int adjnode=iter[0];
                int edgewt=iter[1];
                if( dis+edgewt <dist[adjnode] && stops<=k){

                    dist[adjnode]=dis+edgewt;
                    q.push({stops+1,{adjnode,dis+edgewt}});

                }


            }






         }



         if(dist[dst]==1e9) return -1;
         return dist[dst];




        
    }
};