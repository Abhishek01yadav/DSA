class Solution {
public:
typedef long long ll;
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
       int mn,mx;
        ll ans=0;
        for(int i=0;i<n;i++){
            mn=nums[i];
            mx=nums[i];
            
            for(int j=i+1;j<n;j++){
                mn=min(mn,nums[j]);
                mx=max(mx,nums[j]);
                ll temp=mx-mn;
                ans+=temp;


            }
        }
        return ans;
        
    }
};