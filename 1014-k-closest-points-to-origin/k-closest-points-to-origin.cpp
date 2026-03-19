class Solution {
public:
typedef pair<int,vector<int>>pi;
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
priority_queue<pi>pq;
vector<vector<int>>ans;
int n=arr.size();
for(auto v:arr){
    int dist=v[0]*v[0]+v[1]*v[1];
    pq.push({dist,v});
    if(pq.size()>k) pq.pop();
}
while(!pq.empty()){
    ans.push_back(pq.top().second);
    pq.pop();

}
   return ans;     
    }
};