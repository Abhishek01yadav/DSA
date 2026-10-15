class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefmax(n);
         vector<int>suffmax(n);
         prefmax[0]=height[0];


         for(int i=1;i<n;i++){
            prefmax[i]=max(prefmax[i-1],height[i]);

         }
         suffmax[n-1]=height[n-1];

          for(int i=n-2;i>=0;i--){
            suffmax[i]=max(suffmax[i+1],height[i]);

         }
         int ans=0;

         for(int i=0;i<n;i++){
            int leftmax=prefmax[i];
            int rightmax=suffmax[i];
            if(height[i]<leftmax && height[i]<rightmax)
            {
            ans+=min(leftmax,rightmax)-height[i];
            }

         }
         return ans;

    }
};