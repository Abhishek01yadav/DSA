class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>temp;
        if(k>n) k=k%n;
        
        for(int i=n-k;i<n;i++){
            temp.push_back(arr[i]);
        }
        
         for(int i=n-1;i>=k;i--){
            arr[i]=arr[i-k];
        }
        
        //int j=0;
        
        for(int i=0;i<k;i++){
            arr[i]=temp[i];
           // j++;
        }
        
    }
};