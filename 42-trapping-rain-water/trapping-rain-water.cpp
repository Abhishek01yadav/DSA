class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
    //     int  l=0;
    //     int  r=n-1;
    //    int  lmax=0;
    //    int  rmax=0;
    //    int ans=0;
    //     while(l<r){
    //       lmax=  max(lmax, height[l]);
    //         rmax=max(rmax, height[r]);
    //         if(lmax<rmax)
    //         {
    //             ans+=lmax- height[l];
    //             l++;
    //         }
    //         else {
    //             ans+=rmax- height[r];
    //             r--;
    //         }
    //     }
    //     return ans;

    vector<int>left(n,0),right(n,0);
    left[0]=height[0];
    right[n-1]=height[n-1];
    for(int i=1;i<n;i++){
        left[i]=max(height[i],left[i-1]);
    }

 for(int i=n-2;i>=0;i--){
        right[i]=max(height[i],right[i+1]);
    }
  
   int ans = 0;
    for(int i = 0; i < n; i++){
        ans += min(left[i], right[i]) - height[i];
    }

return ans;

    }
};