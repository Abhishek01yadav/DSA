class Solution {
public:
typedef long long ll;


vector<int>getPGE(vector<int>&nums,int n){
    vector<int>result(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            result[i]=-1;

        }

        else{
            while(!st.empty() &&  nums[st.top()] <=nums[i])
            st.pop();

            result[i]=st.empty()?-1:st.top();

            
        }
        st.push(i);

    }

    return result;
}

vector<int>getNGE(vector<int>&nums,int n){
    vector<int>result(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            result[i]=n;

        }

        else{
            while(!st.empty() &&  nums[st.top()] <nums[i])
            st.pop();

            result[i]=st.empty()?n:st.top();

            
        }
        st.push(i);

    }

    return result;
}

vector<int>getPSE(vector<int>&nums,int n){
    vector<int>result(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            result[i]=-1;

        }

        else{
            while(!st.empty() &&  nums[st.top()]>=nums[i])
            st.pop();

            result[i]=st.empty()?-1:st.top();

            
        }
        st.push(i);

    }

    return result;
}

vector<int>getNSE(vector<int>&nums,int n){
    vector<int>result(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            result[i]=n;

        }

        else{
            while(!st.empty() && nums[st.top()]>nums[i])
            st.pop();

            result[i]=st.empty()?n:st.top();

            
        }
        st.push(i);

    }

    return result;
}

ll sumofMAX(vector<int>& nums,int n){
    vector<int>nge=getNGE(nums,n);
    vector<int>pge=getPGE(nums,n);
    ll totalsum=0;

    for(int i=0;i<n;i++){
        int ls=i-pge[i];
        int rs=nge[i]-i;

    ll totalways=ls*rs;
    ll sum=totalways*nums[i];

    totalsum+=sum;

    }
    return totalsum;
}


ll sumofMIN(vector<int>& nums,int n){
    vector<int>nse=getNSE(nums,n);
    vector<int>pse=getPSE(nums,n);
    ll totalsum=0;

    for(int i=0;i<n;i++){
        int ls=i-pse[i];
        int rs=nse[i]-i;

    ll totalways=ls*rs;
    ll sum=totalways*nums[i];

    totalsum+=sum;

    }


return totalsum;

}
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
     ll ans1=   sumofMIN(nums,n);
     ll ans2=   sumofMAX(nums,n);
     cout<<ans1<<endl;
     cout<<ans2<<endl;
     return ans2-ans1;
        
    }
};