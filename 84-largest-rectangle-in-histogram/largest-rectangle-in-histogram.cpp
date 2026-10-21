class Solution {
public:
vector<int>getNSE(vector<int>&heights,int n){
    vector<int>result(n);
    stack<int>st;

    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            result[i]=n;
        }
        else{
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            result[i]=st.empty()?n:st.top();


        }
        st.push(i);
    }

    return result;

}

vector<int>getPSE(vector<int>&heights,int n){
    vector<int>result(n);
    stack<int>st;

    for(int i=0;i<n;i++){
        if(st.empty()){
            result[i]=-1;
        }
        else{
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }

            result[i]=st.empty()?-1:st.top();


        }
        st.push(i);
    }

    return result;

}
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse=getNSE(heights,n);
         vector<int>pse=getPSE(heights,n);

         int mx=0;
         for(int i=0;i<n;i++){
            int val=heights[i]*(nse[i]-pse[i]-1);
            mx=max(mx,val);
         }
        
return mx;
        
    } 
    
};