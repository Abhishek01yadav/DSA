class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        // vector<string>arr(n);
        // for(int ele:nums){
        //     arr.push_back(to_string(ele));

        // }
        auto mycomparator=[](int &a,int &b){
            // if(s1+s2>s2+s1) return true;
            // return false;
            string s1=to_string(a);
            string s2=to_string(b);
            return s1+s2>s2+s1;
        };
        sort(nums.begin(),nums.end(),mycomparator);
        if(nums[0]==0) return "0";
        string ans="";
        for(int &ele:nums){
            ans+=to_string(ele);
        }
        return ans;
        
    }
};