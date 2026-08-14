class Solution {
public:

 static bool  cmp (const pair<int,int>&ele1,const pair<int,int>&ele2){
    return ele1.second >ele2.second;
}

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int &ele :nums){
            mp[ele]++;
        }

        vector<pair<int,int>>p(mp.begin(),mp.end());
        priority_queue<pair<int,int>>pq;

        for(auto &x:mp){
            pq.push({x.second,x.first});
        }

        vector<int>ans;

        for(int i=0;i<k;i++)
        {
            int x=pq.top().second;
            ans.push_back(x);

            pq.pop();
        }



return ans;
      
        
    }
};