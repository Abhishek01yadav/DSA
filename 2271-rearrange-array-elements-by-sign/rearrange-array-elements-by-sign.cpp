class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<int>numpos(n/2),numneg(n/2);
        for(auto ele:nums){
            if(ele>0) numpos.push_back(ele);
            if(ele<0) numneg.push_back(ele);
        }
        for(int i=0;i<numpos.size();i++){
            ans.push_back(numpos[i]);
            ans.push_back(numneg[i]);
        }

       ans.erase(remove(ans.begin(), ans.end(), 0), ans.end());
     
        return ans;
    }
};