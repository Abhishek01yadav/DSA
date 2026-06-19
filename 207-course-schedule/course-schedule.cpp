class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int   V =  numCourses;
      vector<vector<int>>adj(V);
      vector<int>toposort;
      
      for(auto edge: prerequisites){
        adj[edge[0]].push_back(edge[1]);
      }

      vector<int>indegree(V,0);

      // calculate indegree array
      for(int i=0;i<V;i++){
        for(auto adjnode:adj[i]){
            indegree[adjnode]++;
        }
      }
      

       queue<int>q;

       for(int i=0;i<V;i++)
       {
        if(indegree[i]==0) q.push(i);
       }

       while(!q.empty()){
        int node=q.front();
        q.pop();
        toposort.push_back(node);
        for(auto adjnode: adj[node]){
            indegree[adjnode]--;
            if(indegree[adjnode]==0) q.push(adjnode);
        }
        
       }


    
return toposort.size()==V;







        
    }
};