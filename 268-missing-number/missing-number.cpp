class Solution {
public:
    int missingNumber(vector<int>& arr) {
         int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]!=i){
                return i;
            }
        }
        
return n;
        
    }
};