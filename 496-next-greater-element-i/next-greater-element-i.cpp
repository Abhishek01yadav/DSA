class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            cout<<"run"<<endl;
            for(int j=0;j<m;j++){
                if(nums2[j]==nums1[i])
                {
                    for(int k=j;k<m;k++)
                    {
                        if(nums2[k]>nums1[i]){
                            ans.push_back(nums2[k]);
                            break;
                        }

                        if(k==m-1) ans.push_back(-1);
                        
                       
                    }
                    
                }
            }
        }

        
return ans;
        
    }
};