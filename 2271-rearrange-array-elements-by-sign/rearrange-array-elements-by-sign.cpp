class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        vector<int>numpos,numneg;
        for(auto ele:nums){
            if(ele>0) numpos.push_back(ele);
            if(ele<0) numneg.push_back(ele);
        }
        
        for(int i=0;i<numpos.size();i++){
           ans[2*i]=numpos[i];
           ans[2*i+1]=numneg[i];
        }

     
     
        return ans;
    }
};