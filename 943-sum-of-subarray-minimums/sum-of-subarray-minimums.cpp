class Solution {
public:
typedef long long ll;
const int mod=1e9+7;
vector<int>getNSL(vector<int>&arr,int n){
    stack<int>st;
    vector<int>nsl(n);

    for(int i=0;i<n;i++){

        if(st.empty())  nsl[i]=-1;
        else{
            while(!st.empty() && arr[st.top()] >=arr[i])  st.pop();

            nsl[i]=st.empty()?-1:st.top();

            
        }
        st.push(i);
    }
return nsl;
    
}


vector<int>getNSR(vector<int>&arr,int n){
    stack<int>st;
    vector<int>nsr(n);

    for(int i=n-1;i>=0;i--){

        if(st.empty())  nsr[i]=n;
        else{
            while(!st.empty() && arr[st.top()] >arr[i])  st.pop();

            nsr[i]=st.empty()?n:st.top();

          
        }
        st.push(i);
    }
return nsr;
    
}
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nsl=getNSL(arr,n);
        vector<int>nsr=getNSR(arr,n);

       ll totalsum=0;
       

        for(int i=0;i<n;i++){
            ll ls=i-nsl[i];
            ll rs=nsr[i]-i;

            ll totalways=ls*rs;//is element ko minimum leke kiten subarray bnenge.
            ll sum=totalways*arr[i];

            totalsum=(totalsum+sum)%mod;

            
        }
        return totalsum;
        
    }
};