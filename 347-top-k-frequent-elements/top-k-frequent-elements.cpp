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

        sort(p.begin(),p.end(),cmp);

        vector<int>ans;

        for(int i=0;i<k;i++){
            ans.push_back(p[i].first);
        }


      


return ans;
      
        
    }
};