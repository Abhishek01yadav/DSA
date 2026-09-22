class Solution {
public:
vector<vector<int>>ans;
void f(int idx,vector<int>&candidates,vector<int>&temp,int target){
    int n=candidates.size();

    
//base case 
        if(target==0){
            ans.push_back(temp);
        
        return;
        }

    

    //pick 
    for(int i=idx;i<n;i++){
        int val=candidates[i];
        if(val > target) break;
        if(i>idx && candidates[i] ==candidates[i-1]) continue;

        temp.push_back(val);
        f(i+1,candidates,temp,target-val);
        temp.pop_back();


    }

    


}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;

        sort(candidates.begin(),candidates.end());
        f(0,candidates,temp,target);
        

        return ans;
        
    }
};