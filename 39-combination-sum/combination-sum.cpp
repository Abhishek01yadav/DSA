class Solution {
public:

void f(int idx,vector<int>&candidates, vector<int> &temp,int target,vector<vector<int>> &result){
if(target==0) {
    result.push_back(temp);
    return;
    
}
    if(idx==0){
        if(target % candidates[0] ==0){
            int count=target/candidates[0];
            for(int i=1;i<=count;i++){
            temp.push_back(candidates[0]);
            }
           result.push_back(temp); 
           

          for(int i=0;i<count;i++){
            temp.pop_back();
          }
           
           return;
           
        }
        return;
       
        
    

    }

    //pick 
   
    
        int currval=candidates[idx];

        if(target-currval >= 0){

     temp.push_back(currval);
    f(idx,candidates,temp,target-currval,result);

        
    
    temp.pop_back();
        }
    
    

    f(idx-1,candidates,temp,target,result);
    
    

    

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        int n=candidates.size();
        f(n-1,candidates,temp,target,result);
        return result;

        
    }
};